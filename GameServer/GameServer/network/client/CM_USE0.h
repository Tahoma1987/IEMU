////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _CM_USE0_H_
#define _CM_USE0_H_

inline void CM_USE0(PACKET* pck)
{
	mychar->target_id = pck->readD();
	SM_USE0(pck, mychar->target_id);
	SM_UNK_690f(pck, mychar->target_id);

	mychar->action = ACTION_MINING;
}

#endif