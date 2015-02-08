////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////

#ifndef _CM_SKILLS_PANEL_MOVE_H_
#define _CM_USE_H_

inline void CM_SKILLS_PANEL_MOVE(PACKET* pck)
{
	bool complate = false;
	int32 active = pck->readD();		// 0 -destroy, 1 - move
	int16 num_panel = pck->readW();
	int8 slot = pck->readB();
	int8 unk1 = pck->readB();
	int32 unk2 = pck->readD();
	int32 skill_id = pck->readD();
	int32 unk3 = pck->readD();

	if (active == 0)
	{
		for (int i = 0; i < _MAX_SKILLS_PANEL_SLOTS; i++)
		{
			if (mychar->skills_panel[i].num_panel == num_panel &&
				mychar->skills_panel[i].slot == slot &&
				mychar->skills_panel[i].skill_id == skill_id)
			{
				mychar->skills_panel[i].active = 0;
				complate = true;
				break;
			}
		}

		if (!complate)
		{
			lg::Error(fg, "Anti")
		}
	}
	else
	{
		for (int i = 0; i < _MAX_SKILLS_PANEL_SLOTS; i++)
		{
			if (mychar->skills_panel[i].active == 0)
			{
				mychar->skills_panel[i].active = active;
				mychar->skills_panel[i].num_panel = num_panel;
				mychar->skills_panel[i].slot = slot;
				mychar->skills_panel[i].unk1 = unk1;
				mychar->skills_panel[i].unk2 = unk2;
				mychar->skills_panel[i].skill_id = skill_id;
				mychar->skills_panel[i].unk3 = unk3;
				mychar->skills_panel[i].unk4 = unk4;
				complate = true;
				break;
			}
		}
	}

}

/*
01000000
0000
0700
ffffffff
3b000200
ffffffff
00009e09
*/
#endif