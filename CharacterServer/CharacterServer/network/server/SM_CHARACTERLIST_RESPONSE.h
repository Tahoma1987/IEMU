////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_CHARACTERLIST_RESPONSE_H_
#define _SM_CHARACTERLIST_RESPONSE_H_

void SM_CHARACTERLIST_RESPONSE(PACKET* pck)
{
	tm* timeinfo;
	int num_characters = pck->sql->GetCharactersInfo(account->account_id, account->character, max_characters);

	pck->CreateBufForSend();
	pck->writeD(0); // unk
	pck->writeB(1); // unk
		
	if (num_characters == 20)
	{
		pck->writeB(1);
		pck->writeW(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->PackSend(OPCODE_SM_CHARACTERLIST_RESPONSE);
		return;
	}

	if (num_characters >= max_characters)
		pck->writeB(DENY_CREATE_CHARACTER);						// deny create character
	else
		pck->writeB(ALLOW_CREATE_CHARACTER);					// access create character

	pck->writeW(num_characters);								// max characters in server
	pck->writeD(account->character[0].id);
	pck->writeD(0);
	for (int i = 0; i < num_characters; i++)
	{
		timeinfo = localtime(&account->character[i].create_time);
		pck->writeD(account->character[i].id);
		pck->writeBuf((void*)&account->character[i].charname, 20);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeW(0);
		pck->writeW(0);
		pck->writeW(1);
		pck->writeW(1);
		pck->writeW(0);
		pck->writeW(1);
		pck->writeD(account->character[i].cls);
		pck->writeW(account->character[i].lvl);		// level
		pck->writeB(account->character[i].sex);		// sex
		pck->writeB(0);
		pck->writeB(13);
		pck->writeB(0);
		pck->writeB(0);
		pck->writeB(0);
		pck->writeD(0x433f0000);		// 191.000000
		pck->writeD(0x44580800);		// 864.125000
		pck->writeD(0x42c40000);		// 98.000000
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xb1000000);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0xffffffff);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0xd9efa578);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0x02800000);
		pck->writeB(0x32);
		pck->writeB(timeinfo->tm_min);			// minuta sozdaniya persa
		pck->writeB(timeinfo->tm_hour);			// chas sozdaniya persa
		pck->writeB(timeinfo->tm_mday);			// den sozdaniya persa
		pck->writeB(timeinfo->tm_mon);			// mesac sozdaniya persa
		pck->writeB(timeinfo->tm_year-100);		// god sozdaniya persa
		pck->writeW(0x44a6);
		pck->writeD(0x0145);
		pck->writeD(0);
		pck->writeD(0x0001006a);				// ðóáàøêà = slot 1
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0x1EFFE1);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0x0001006b);				// áîòû = slot 7
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0x00010084);				// ïåð÷è = slot 2
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);			
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0x00000076);				// weapon = slot 3
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0xffffffff);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeBuf((void*)&account->character[i].style, sizeof(CHAR_STYLE));
		pck->writeB(0);
		pck->writeW(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
		pck->writeD(0);
	}
	pck->PackSend(OPCODE_SM_CHARACTERLIST_RESPONSE);
}

#endif


/*
5602
0511
0000
00000000
0100
0100
7e6f2500
00000000
7e6f2500
46006c0061007900730000000000000000000000
00000000
00000000
00000000
00000000
00000000
01000000
01000000
0c000000
0000
3f43
0080
58440000
c4420000
00000000
00000000
0000b100
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
0000
ffffffff
00000000
ffffffff
ffffffff
ffffffff
00000000
78a5efd9
02000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00008002
321d011b
0b0e0000
45010000
00000000
6c000100
0000ffff
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
6d000100
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
ffffffff
00000000
00000000
00000000
813ecb32062b1427b336993ae12e6a4200008504ffffffffecff1300ffffffff111d2bffc1c1c1ff565656ffb8daa7ff707070ff000000ff000000ff000000ffffffffffffffffff3f33c105b3caf2f0da03100dc7fd1ed4b3e5ca0000000000000000000000003800452f64fc07000000000000e3fcdfc6ec00004700000000000000640000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

¬Ö¬ã¬Ý¬Ú ¬ß¬Ö¬ä ¬é¬Ñ¬â¬à¬Ó
[1600][0511]
0000
00000000
01000000
00000000
00000000
*/