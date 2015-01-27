////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#include "packet.h"

PACKET::PACKET(THREAD_STRUCT* sockstruct, int max_characters)
{
	this->sockstruct = sockstruct;
	this->sql = (DATABASE*)sockstruct->mysql;
	this->max_characters = max_characters;
	isconndecred = true;
	buf_use_packed = 0;
	size_new_packet = 0;
	offset = 0;
	fg = sockstruct->fg;
}

PACKET::~PACKET()
{
	sockstruct = NULL;
}

void PACKET::Disconnect()
{
	closesocket(sockstruct->socket);
	sockstruct->socket = NULL;
	isconndecred = false;
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
// Получаем пакет от клиента
//
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
		Disconnect();
		return false;
	}

	offset = 0;
	buf_use_packed = packet_buf;
	real_packet_size = readUW();
	opcode = readUW();
	cryptflag = readUB();
	int8 cryptflag2 = readUB();
	packet_len = real_packet_size - offset;

	char key[] = { 0xc1, 0xa1, 0xb2, 0xc4, 0x4b, 0x3f, 0x1b, 0x41 };
	int step_key = 0;
	if (cryptflag == 2)
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


//	return false;
}

//====================================================================================
// Отвечает за отправление пакета клиенту
//
bool PACKET::PackSend(uint16 op)
{
	int16 cryptflag = 0;
	char pack[PACKET_LEN + 6];
	memcpy(pack + 6, packet_snd, offset_snd);

	uint16 pack_len = offset_snd + 6;
	memcpy(pack, &pack_len, 2);
	memcpy(pack + 2, &op, 2);
	memcpy(pack + 4, &cryptflag, 2);
	send(sockstruct->socket, pack, pack_len, NULL);

	return true;
}

//====================================================================================
// Возвращает указатель на буфер учитывая смещение по нему
//
char* PACKET::GetPacketPointer()
{
	return buf_use_packed + offset;
}