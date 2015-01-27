////////////////////////////////////////////////
// Authors: Tahoma, karyzirus
////////////////////////////////////////////////

#ifndef _SM_OBJECT_MOVE_H_
#define _SM_OBJECT_MOVE_H_

inline void SM_OBJECT_MOVE(PACKET* pck, int obj_id,
										int action_status,
										float pos_x,
										float pos_y,
										float pos_z,
										float next_pos_x,
										float next_pos_y,
										float next_pos_z)
{
	pck->CreateBufForSend();
	pck->writeD(0);
	pck->writeD(obj_id);
	pck->writeD(action_status);
	pck->writeF(pos_x);	// pos_x
	pck->writeF(pos_y);	// pos_y
	pck->writeF(pos_z);	// pos_z
	pck->writeF(next_pos_x);	// next_x
	pck->writeF(next_pos_y);	// next_y
	pck->writeF(next_pos_z);	// next_z
	pck->PackSend(OPCODE_SM_OBJECT_MOVE);
}
/*
1003 0000
00000000
7FA61A00
02000000
38323944
DE595244
D04BFC41
40F33844
FD8A5144
ED5AF841                           ..QD.Z.A
*/
#endif

