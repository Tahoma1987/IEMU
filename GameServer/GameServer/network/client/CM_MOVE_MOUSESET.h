////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_MOVE_MOUSESET_H_
#define _CM_MOVE_MOUSESET_H_

inline void CM_MOVE_MOUSESET(PACKET* pck)
{
	int8 action = pck->readB();				// 0 - идти / 1 - бежать
	int8 status = pck->readB();				// 0 - стоять / 1 - двигаться
	int8 unk1 = pck->readB();
	int8 unk2 = pck->readB();
	int32 unk3 = pck->readD();
	mychar->pos.pos_x = pck->readF();		// 759.582
	mychar->pos.pos_y = pck->readF();		// 898.307861
	mychar->pos.pos_z = pck->readF();		// 32.02
	mychar->pos.next_x = pck->readF();		// 765.3179
	mychar->pos.next_y = pck->readF();		// 890.116333
	mychar->pos.next_z = pck->readF();		// 32.02

	if (status == 1)
	{
		if (action == 0)
			mychar->action = ACTION_GO;
		else
			mychar->action = ACTION_RUN;
	}
	else
		mychar->action = ACTION_NONE;
}

/*
01
00
17
00
0d000000
379f4a44
7f844c44
3322f641
42e53d44
b4936044
2e1c0042


*/

#endif