////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_CREATECHARACTER_H_
#define _CM_CREATECHARACTER_H_

void CM_CREATECHARACTER(PACKET* pck)
{
	CHAR_STYLE st;
	WCHAR w_charname[10];
	int len_character_name = pck->readBuf((char*)w_charname, 20);
	uint32 unk2 = pck->readUD();
	uint32 unk3 = pck->readUD();
	uint32 unk4 = pck->readUD();
	uint32 unk5 = pck->readUD();
	uint32 unk6 = pck->readUW();
	uint8 cls = pck->readUB();			// ¬Ü¬Ý¬Ñ¬ã¬ã
	uint8 sex = pck->readUB();			// ¬á¬à¬Ý
	int16 unk71 = pck->readW();
	st.unk81 = 0;
	st.unk0 = pck->readUW();
	st.unk1 = pck->readUD();
	st.eye = pck->readUB();				// ¬æ¬à¬â¬Þ¬Ñ ¬Ô¬Ý¬Ñ¬Ù
	st.unk2 = pck->readUB();
	st.eyebrows = pck->readUB();		// ¬Ò¬â¬à¬Ó¬Ú
	st.unk3 = pck->readUB();
	st.iris = pck->readUB();			// ¬Ù¬â¬Ñ¬é¬Ö¬Ü
	st.unk4 = pck->readUW();
	st.unk5 = pck->readUB();
	st.tatoo = pck->readUB();			// ¬ä¬Ñ¬ä¬å
	st.unk6 = pck->readUW();
	st.unk7 = pck->readUB();
	st.unk8 = pck->readUW();			// 0x0000
	st.unk9 = pck->readUD();			// 0xffffffff
	st.hair = pck->readUB();			// ¬á¬â¬Ú¬é¬Ö¬ã¬Ü¬Ñ
	st.unk10 = pck->readUW();
	st.unk11 = pck->readUB();
	st.unk12 = pck->readUD();			// 0xffffffff
	st.unk13 = pck->readUD();
	st.unk14 = pck->readUD();
	st.color_lips = pck->readUD();		// ¬è¬Ó¬Ö¬ä ¬Ô¬å¬Ò
	st.color_eyeb = pck->readUD();		// ¬è¬Ó¬Ö¬ä ¬Ò¬Ö¬Ý¬Ü¬Ñ
	st.color_iris = pck->readUD();		// ¬è¬Ó¬Ö¬ä ¬â¬Ñ¬Õ¬å¬Ø¬Ü¬Ú
	st.color_eyebrows = pck->readUD();	// ¬è¬Ó¬Ö¬ä ¬Ò¬â¬à¬Ó¬Ö¬Û
	st.color_eye = pck->readUD();		// ¬è¬Ó¬Ö¬ä ¬Ô¬Ý¬Ñ¬Ù
	st.unk15 = pck->readUD();
	st.unk16 = pck->readUD();
	st.unk17 = pck->readUD();
	st.unk18 = pck->readUD();
	st.unk19 = pck->readUD();
	st.unk20 = pck->readUD();
	st.unk21 = pck->readUD();
	st.unk22 = pck->readUD();
	st.unk23 = pck->readUD();
	st.unk24 = pck->readUD();
	st.unk25 = pck->readUD();
	st.unk26 = pck->readUD();
	st.unk27 = pck->readUD();
	st.unk28 = pck->readUD();
	st.unk29 = pck->readUD();
	st.unk30 = pck->readUD();
	st.unk31 = pck->readUD();
	st.unk32 = pck->readUD();
	st.unk33 = pck->readUD();
	st.unk34 = pck->readUB();
	st.unk35 = pck->readUB();
	st.unk36 = pck->readUB();
//	st.unk35 = pck->readUD();
//	st.unk36 = pck->readUD();
//	st.unk37 = pck->readUD();

	char charname[18];
	int len_charname = wcstombs(charname, w_charname, 18);
	if (len_charname < 4 || len_charname > 16)
	{
		SM_LOBBYUSERMSG(pck, 14);					// 
		return;
	}

	if (!(pck->sql->CheckCharname(charname)))
	{
		SM_LOBBYUSERMSG(pck, 14);					// !!!!!
		return;
	}

	int character_id = pck->sql->CreateCharacter(charname, &st, sex, cls, pck->sockstruct->account_id);

	SM_CREATECHARACTER(pck, character_id, charname, w_charname, cls, sex, &st);
}

#endif

/*
..T.a.h.o.m.a.......o............w...........>.2.*.'.6.:..iB..............pp......>>......!$(.....................?..................................................................Cp.....?....;
[021b]
5400610068006f006d0061000000 - nick
a802c0f5 +
6f09c897 + 
17000300 +
0000a0d5 +
0177f497 +
1700bcbb +
01       +
00		 +
00b1 +
813ec932 +
f9       + ¬æ¬à¬â¬Þ¬Ñ ¬Ô¬Ý¬Ñ¬Ù
2a       +
11       + ¬Ò¬â¬à¬Ó¬Ú
27       +
b1       + ¬Ù¬â¬Ñ¬é¬Ö¬Ü
3699     +
3a       +
e1       + ¬ä¬Ñ¬ä¬å
2e69     +
42       +
0000     +
ffffffff +
ec       + ¬á¬â¬Ú¬é¬Ö¬ã¬Ü¬Ñ
ff13     +
00       +
ffffffff +
707099ff +
d4d4d4ff +
3e3e82ff + ¬è¬Ó¬Ö¬ä ¬Ô¬å¬Ò 
ffffffff + ¬è¬Ó¬Ö¬ä ¬Ò¬Ö¬Ý¬Ü¬Ñ
212428ff + ¬è¬Ó¬Ö¬ä ¬â¬Ñ¬Õ¬å¬Ø¬Ü¬Ú
000000ff + ¬è¬Ó¬Ö¬ä ¬Ò¬â¬à¬Ó¬Ö¬Û
000000ff + ¬è¬Ó¬Ö¬ä ¬Ô¬Ý¬Ñ¬Ù
000000ff
ffffffff
ffffffff
3f
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬Ô¬à¬Ý¬à¬Ó¬í
00 // ¬â¬à¬ã¬ä
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬ê¬Ö¬Ú
00 // ¬Õ¬Ý¬Ú¬ß¬Ñ ¬ê¬Ö¬Ú
00 // ¬ê¬Ú¬â¬Ú¬ß¬Ñ ¬Ô¬â¬å¬Õ¬Ú
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬Ô¬â¬å¬Õ¬Ú
00 // ¬ê¬Ú¬â¬Ú¬ß¬Ñ ¬Ø¬Ú¬Ó¬à¬ä¬Ñ
00 // ¬Ó¬í¬ã¬à¬ä¬Ñ ¬Ø¬Ú¬Ó¬à¬ä¬Ñ
00 // ¬ê¬Ú¬â¬Ú¬ß¬Ñ ¬ä¬Ñ¬Ý¬Ú¬Ú
00 // ¬ê¬Ú¬â¬Ú¬ß¬Ñ ¬á¬Ý¬Ö¬é
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬á¬Ý¬Ö¬é¬Ö¬Ý¬å¬é¬Ö¬Ó¬à¬Û ¬Þ¬í¬ê¬è¬í
00 // ¬Õ¬Ý¬Ú¬ß¬Ñ ¬á¬Ý¬Ö¬é¬Ö¬Ý¬å¬é¬Ö¬Ó¬à¬Û ¬Þ¬í¬ê¬è¬í
00 // ¬Õ¬Ý¬Ú¬ß¬Ñ ¬Ü¬Ú¬ã¬ä¬Ú
00 // ¬ä¬à¬Ý¬ë¬Ú¬ß¬Ñ ¬Ý¬ñ¬ê¬Ö¬Ü
00 // ¬ä¬à¬Ý¬ë¬Ú¬ß¬Ñ ¬Ú¬Ü¬â
d8 // ¬Õ¬Ý¬Ú¬ß¬Ñ ¬ß¬à¬Ô
00 // ¬ä¬à¬Ý¬ë¬Ú¬ß¬Ñ ¬ã¬ä¬å¬á¬ß¬Ö¬Û
00 // ¬ã¬Ý¬à¬Ø¬Ö¬ß¬Ú¬Ö ¬ä¬Ö¬Ý¬Ñ (¬ç¬à¬Õ¬à¬ë¬Ñ¬Ó¬í¬Û - ¬ä¬à¬Ý¬ã¬ä¬í¬Û)
00 // ¬ã¬Ü¬å¬Ý¬í
00 // ¬à¬Ü¬â¬å¬Ô¬Ý¬à¬ã¬ä¬î ¬á¬à¬Õ¬Ò¬à¬â¬à¬Õ¬Ü¬Ñ
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬á¬à¬Õ¬Ò¬à¬â¬à¬Õ¬Ü¬Ñ
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬ã¬Ü¬å¬Ý
00 // ¬ä¬à¬Ý¬ë¬Ú¬ß¬Ñ ¬ë¬Ö¬Ü
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬Ô¬Ý¬Ñ¬Ù
00 // ¬â¬Ñ¬Ù¬Þ¬Ö¬â ¬Ù¬â¬Ñ¬é¬Ü¬à¬Ó
00 // ¬Ô¬Ý¬å¬Ò¬Ú¬ß¬Ñ ¬Ô¬Ý¬Ñ¬Ù
00 // ¬â¬Ñ¬ã¬ã¬ä¬à¬ñ¬ß¬Ú¬Ö ¬Ô¬Ý¬Ñ¬Ù
00 // ¬Ó¬í¬ã¬à¬ä¬Ñ ¬Ô¬Ý¬Ñ¬Ù
00 // ¬å¬Ù¬Ü¬à¬ã¬ä¬î ¬Ô¬Ý¬Ñ¬Ù
00 // ¬ã¬å¬Ø¬Ö¬ß¬Ú¬Ö ¬Ü ¬ß¬à¬ã¬å (¬á¬â¬à ¬Ô¬Ý¬Ñ¬Ù¬Ñ)
00 // ¬ã¬å¬Ø¬Ö¬ß¬Ú¬Ö ¬Ü ¬å¬ê¬Ñ¬Þ )))
00 // ¬Ó¬í¬ã¬à¬ä¬Ñ ¬Ò¬â¬à¬Ó¬Ö¬Û
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00
00000043
70bb19c1
b8b93fc1
00008a3b

*/