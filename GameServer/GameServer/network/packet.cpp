////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#include "packet.h"

PACKET::PACKET(SOCKET sock, CHARACTER* me, DATABASE* mysql, FILE* fg, int* pingtime)
{
	this->socket = sock;
	this->me = me;
	this->sql = mysql;
	this->fg = fg;
	this->pingtime = pingtime;
	isconndected = true;
	buf_use_packed = 0;
	size_new_packet = 0;
	offset = 0;
	onepacketsend = false;
}

PACKET::~PACKET()
{

}

void PACKET::IsOnePacket(bool set)
{
	if (set)
	{
		onepacketsend = true;
		onepacket_step = 0;
		memset(onepacket, 0, PACKET_LEN);
	}
	else
	{
		onepacketsend = false;

		/*/// DEBUG
		char tmp[2];
		tmp[1] = 0;
		log::Debug(fg, "S->C: ");
		for (int i = 4; i < onepacket_step; i++)
		{
			if ((uint8)onepacket[i] > 0x20 && (uint8)onepacket[i] <= 'z')
			{
				tmp[0] = (uint8)onepacket[i];
				log::Notify(fg, tmp);
			}
			else
			{
				log::Notify(fg, ".");
			}
		}
		log::Notify(fg, "\n");
		log::Debug(fg, "S->C: ");
		for (int i = 4; i < onepacket_step; i++)
		{
			log::Notify(fg, "%02x", (uint8)onepacket[i]);
		}
		log::Notify(fg, "\n");
		/// !DEBUG*/


		int s = send(socket, onepacket, onepacket_step, NULL);
		int nError = WSAGetLastError();
		if (nError != WSAEWOULDBLOCK && nError != 0)
		{
			Disconnect();
			return;
		}
	}
}

void PACKET::Disconnect()
{
	me->ingame = false;
	isconndected = false;
//	shutdown(socket, NULL);
//	closesocket(socket);
	socket = NULL;
}

void PACKET::CreateBufForSend()
{
	memset(packet_snd, 0, PACKET_LEN);
	offset_snd = 0;
}

void PACKET::PackCreate()
{
}

void PACKET::drop()
{
	packet_len = NULL;
}

//====================================================================================
// ≈сли в одном потоке было больше одного пакета, то обрабатываем
//
bool PACKET::NextPacket()
{
	offset = old_offset + old_packet_len;
	if (offset >= PACKET_LEN)
	{
		lg::Error(fg, "PCK: buffer OEF.\n", packet_len, real_packet_size);
		Disconnect();
		return false;
	}

	old_offset = offset;

	real_packet_size = readUW();
	old_packet_len = real_packet_size;
	if (real_packet_size == 0)
		return false;

	opcode = readUW();
	int cryptflag = readB();
	int cryptflag2 = readB();

	if (real_packet_size < 6)
	{
		lg::Error(fg, "PCKHandler: recv packet len: %d, in packet: %d\n", packet_len, real_packet_size);
		for (int i = 0; i < packet_len; i++)
			lg::Notify(fg, "%02x", (uint8)packet_buf[i]);

		lg::Notify(fg, "\n");
		return false;
	}

	packet_len = real_packet_size - 6;
	if (cryptflag == 1 || cryptflag == 2)
	{
		int step_xor_key = 0;
		char xor_key[] = { 0xcb, 0x1e, 0xbd, 0x4c, 0xbf, 0x8f, 0xb9, 0x4a };
		for (int i = 0; i < packet_len; i++)
		{
			buf_use_packed[i + offset] ^= xor_key[step_xor_key];
			++step_xor_key;
			if (step_xor_key == sizeof(xor_key))
				step_xor_key = 0;
		}
	}
	return true;
}

//====================================================================================
// —читываем переданные клиентом данные
//
bool PACKET::PackRecv() 
{
	memset(packet_buf, 0, PACKET_LEN-1);

	if ((packet_len = recv(socket, packet_buf, PACKET_LEN, 0)) == (uint16)SOCKET_ERROR)
		return false;

	if (packet_len == 0)
	{
		Disconnect();
		return false;
	}
		
	int nError = WSAGetLastError();
	if (nError != WSAEWOULDBLOCK && nError != 0)
	{
		Disconnect();
		return false;
	}

	offset = 0;
	old_offset = 0;
	buf_use_packed = packet_buf;

	real_packet_size = readUW();

	old_packet_len = real_packet_size;
	opcode = readUW();
	uint8 cryptflag = readB();
	uint8 crypt = readB();

	if (real_packet_size < 6)
	{
		lg::Error(fg, "PCKHandler: recv packet len: %d, in packet: %d\n", packet_len, real_packet_size);
		for (int i = 0; i < packet_len; i++)
		{
			lg::Notify(fg, "%02x", (uint8)packet_buf[i]);
		}
		lg::Notify(fg, "\n");
		return false;
	}

	packet_len = real_packet_size - offset;

	if (cryptflag == 1 || cryptflag == 2)
	{
		int step_xor_key = 0;
		char xor_key[] = { 0xcb, 0x1e, 0xbd, 0x4c, 0xbf, 0x8f, 0xb9, 0x4a };
		for (int i = 0; i < packet_len; i++)
		{
			buf_use_packed[i + offset] ^= xor_key[step_xor_key];
			++step_xor_key;
			if (step_xor_key == sizeof(xor_key))
				step_xor_key = 0;
		}
	}

	return true;
}

bool PACKET::PackSend(uint16 op)
{
	char pack[PACKET_LEN + 6];
	memcpy(pack + 6, packet_snd, offset_snd);

	uint16 pack_len = offset_snd + 6;
	memcpy(pack, &pack_len, 2);
	memcpy(pack + 2, &op, 2);
	memset(pack + 4, 0, 2);
	
	if (false)//onepacketsend)
	{
		memcpy(onepacket + onepacket_step, pack, pack_len);
		onepacket_step += pack_len;
	}
	else
	{
		/*/// DEBUG
		char tmp[2];
		tmp[1] = 0;
		lg::Debug(fg, "S->C: ");
		for (int i = 4; i < pack_len; i++)
		{
			if ((uint8)pack[i] > 0x20 && (uint8)pack[i] <= 'z')
			{
				tmp[0] = (uint8)pack[i];
				lg::Notify(fg, tmp);
			}
			else
			{
				lg::Notify(fg, ".");
			}
		}
		lg::Notify(fg, "\n");
		lg::Debug(fg, "S->C: ");
		for (int i = 4; i < pack_len; i++)
		{
			lg::Notify(fg, "%02x", (uint8)pack[i]);
		}
		lg::Notify(fg, "\n");
		/// !DEBUG*/

		int s = send(socket, pack, pack_len, NULL);
		int nError = WSAGetLastError();
		if (nError != WSAEWOULDBLOCK && nError != 0)
		{
			Disconnect();
			return false;
		}
	}
	return true;
}

//====================================================================================
// Get pointer in packet
//
char* PACKET::GetPacketPointer()
{
	return buf_use_packed + offset;
}