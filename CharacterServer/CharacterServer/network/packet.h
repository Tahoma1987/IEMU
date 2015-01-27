////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _PACKET_H_
#define _PACKET_H_

#include <Windows.h>
#include <stdio.h>
#include <assert.h>
#include "../defines.h"
#include "../structs.h"
#include "../common/logger.h"
#include "../common/database.h"

#define account		pck->sockstruct
#define PACKET_LEN	1024*64

class PACKET
{
public:
	PACKET(THREAD_STRUCT* sockstruct, int max_characters);
	~PACKET();
	bool PackRecv();								/*-- Получает паке? Записывает опко??opcode, заложенный размер пакета ?real_packet_size ?определени?криптовк??compress */
	void PackCreate();								/* Формирование буфера для отправки пакета */
	bool PackSend(uint16 op);						/* Добавляет заголово??отправ?ет паке?*/
	void CreateBufForSend();						/* Создае?буфе?для отправ?емог?пакета */
	void drop();									/* Удаляет информацию ?пакете */
	void Disconnect();								/* ¬І¬С¬Щ¬в¬н¬У¬С¬Ц¬д ¬б¬а¬Х¬Ь¬Э¬р¬й¬Ц¬Я¬Ъ¬Ц*/

	int					packet_len;					/* realno poluchennaya dlina paketa */
	uint16				opcode;
	uint16				real_packet_size;
	bool				compress;
	char				packet_buf[PACKET_LEN];
	char*				GetPacketPointer();			/* Возвращает указател?на буфе?пакета учитыв? смещение */
	THREAD_STRUCT*		sockstruct;
	DATABASE*			sql;						/* ¬µ¬Ь¬С¬Щ¬С¬д¬Ц¬Э¬о ¬Я¬С ¬Ь¬Э¬С¬г¬г ¬Х¬Э¬с ¬в¬С¬Т¬а¬д¬н ¬г ¬ў¬Ґ */
	bool				isconndecred;
	int					max_characters;

private:	
	int					_packet_len;
	uint32				size_new_packet;
	char*				buf_use_packed;
	uint32				offset;
	uint32				offset_snd;
	char				packet_snd[PACKET_LEN];
	FILE*				fg;
	int					cryptflag;
	
public:
	template <typename T> T read()
	{
		try
		{
			assert((offset + sizeof(T)) <= PACKET_LEN);
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

	//====================================================================================
	// ¬№¬Ъ¬д¬С¬Ц¬д ¬р¬Я¬Ъ¬Ь¬а¬Х ¬г¬д¬в¬а¬Ь¬е ¬У ¬е¬Ь¬С¬Щ¬С¬Я¬Я¬н¬Ы ¬Т¬е¬ж¬Ц¬в
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
	// ¬№¬Ъ¬д¬С¬Ц¬д ¬г¬д¬в¬а¬Ь¬е ¬У ¬е¬Ь¬С¬Щ¬С¬Я¬Я¬н¬Ы ¬Т¬е¬ж¬Ц¬в
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
	// ¬№¬Ъ¬д¬С¬Ц¬д ¬е¬Ь¬С¬Щ¬С¬Я¬Я¬а¬Ц ¬Ь¬а¬Э¬Ъ¬й¬Ц¬г¬д¬У¬а ¬г¬Ъ¬Ю¬У¬а¬Э¬а¬У ¬Ъ ¬Щ¬С¬б¬Ъ¬г¬н¬У¬С¬Ц¬д ¬У ¬Т¬е¬ж¬Ц¬в
	//
	int readBuf(char* buf, int len)
	{
		assert((offset + len) <= PACKET_LEN);
		memcpy(buf, buf_use_packed + offset, len);
		offset += len;
		return len;
	}

	//====================================================================================
	// ¬©¬С¬б¬Ъ¬г¬н¬У¬С¬Ц¬д ¬б¬Ц¬в¬Ц¬Ю¬Ц¬Я¬Я¬е¬р ¬е¬Ь¬С¬Щ¬С¬Я¬Я¬а¬Ф¬а ¬в¬С¬Щ¬Ю¬Ц¬в¬С ¬У ¬г¬а¬Щ¬Х¬С¬У¬С¬Ц¬Ю¬н¬Ы ¬б¬С¬Ь¬Ц¬д
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
			log::Error(fg, "[ERROR] Error at writing. ErrorMsg: %s \n", msg);
		}
	}

	//====================================================================================
	// ¬©¬С¬б¬Ъ¬г¬н¬У¬С¬Ц¬д ¬р¬Я¬Ъ¬Ь¬а¬Х ¬г¬д¬в¬а¬Ь¬е ¬У ¬г¬а¬Щ¬Х¬С¬У¬С¬Ц¬Ю¬н¬Ы ¬б¬С¬Ь¬Ц¬д
	//
	int writeUstr(WCHAR* wc)
	{
		try
		{
			assert((offset_snd + (wcslen(wc)*2+2)) <= PACKET_LEN);
			int lenwc = wcslen(wc);
			memcpy(packet_snd + offset_snd, wc, lenwc * 2 + 2);
			offset_snd += lenwc*2+2;
			return lenwc;
		}
		catch (char* msg)
		{
			log::Error(fg, "[ERROR] Error at writing. ErrorMsg: %s \n", msg);
		}
	}

	//====================================================================================
	// ¬©¬С¬б¬Ъ¬г¬н¬У¬С¬Ц¬д ¬г¬д¬в¬а¬Ь¬е ¬У ¬г¬а¬Щ¬Х¬С¬У¬С¬Ц¬Ю¬н¬Ы ¬б¬С¬Ь¬Ц¬д
	//
	int writeTstr(TCHAR* tc)
	{
		int lentc = strlen(tc);
		memcpy(packet_snd + offset_snd, tc, lentc+1);
		offset_snd += lentc+1;
		return lentc;
	}

	//====================================================================================
	// ¬©¬С¬б¬Ъ¬г¬н¬У¬С¬Ц¬д ¬Т¬е¬ж¬Ц¬в ¬Щ¬С¬Х¬С¬Я¬Я¬а¬Ф¬а ¬в¬С¬Щ¬Ю¬Ц¬в¬С ¬У ¬г¬а¬Щ¬Х¬С¬У¬С¬Ц¬Ю¬н¬Ы ¬б¬С¬Ь¬Ц¬д
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