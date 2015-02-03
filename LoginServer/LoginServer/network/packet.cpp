////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#include "packet.h"

PACKET::PACKET(THREAD_STRUCT* sockstruct)
{
	this->sockstruct = sockstruct;
	this->sockstruct->send_serverlist = false;
	isconnected = true;
	buf_use_packed = 0;
	size_new_packet = 0;
	offset = 0;
	fg = sockstruct->fg;
}

PACKET::~PACKET()
{

}

void PACKET::Disconnect()
{
	closesocket(sockstruct->socket);
	sockstruct->socket = NULL;
	isconnected = false;
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

bool PACKET::PackRecv() 
{
	if ((packet_len = recv(sockstruct->socket, packet_buf, PACKET_LEN, 0)) == SOCKET_ERROR)
		return false;

	if (packet_len == 0)
	{
		Disconnect();
		return false;
	}

	int nError = WSAGetLastError();
	if (nError != WSAEWOULDBLOCK && nError != 0)
	{
		log::Error(fg, "PCKHandler: Recv packet error: %d \n", nError);
		Disconnect();
		return false;
	}

	offset = 0;
	buf_use_packed = packet_buf;

	real_packet_size = readUW();
	opcode = readUW();
	int cryptflag1 = readUB();
	int cryptflag2 = readUB();
	packet_len = real_packet_size - offset;

	char key[] = { 0xcb, 0x1e, 0xbd, 0x4c, 0xbf, 0x8f, 0xb9, 0x4a };
	int step_key = 0;
	if (cryptflag1 == 2)
	{
		for (int i = 0; i < packet_len; i++)
		{
			buf_use_packed[i + offset] ^= key[step_key];
			++step_key;
			if (step_key == sizeof(key))
				step_key = 0;
		}
	}

	return true;
}

bool PACKET::PackSend(uint16 op)
{
	int16 null = 0;
	char pack[PACKET_LEN + 6];
	memcpy(pack + 6, packet_snd, offset_snd);

	int pack_len = offset_snd + 6;
	memcpy(pack, &pack_len, 2);
	memcpy(pack + 2, &op, 2);
	memcpy(pack + 4, &null, 2);
	send(sockstruct->socket, pack, pack_len, NULL);

	/*/// DEBUG
	char tmp[2];
	tmp[1] = 0;
	log::Debug(fg, "S->C: [len:%d] [op:%02x]", pack_len, op);
	for (int i = 6; i < pack_len; i++)
	{
	if ((uint8)pack[i] > 0x20 && (uint8)pack[i] <= 'z')
	{
	tmp[0] = (uint8)pack[i];
	log::Notify(fg, tmp);
	}
	else
	{
	log::Notify(fg, ".");
	}
	}
	log::Notify(fg, "\n");
	log::Debug(fg, "S->C: ");
	for (int i = 6; i < pack_len; i++)
	{
	log::Notify(fg, "%02x", (uint8)pack[i]);
	}
	log::Notify(fg, "\n");
	/// !DEBUG*/
	return true;
}
//////////////////////////////////////////////////////////////////////////
// Возвращает указател?на буфе?пакета учитыв? смещение
//////////////////////////////////////////////////////////////////////////
char* PACKET::GetPacketPointer()
{
	return buf_use_packed + offset;
}