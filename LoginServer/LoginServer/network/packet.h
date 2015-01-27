////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _PACKET_H_
#define _PACKET_H_

#include <Windows.h>
#include <stdio.h>
#include "../defines.h"
#include "../structs.h"
#include "../common/logger.h"


#define PACKET_LEN	1024*64

class PACKET
{
public:
	PACKET(THREAD_STRUCT* sockstruct);
	~PACKET();
	bool PackRecv();								/*-- Получает паке? Записывает опко??opcode, заложенный размер пакета ?real_packet_size ?определени?криптовк??compress */
	void PackCreate();								/* Формирование буфера для отправки пакета */
	bool PackSend(uint16 op);						/* Добавляет заголово??отправ?ет паке?*/
	void CreateBufForSend();						/* Создае?буфе?для отправ?емог?пакета */
	void drop();									/* Удаляет информацию ?пакете */
	void Disconnect();								/* ¬І¬С¬Щ¬в¬н¬У¬С¬Ц¬д ¬б¬а¬Х¬Ь¬Э¬р¬й¬Ц¬Я¬Ъ¬Ц*/

	int					packet_len;					/* Размер пакета ?данным?*/
	uint16				opcode;
	uint16				real_packet_size;
	bool				compress;
	char				packet_buf[PACKET_LEN];
	char*				GetPacketPointer();			/* Возвращает указател?на буфе?пакета учитыв? смещение */
	THREAD_STRUCT*		sockstruct;
	bool				isconnected;

private:	
	int					_packet_len;
	uint32				size_new_packet;
	char*				buf_use_packed;
	uint32				offset;
	uint32				offset_snd;
	char				packet_snd[PACKET_LEN];
	FILE*				fg;
	
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
			log::Error(fg, "[ERROR] Error at reading. ErrorMsg: %s \n", msg);
			return NULL;
		}
	}

	// Копирует? UNICODE строка ?переданный буфе??возвращает длин?
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

	// Заполняет буфер out до первого нуля
	int readTstr(TCHAR* out)
	{
		int step = 0;
		for (int i = 0; i < real_packet_size; i++)
		{
			++step;
			if ((uint8)buf_use_packed[offset+i] == 0)
				break;			
		}

		memcpy(out, &buf_use_packed[offset], step);
		offset += step;
		return step;
	}

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
			log::Error(fg, "[ERROR] Error at writing. ErrorMsg: %s \n", msg);
		}
	}

	//====================================================================================
	// Копирует строку UNICODE в передаваемый пакет
	//
	int writeUstr(WCHAR* wc)
	{
		int lenwc = wcslen(wc);
		memcpy(packet_snd + offset_snd, wc, lenwc * 2 + 2);
		offset_snd += lenwc*2+2;
		return lenwc;
	}

	//====================================================================================
	// Копирует строку типа CHAR в передаваемый пакет
	//
	int writeTstr(TCHAR* tc)
	{
		int lentc = strlen(tc);
		memcpy(packet_snd + offset_snd, tc, lentc+1);
		offset_snd += lentc+1;
		return lentc;
	}

	//====================================================================================
	// Копирует передаваемый буфер в отправляемый пакет
	//
	int writeBuf(TCHAR* tc, int len)
	{
		memcpy(packet_snd + offset_snd, tc, len);
		offset_snd += len;
		return len;
	}
};

#endif _PACKET_H_