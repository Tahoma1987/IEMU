////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _PACKET_H_
#define _PACKET_H_

#include <Windows.h>
#include <stdio.h>
#include <winsock.h>
#include "../defines.h"
#include "../structs.h"
#include "../common/logger.h"
#include "../common/database.h"


#define PACKET_LEN	1024*64
#define mychar						pck->me
#define inv							pck->me->inventory

class PACKET
{
public:
	PACKET(SOCKET sock, CHARACTER* me, DATABASE* mysql, FILE* fg, int* pingtime);
	~PACKET();
	bool PackRecv();								/*-- Получает паке? Записывает опко??opcode, заложенный размер пакета ?real_packet_size ?определени?криптовк??compress */
	bool NextPacket();
	void PackCreate();								/* Формирование буфера для отправки пакета */
	bool PackSend(uint16 op);						/* Добавляет заголово??отправ?ет паке?*/
	void CreateBufForSend();						/* Создае?буфе?для отправ?емог?пакета */
	void drop();									/* Удаляет информацию ?пакете */
	void Disconnect();								/* ¬І¬С¬Щ¬в¬н¬У¬С¬Ц¬д ¬б¬а¬Х¬Ь¬Э¬р¬й¬Ц¬Я¬Ъ¬Ц*/
	void IsOnePacket(bool set);						// 

	int*				pingtime;
	uint16				packet_len;					/* Размер пакета ?данным?*/
	uint16				opcode;
	uint16				real_packet_size;
	bool				compress;
	char				packet_buf[PACKET_LEN];
	char*				GetPacketPointer();			/* Возвращает указател?на буфе?пакета учитыв? смещение */
	DATABASE*			sql;						/* ¬µ¬Ь¬С¬Щ¬С¬д¬Ц¬Э¬о ¬Я¬С ¬Ь¬Э¬С¬г¬г ¬Х¬Э¬с ¬в¬С¬Т¬а¬д¬н ¬г ¬ў¬Ґ */
	CHARACTER*			me;
	bool				isconndected;
	FILE*				fg;

private:	
	SOCKET				socket;
	int					_packet_len;
	uint32				size_new_packet;
	char*				buf_use_packed;
	uint32				offset;
	uint32				offset_snd;
	char				packet_snd[PACKET_LEN];
	
	uint16				old_packet_len;
	uint16				old_offset;
	bool				onepacketsend;
	int					onepacket_step;
	char				onepacket[PACKET_LEN];	
	
public:

	template <typename T> T read()
	{
		try
		{
			T ret = *(reinterpret_cast<T*>(&buf_use_packed[offset]));

			offset += sizeof(T);
			return ret;
		}
		catch (char* msg)
		{
			lg::Error(fg, "PCKHandler: Error at reading. ErrorMsg: %s \n", msg);
			return NULL;
		}
	}

	//====================================================================================
	// get unicode string. End NULL
	//
	int readWstr(WCHAR* wc)
	{
		int step = 0;
		for (int i = offset; i < packet_len; i += 2)
		{
			step += 2;
			if (buf_use_packed[i] == 0)
				break;			
		}

		memcpy(wc, &buf_use_packed[offset], step);
		offset += step;
		return step / 2;
	}

	//====================================================================================
	// get ascii string. End NULL
	//
	int readTstr(TCHAR* tc)
	{
		int step = 0;
		for (int i = 0; i < real_packet_size; i++)
		{
			++step;
			if ((uint8)buf_use_packed[offset+i] == 0)
				break;			
		}

		memcpy(tc, &buf_use_packed[offset], step);
		offset += step;
		return step;
	}

	//====================================================================================
	// Читает в буфер указанное количество символов
	//
	int readBuf(char* buf, int len)
	{
		memcpy(buf, buf_use_packed + offset, len);
		offset += len;
		return len;
	}

	//====================================================================================
	// Читает в буфер количество байт определенных в первых 2х байтах
	//
	int read2Str(char* buf)
	{
		uint16 size = *(reinterpret_cast<uint16*>(&buf_use_packed[offset]));
		offset += 2;
		memset(buf, 0, size+1);
		memcpy(buf, &buf_use_packed[offset], size);
		offset += size;
		return size;
	}

	//====================================================================================
	// записывает число в пакет
	//
	template <typename T> void write(T newData)
	{
		try
		{
			assert((offset_snd + sizeof(T)) <= PACKET_LEN);
			memcpy(&packet_snd[offset_snd], reinterpret_cast<uint8*>(&newData), sizeof(newData));

			offset_snd += sizeof(newData);
		}
		catch (char* msg)
		{
			lg::Error(fg, "PCKHandler: Error at writing. ErrorMsg: %s \n", msg);
		}
	}

	//====================================================================================
	// Записывает unicode строку исходя из wcslen
	//
	int writeUstr(WCHAR* wc, bool setlen = false)
	{
		int16 lenwc = wcslen(wc);
		if (setlen)
		{
			int16 unisize = lenwc;
			memcpy(&packet_snd[offset_snd], reinterpret_cast<uint16*>(&unisize), sizeof(unisize));
			offset_snd += sizeof(unisize);
			unisize -= 2;
		}
		memcpy(packet_snd + offset_snd, wc, lenwc * 2 + 2);
		offset_snd += lenwc*2+2;
		return lenwc;
	}

	int writeUstr(WCHAR* wc, uint16 len)
	{
		memcpy(&packet_snd[offset_snd], reinterpret_cast<uint8*>(&len), sizeof(len));
		memcpy(packet_snd + offset_snd, wc, len * 2+2);
		offset_snd += len * 2 + 4;
		return (len*2)+2;
	}

	//====================================================================================
	// Записывает ascii строку исходя из strlen
	//
	int writeTstr(TCHAR* tc, bool setlen = false)
	{
		int16 lentc = strlen(tc);
		if (setlen)
		{
			memcpy(&packet_snd[offset_snd], reinterpret_cast<uint16*>(&lentc), sizeof(lentc));
			offset_snd += sizeof(lentc);
			--lentc;
		}
		memcpy(packet_snd + offset_snd, tc, lentc+1);
		offset_snd += lentc+1;
		return lentc;
	}

	//====================================================================================
	// Записывает ascii строку исходя из переменной len
	//
	int writeTstr(TCHAR* tc, uint16 len)
	{
		memcpy(&packet_snd[offset_snd], reinterpret_cast<uint8*>(&len), sizeof(len));
		memcpy(packet_snd + offset_snd, tc, len);
		offset_snd += len + 2;
		return (len + 2);
	}

	//====================================================================================
	// Записывает в буфер пакета указанное количество байт
	//
	int writeBuf(void* tc, int len)
	{
		memcpy(packet_snd + offset_snd, tc, len);
		offset_snd += len;
		return len;
	}

	void writeA(char* in)
	{
		uint8 res;
		char tmp[3];
		memset(tmp, 0, 3);

		for (int i = 0; i < (int)strlen(in); i += 2)
		{
			strncpy(tmp, in + i, 2);
			res = (uint8)strtol(tmp, NULL, 16);
			memcpy(&packet_snd[offset_snd], reinterpret_cast<uint8*>(&res), sizeof(res));
			++offset_snd;
		}
	}
};

#endif _PACKET_H_