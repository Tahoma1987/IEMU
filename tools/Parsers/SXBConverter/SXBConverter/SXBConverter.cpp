// DataParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SXBConverter.h"

//=================================================================================
// Create BAK file
//
void CreateBackupFile(char* filename)
{
	int filesize;
	char bak_filename[256];
	sprintf(bak_filename, "%s.bak", filename);
	FILE* freal = fopen(filename, "rb");
	if (freal)
	{
		printf("Create backup file: %s", filename);
		fprintf(fLog, "Create backup file: %s", filename);
		FILE* fbak = fopen(bak_filename, "wb");
		fseek(freal, 0, SEEK_END);
		filesize = ftell(freal);
		fseek(freal, 0, SEEK_SET);

		void *buf = malloc(filesize);
		fread(buf, filesize, 1, freal);
		fwrite(buf, filesize, 1, fbak);
		free(buf);

		fclose(freal);
		fclose(fbak);
	}
}

//=================================================================================
// Ôîðìèðóåì SXB èç ïîëó÷åííûõ äàííûõ
//
void SaveSXBFile(__int16 num_all_blocks, unsigned int data_size)
{
	printf("Build SXB file.\n", filename);
	fprintf(fLog, "Build SXB file.\n", filename);
	fflush(fLog);

	char* mem;
	int DataSXB_size;
	int OffesetsSXB_size;

//	__int16 numkeys = 5;
	char key1[] = "key";
	char key2[] = "korean";
	char key3[] = "jpn";
	char key4[] = "chinese";
	char key5[] = "enu";
	__int8 unk = 1;
	__int8 size_key;


	fOffesetsSXB = fopen(sxb001, "rb");
	fDataSXB = fopen(sxb002, "rb");

	fseek(fOffesetsSXB, 0, SEEK_END);
	OffesetsSXB_size = ftell(fOffesetsSXB);
	fseek(fOffesetsSXB, 0, SEEK_SET);

	fseek(fDataSXB, 0, SEEK_END);
	DataSXB_size = ftell(fDataSXB);
	fseek(fDataSXB, 0, SEEK_SET);

	fwrite(&num_keys, 2, 1, fResult);			// num_keys (2)

	for (int i = 0; i < num_keys; i++)
	{
		size_key = strlen(keys[i].name);
		fwrite(&unk, 1, 1, fResult);
		fwrite(&size_key, 1, 1, fResult);
		fwrite(&keys[i].name, size_key, 1, fResult);

	}

	fwrite(&num_all_blocks, 2, 1, fResult);		// num_all_blocks

	mem = (char*)malloc(OffesetsSXB_size);
	fread(mem, OffesetsSXB_size, 1, fOffesetsSXB);
	fwrite(mem, OffesetsSXB_size, 1, fResult);
	free(mem);

	fwrite(&data_size, 4, 1, fResult);

	mem = (char*)malloc(DataSXB_size);
	fread(mem, DataSXB_size, 1, fDataSXB);
	fwrite(mem, DataSXB_size, 1, fResult);
	free(mem);

	fclose(fOffesetsSXB);
	fclose(fDataSXB);

	DeleteFile(sxb001);
	DeleteFile(sxb002);

}

void ConvertXMLtoSXB()
{
	printf("Convert file XML to SXB.\n", filename);
	fprintf(fLog, "Convert file XML to SXB.\n", filename);
	fflush(fLog);

	int contentLength;
	size_t convertedChars;
	int step_to_write = 0;
	unsigned __int32 step = 0;
	__int16 null = 0;
	__int16 num_all_blocks = 0;
	WCHAR wcstring[1024];
	char tmp[128];

	TiXmlDocument *xml = new TiXmlDocument(filename);
	const TiXmlElement* elem;
	if (xml->LoadFile())
	{
		TiXmlElement* blocks = xml->FirstChildElement("blocks");
		if (!blocks)
		{
			fprintf(fLog, "XML file incorrect.\n");
			printf("XML file incorrect.\n");
			fflush(fLog);
		}

		if ((elem = blocks->FirstChildElement("keys")))
		{
			if (elem->Attribute("num_keys"))
			{
				num_keys = atoi(elem->Attribute("num_keys"));
			}

			for (int i = 0; i < num_keys; i++)
			{
				sprintf(tmp, "key%d", i + 1);
				if (elem->Attribute(tmp))
				{
					memset(&keys[i].name, 0, 256 - 1);
					strcpy(keys[i].name, elem->Attribute(tmp));
				}
			}
		}

		for (const TiXmlElement* elem = blocks->FirstChildElement("block"); elem; elem = elem->NextSiblingElement("block"))
		{
			if (elem->Attribute(keys[0].name))
			{
				memset(wcstring, 0, sizeof(wcstring));
				fwrite(&step_to_write, 4, 1, fOffesetsSXB);				
				mbstowcs_s(&convertedChars, wcstring, strlen(elem->Attribute(keys[0].name)) + 1, elem->Attribute(keys[0].name), _TRUNCATE);
				step_to_write += convertedChars;
				fwrite((char*)wcstring, convertedChars * 2, 1, fDataSXB);
				step += convertedChars * 2;
			}
			if (elem->Attribute(keys[1].name))
			{
				memset(wcstring, 0, sizeof(wcstring));
				fwrite(&step_to_write, 4, 1, fOffesetsSXB);
				contentLength = MultiByteToWideChar(65001, 0, elem->Attribute(keys[1].name), -1, NULL, NULL);
				step_to_write += contentLength;
				MultiByteToWideChar(65001, 0, elem->Attribute(keys[1].name), -1, wcstring, contentLength);
				fwrite((char*)wcstring, contentLength *2, 1, fDataSXB);
				step += contentLength * 2;
				++num_all_blocks;
				
				if (num_keys > 2)
				{
					for (int i = 0; i < (num_keys - 2); i++)
					{
						fwrite(&step_to_write, 4, 1, fOffesetsSXB);
						fwrite(&null, 2, 1, fDataSXB);
						++step_to_write;						
					}
				}
			}
		}

		fclose(fOffesetsSXB);
		fclose(fDataSXB);
		Sleep(1000);
		SaveSXBFile(num_all_blocks, step);
		fclose(fResult);
	}
	else
	{
		fprintf(fLog, "Can't open XML file.\n");
		printf("Can't open XML file.\n");
		fflush(fLog);
	}
}

void ConvertSXBtoXML()
{
	printf("Convert file SXB to XML.\n", filename);
	fprintf(fLog, "Convert file SXB to XML.\n", filename);
	fflush(fLog);
	
	__int16 num_offsets;
	int data_step;
	size_t convertedChars = 0;
	char buf[1024 * 2];
	char commxml_start[] = "<!-- ";
	char commxml_end[] = " -->\n";

	// ðàçáîð çàãîëîâêà
	fread(&num_keys, 2, 1, freal);
	fprintf(fLog, "num_keys: %d\n", num_keys);
	if (num_keys == 0)
		return;

	for (int i = 0; i < num_keys; i++)
	{
		memset(&keys[i].name, 0, 256);
		fread(&keys[i].unk, 1, 1, freal);
		fread(&keys[i].size, 1, 1, freal);
		fread(&keys[i].name, keys[i].size, 1, freal);
		fwrite(commxml_start, strlen(commxml_start), 1, fResult);
		fwrite(&keys[i].name, strlen(keys[i].name), 1, fResult);		
		fwrite(commxml_end, strlen(commxml_end), 1, fResult);
		printf(commxml_start);
		printf(keys[i].name);
		printf(commxml_end);
	}
	fflush(fResult);

	// çàãðóçêà îôôñåòîâ
	fread(&num_offsets, 2, 1, freal);
	int offset_buffer_size = num_offsets * num_keys * 4;
	data_step = offset_buffer_size + 4;

	offsets = (char*)malloc(offset_buffer_size + 4);
	memset(offsets, -1, offset_buffer_size + 4);
	fread(offsets, data_step , 1, freal);

	int ss = ftell(freal);
	unsigned __int32 size_keydata = 0;
	void* data;

	int step_xml = 0;

	fwrite(xml00, strlen(xml00), 1, fResult);
	printf(xml00);

	// Çàïèñûâàåì âñå êëþ÷è â XML
	fwrite(xml02, strlen(xml02), 1, fResult);
	printf(xml_s);
	sprintf(buf, param1, num_keys);
	fwrite(buf, strlen(buf), 1, fResult);
	printf(buf);
	for (int i = 0; i < num_keys; i++)
	{
		sprintf(buf, "key%d=\"%s\" ", i + 1, keys[i].name);
		fwrite(buf, strlen(buf), 1, fResult);
		printf(buf);
	}

	fwrite(xml_e, strlen(xml_e), 1, fResult);
	printf(xml_e);
	fflush(fResult);
	
	for (int i = 0; i < num_offsets * num_keys; i++)
	{
		size_keydata = *(reinterpret_cast<unsigned __int32*>(&offsets[(i + 1) * 4])) - *(reinterpret_cast<unsigned __int32*>(&offsets[i * 4]));
		size_keydata *= 2;
		data = malloc(size_keydata + 1);
		memset(data, 0, size_keydata);
		fread(data, size_keydata, 1, freal);

		if (step_xml == 0)
		{
			fwrite(xml_s, strlen(xml_s), 1, fResult);
			printf(xml_s);
		}

		if (strstr(keys[step_xml].name, "korean") != NULL || strcmp(keys[step_xml].name, "key") == NULL)
		{
			fwrite(&keys[step_xml].name, strlen((const char*)&keys[step_xml].name), 1, fResult);
			fwrite(xml_t1, strlen(xml_t1), 1, fResult);
			printf((const char*)&keys[step_xml].name);
			printf(xml_t1);

			memset(buf, 0, 511);

			if (strcmp(keys[step_xml].name, "key") == NULL)
			{
				wcstombs(buf, (WCHAR*)data, sizeof(buf));
			}
			else
			{
				if (translate)
				{
					Translat((WCHAR*)data);
					sprintf(buf, "%s", tmp_translate);
				}
				else
				{
					if (korean)
					{
						int cbNeeded = WideCharToMultiByte(949, 0, (WCHAR*)data, -1, NULL, 0, NULL, NULL);
						WideCharToMultiByte(949, 0, (WCHAR*)data, -1, buf, cbNeeded, NULL, NULL);
					}
					else
					{
						int cbNeeded = WideCharToMultiByte(CP_UTF8, 0, (WCHAR*)data, -1, NULL, 0, NULL, NULL);
						WideCharToMultiByte(CP_UTF8, 0, (WCHAR*)data, -1, buf, cbNeeded, NULL, NULL);
						//					sprintf(buf, "%s", data);
					}
				}
			}

			fwrite(buf, strlen(buf), 1, fResult);
			fwrite(xml_t2, strlen(xml_t2), 1, fResult);
			printf(buf);
			printf(xml_t2);
		}
		free(data);

		++step_xml;
		if (step_xml == num_keys)
		{
			step_xml = 0;
			fwrite(xml_e, strlen(xml_e), 1, fResult);
			printf(xml_e);
		}
		fflush(fResult);
			
	}

	fwrite(xml01, strlen(xml01), 1, fResult);
	printf(xml01);
	free(offsets);
	fclose(freal);
	fclose(fResult);
}

//=================================================================================
// Êîíâåðòàöèÿ þíèêîäà â HEX ñòðîêó
//
void wstring_to_utf8_hex(char* output, WCHAR* input)
{
	output[0] = 0;
	int step = 0;
	int cbNeeded = WideCharToMultiByte(CP_UTF8, 0, input, -1, NULL, 0, NULL, NULL);
	if (cbNeeded > 0) {
		char *utf8 = new char[cbNeeded];
		if (WideCharToMultiByte(CP_UTF8, 0, input, -1, utf8, cbNeeded, NULL, NULL) != 0) {
			for (char *p = utf8; *p; *p++) {
				char onehex[5];
				_snprintf(onehex, sizeof(onehex), "%%%02.2X", (unsigned char)*p);
				sprintf(output, "%s%s", output, onehex);
			}
		}
		delete[] utf8;
	}
}

size_t cb(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t realsize = size * nmemb;
	MemoryStruct *mem = (struct MemoryStruct *)userdata;

	mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
		/* out of memory! */
		printf("not enough memory (realloc returned NULL)\n");
		fprintf(fLog, "Not enough memory (realloc returned NULL)\n");
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), ptr, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}

//=================================================================================
// Ïåðåâîäèò óêàçàííóþ ñòðîêó â HEX âèä
// îòïðàâëÿåò ãóãëó äëÿ ïåðåâîäà
//
void Translat(WCHAR* txt)
{
	MemoryStruct ms;
	char* aaa;
	char* stp;

	memset(tmp_translate, 0, 1024 * 4 - 1);
	int txt_size = wcslen(txt);
	if (txt_size == 0)
		return;

	aaa = (char*)malloc(txt_size * 10);
	stp = (char*)malloc(txt_size * 10 + 128);

//	char aaa[1024*4];
//	char stp[1024 * 4];
	memset(aaa, 0, txt_size * 10-1);
	memset(stp, 0, txt_size * 10+128-1);
	wstring_to_utf8_hex(aaa, txt);
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		if (!toeng)
			sprintf(stp, "http://translate.google.ru/translate_a/t?client=x&text=%s&hl=kr&sl=kr&tl=ru", aaa);
		else
			sprintf(stp, "http://translate.google.ru/translate_a/t?client=x&text=%s&hl=kr&sl=kr&tl=en", aaa);

		struct curl_slist *chunk = NULL;
		
		ms.memory = (char*)malloc(1);
		ms.size = 0;
		chunk = curl_slist_append(chunk, "Accept: text/html, application/xhtml+xml, */*");
		chunk = curl_slist_append(chunk, "Accept-Language: ru,en-US;q=0.8,en;q=0.5,ko;q=0.3");
		chunk = curl_slist_append(chunk, "User-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64; Trident/7.0; rv:11.0) like Gecko");
		chunk = curl_slist_append(chunk, "Connection: Keep-Alive");
		res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		res = curl_easy_setopt(curl, CURLOPT_URL, stp);
		res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
		res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ms);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			fprintf(fLog, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		else
		{
			char check[] = "\"trans\":\"";
			int step_chk = 0;
			int step_tmp_translate = 0;
			char* settranschar;
			char* begin_mem = ms.memory;

			while (true)
			{
				if ((settranschar = strstr(begin_mem, check)) != NULL)
				{
					settranschar += strlen(check);
					step_chk = 0;
					if (ms.size > (settranschar - begin_mem))
					{
						for (int i = 0; i < ms.size - (settranschar - begin_mem); i++)
						{
							if (settranschar[i] == 0x22)
							{
								memcpy(tmp_translate + step_tmp_translate, settranschar, i);
								step_tmp_translate += i;
								break;
							}
						}
					}
					begin_mem = settranschar;
					++begin_mem;
				}
				else
				{
					break;
				}
			}
		}
		curl_easy_cleanup(curl);

		if (ms.memory)
			free(ms.memory);

		free(aaa);
		free(stp);
		curl_global_cleanup();
	}
}

//=================================================================================
// Ñîçäàåì ôàéë äëÿ ðåçóëüòàòà çàìåíÿ ðàñøèðåíèå íà XML
//
bool CreateResultFile(char* fname)
{
	fprintf(fLog, "Create result files.\n", filename);
	fflush(fLog);

	char newfilename[MAX_PATH];
	char drive[12];
	char dir[MAX_PATH];
	char name[MAX_PATH];
	char ext[12];
	_splitpath(fname, drive, dir, name, ext);
	sprintf(short_filename, "%s%s%s%s", drive, dir, name, ext);

	if (xml_to_sxb)
	{
		sprintf(sxb001, "%s%s%s.001", drive, dir, name);
		fOffesetsSXB = fopen(sxb001, "wb");
		if (!fOffesetsSXB)
			return false;

		sprintf(sxb002, "%s%s%s.002", drive, dir, name);
		fDataSXB = fopen(sxb002, "wb");
		if (!fDataSXB)
			return false;
		
		sprintf(newfilename, "%s%s%s.sxb", drive, dir, name);
		CreateBackupFile(newfilename);
		fResult = fopen(newfilename, "wb");
		if (!fResult)
			return false;
	}
	else
	{
		sprintf(newfilename, "%s%s%s.xml", drive, dir, name);
		CreateBackupFile(newfilename);
		fResult = fopen(newfilename, "wb");
		if (!fResult)
			return false;

		char xml[] = "<?xml version = \"1.0\"?>\n";
		fwrite(xml, strlen(xml), 1, fResult);
	}

	return true;
}

void CheckConvert()
{
	if (xml_to_sxb)
	{
		if (!CreateResultFile(filename))
		{
			fprintf(fLog, "Can't create result file.\n");
			fflush(fLog);
			return;
		}
		ConvertXMLtoSXB();
	}
	else
	{
		if (!CreateResultFile(filename))
		{
			fprintf(fLog, "Can't create result file.\n");
			fflush(fLog);
			return;
		}

		freal = fopen(filename, "rb");
		if (!filename)
		{
			printf("Can't open file %s\n\n", filename);
			fprintf(fLog, "Can't open file %s\n\n", filename);
			fflush(fLog);
			return;
		}

		printf("File: %s:\n", short_filename);
		fprintf(fLog, "File: %s:\n", short_filename);
		fflush(fLog);

		ConvertSXBtoXML();
	}

}

void DoSomething(LPCTSTR lpszFileName)
{
	strcpy(filename, lpszFileName);
	CheckConvert();
}

BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = TRUE)
{
	LPTSTR part;
	char tmp[MAX_PATH]; // ¬Ó¬â¬Ö¬Þ¬Ö¬ß¬ß¬í¬Û ¬Þ¬Ñ¬ã¬ã¬Ú¬Ó
	char name[MAX_PATH];

	HANDLE hSearch = NULL;
	WIN32_FIND_DATA wfd;
	memset(&wfd, 0, sizeof(WIN32_FIND_DATA));

	// ¬ã¬ß¬Ñ¬é¬Ñ¬Ý¬à ¬á¬à¬Ú¬ã¬Ü ¬Ó¬ß¬å¬ä¬â¬Ú ¬Ó¬Ý¬à¬Ø¬Ö¬ß¬ß¬í¬ç ¬á¬Ñ¬á¬Ü¬Ñ¬ç ...
	if (bInnerFolders)
	{
		if (GetFullPathName(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
		strcpy(name, part);
		strcpy(part, "*.*");

		// ¬Ö¬ã¬Ý¬Ú ¬á¬Ñ¬á¬Ü¬Ú ¬ã¬å¬ë¬Ö¬ã¬ä¬Ó¬å¬ð¬ä, ¬ä¬à ¬Õ¬Ö¬Ý¬Ñ¬Ö¬Þ ¬á¬à¬Ú¬ã¬Ü
		wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
		if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
			do
			{
				// ¬Ó ¬Ü¬Ñ¬Ø¬Õ¬à¬Û ¬á¬Ñ¬á¬Ü¬Ö ¬Ö¬ã¬ä¬î ¬Õ¬Ó¬Ö ¬á¬Ñ¬á¬Ü¬Ú ¬ã ¬Ú¬Þ¬Ö¬ß¬Ñ¬Þ¬Ú "." ¬Ú ".."
				// ¬Ú ¬ï¬ä¬Ú ¬á¬Ñ¬á¬Ü¬Ú ¬Þ¬í ¬ß¬Ö ¬ä¬â¬à¬Ô¬Ñ¬Ö¬Þ

				// ¬á¬â¬à¬á¬å¬ã¬Ü¬Ñ¬Ö¬Þ ¬á¬Ñ¬á¬Ü¬Ú "." ¬Ú ".."
				if (!strncmp(wfd.cFileName, ".", 1) || !strncmp(wfd.cFileName, "..", 2))
					continue;

				if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // ¬Ö¬ã¬Ý¬Ú ¬Þ¬í ¬ß¬Ñ¬ê¬Ý¬Ú ¬á¬Ñ¬á¬Ü¬å
				{
					char next[MAX_PATH];
					if (GetFullPathName(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
					strcpy(part, wfd.cFileName);
					strcat(next, "\\");
					strcat(next, name);

					SearchFiles(next, lpSearchFunc, TRUE);
				}
			} while (FindNextFile(hSearch, &wfd)); // ¬Ú¬ë¬Ö¬Þ ¬ã¬Ý¬Ö¬Õ¬å¬ð¬ë¬Ú¬Û ¬æ¬Ñ¬Û¬Ý

			FindClose(hSearch); // ¬Ù¬Ñ¬Ü¬Ñ¬ß¬é¬Ú¬Ó¬Ñ¬Ö¬Þ ¬á¬à¬Ú¬ã¬Ü
	}

	if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE)
		return TRUE; // ¬Ó ¬á¬â¬à¬ä¬Ú¬Ó¬ß¬à¬Þ ¬ã¬Ý¬å¬é¬Ñ¬Ö ¬Ó¬í¬ç¬à¬Õ¬Ú¬Þ
	do
		if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) // ¬Ö¬ã¬Ý¬Ú ¬Þ¬í ¬ß¬Ñ¬ê¬Ý¬Ú ¬æ¬Ñ¬Û¬Ý
		{
			char file[MAX_PATH];
			if (GetFullPathName(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
			strcpy(part, wfd.cFileName);

			lpSearchFunc(file);
		}
	while (FindNextFile(hSearch, &wfd)); // ¬Ú¬ë¬Ö¬Þ ¬ã¬Ý¬Ö¬Õ¬å¬ð¬ë¬Ú¬Û ¬æ¬Ñ¬Û¬Ý
	FindClose(hSearch); // ¬Ù¬Ñ¬Ü¬Ñ¬ß¬é¬Ú¬Ó¬Ñ¬Ö¬Þ ¬á¬à¬Ú¬ã¬Ü

	return TRUE;
}

void showstartparams()
{
	printf("Use: SXBConverter [-texak] <filename> or <all>\n");
	printf("\t-t\t Online Translate\n");
	printf("\t-e\t Translate to english (default: russian)\n");
	printf("\t-k\t Translate to korean (default: russian)\n");
	printf("\t-x\t XML to SXB (default: SXB to XML)\n");
	printf("\t-a\t Convert All files\n");

	fprintf(fLog, "Use: SXBConverter [-tsxak] <filename> or <all>\n");
	fprintf(fLog, "\t-t\t Online Translate\n");
	fprintf(fLog, "\t-e\t Translate to english (default: russian)\n");
	fprintf(fLog, "\t-k\t Translate to korean (default: russian)\n");
	fprintf(fLog, "\t-x\t XML to SXB (default: SXB to XML)\n");
	fprintf(fLog, "\t-a\t Convert All files\n");
	exit(0);
}

//=================================================================================
// Îñíîâíàÿ ôóíêöèÿ
//
int _tmain(int argc, _TCHAR* argv[])
{	
	xml_to_sxb = false;
	translate = false;
	toeng = false;
	allfiles = false;
	korean = false;

	fLog = fopen("./result.log", "a+");
	if (fLog == NULL)
	{
		printf("Can't create log file\n");
		return -1;
	}

	fprintf(fLog, "#######################################\n");
	fprintf(fLog, "# SXBConverter (ver: 1.00)            #\n");
	fprintf(fLog, "# Authors: Tahoma, lastfun            #\n");
	fprintf(fLog, "#######################################\n\n");
	fflush(fLog);
	/*
//	translate = true;
//	allfiles = true;
	xml_to_sxb = true;
	strcpy(filename, "localstringdata_dialog.xml");
	CheckConvert();
	return 0;*/
	
	
	if (argc < 2)
		showstartparams();
	
	int i = 1;
	while (argv[i][0] == '-')
	{
		switch (argv[i][1])
		{
		case 't':
			translate = true;
			break;
		case 'e':
			toeng = true;
			break;
		case 'x':
			xml_to_sxb = true;
			break;
		case 'a':
			allfiles = true;
			break;
		case 'k':
			korean = true;
			break;
		}
		++i;
		if (i > argc-1)
			break;
	}

	if (allfiles)
	{
		printf("Auto find files.\n");
		fprintf(fLog, "Auto find files.\n");
		fflush(fLog);
		if (xml_to_sxb)
			SearchFiles("*.xml", DoSomething, false);
		else
			SearchFiles("*.sxb", DoSomething, false);
	}
	else
	{
		strcpy(filename, argv[i]);

		if (strlen(filename) < 2)
			showstartparams();

		CheckConvert();
	}
	

	return 0;
}
