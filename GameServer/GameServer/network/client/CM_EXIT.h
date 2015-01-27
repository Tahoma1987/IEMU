////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_EXIT_H_
#define _CM_EXIT_H_

inline void CM_EXIT(PACKET* pck)
{
	int8 action = pck->readB();

	SM_EXIT(pck);
	if (action == 1)
	{
		SM_CHANGE_CHARACTER(pck, action);
	}
	
}

#endif