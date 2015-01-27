////////////////////////////////////////////////
// Authors: Tahoma, karyzirus
////////////////////////////////////////////////
#ifndef _SM_MOVE_H_
#define _SM_MOVE_H_

inline void SM_MOVE(PACKET* pck)
{
	int8 action = 0;
	int8 status = 0;
	if (mychar->action == ACTION_GO)
	{
		status = 1;
	}
	else if (mychar->action == ACTION_RUN)
	{
		status = 1;
		action = 1;
	}
	pck->CreateBufForSend();
	pck->writeB(status);
	pck->writeB(action);
	pck->writeB(0);
	pck->writeB(0);
	pck->writeD(mychar->id);
	pck->writeF(mychar->pos.pos_x);			// pos_x
	pck->writeF(mychar->pos.pos_y);			// pos_y
	pck->writeF(mychar->pos.pos_z);			// pos_z
	pck->writeF(mychar->pos.next_x);		// next_x
	pck->writeF(mychar->pos.next_y);		// next_y
	pck->writeF(mychar->pos.next_z);		// next_z
	pck->PackSend(OPCODE_SM_MOVE);
}
/*
1000 0000
01010088
CB010980
FC104843  pos_x
078E5944  pos_y
18D7C442  pos_z
00003F43
00805844   ..YD...B..?C..XD
18D7C442
744F91BF
00000000               ...BtO......
*/
#endif

