////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _SM_SETAREA_H_
#define _SM_SETAREA_H_

inline void SM_SETAREA(PACKET* pck)
{
	Sleep(300);
	char area[] = "area_f01_p_0001";
	char tmp_area[24];
	memset(tmp_area, 0, 24);
	strcpy(tmp_area, area);

	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeUD(pck->me->id & 0xfffffff);
//	pck->writeA("5400610068006F006D0061003200000000000000000000000000000000000000000000000100050100F51F310000000000000000030000007A020000000000000D0000000000000014CC3A44437627449E72D9410000B0421800000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFFFFFF0000000000000000C4C4343F010000008047A43F01000000D49C343F0100000008A01E3401000000D8719A5001000000617265615F6630315F705F303030310000000000000000000000003F01000000");
//	pck->PackSend(OPCODE_SM_SETAREA);
//	return;
	pck->writeBuf(mychar->charname, 20);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeB(0);
	pck->writeB(0);
	pck->writeB(2);// pck->me->cls);
	pck->writeB(mychar->sex);
	pck->writeD(0x3bd70900);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeW(pck->me->lvl);
	pck->writeW(0);
	pck->writeD(0);
	pck->writeW(0);
	pck->writeB(0);
	pck->writeB(0);
	pck->writeB(13);
	pck->writeB(0);
	pck->writeW(0);
	pck->writeD(0);
	pck->writeF(mychar->pos.pos_x);
	pck->writeF(mychar->pos.pos_y);
	pck->writeF(mychar->pos.pos_z);
	pck->writeF(mychar->pos.rotate);
//	pck->writeD(0x443e0b61);		// pos_x
//	pck->writeD(0x4460cb05);		// pos_y
//	pck->writeD(0x420032bc);		// pos_z
//	pck->writeD(0x43070000);		// rotate
	pck->writeD(0x18);
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
	pck->writeD(0);
	pck->writeD(0x3fcbd404);
	pck->writeD(1);
	pck->writeD(0x403b0640);
	pck->writeD(1);
	pck->writeD(0x3fcbaf54);
	pck->writeD(1);
	pck->writeD(0x3344f438);
	pck->writeD(1);
	pck->writeD(0x059a71d8);
	pck->writeD(1);	
	pck->writeBuf(tmp_area, 24);
	pck->writeD(0x3f000000);
	pck->writeD(1);
	pck->PackSend(OPCODE_SM_SETAREA);
}

/*
0000
00000000
C7722700
5400610068006F006D00610032000000
0000000000000000000000000000000000000000
00
00
05
01
00F51F310000000000000000030000007A020000000000000D0000000000000014CC3A44437627449E72D9410000B0421800000000000000000000000000000000000000000000000000000000000000000000000000000000000000
FFFFFFFF
00000000
00000000
C4C4343F
01000000
8047A43F
01000000
D49C343F
01000000
08A01E34
01000000
D8719A50
01000000
617265615F6630315F705F303030310000000000000000000000003F01000000

*/

#endif
