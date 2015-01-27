////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#include "ActionController.h"

ACTIONCONTROLLER::ACTIONCONTROLLER(FILE* fg, DATABASE* mysql, ALL_PLAYERS* players, MOB* mobs, int max_players, int max_spawns)
{
	this->fg = fg;
	this->players = players;
	this->max_players = max_players;
	this->max_spawns = max_spawns;
	this->mobs = mobs;
}

ACTIONCONTROLLER::~ACTIONCONTROLLER()
{

}

//================================================================================
// Основной цикл действий всех субъектов
//
void ACTIONCONTROLLER::Frame()
{
	Obj_Actions();
}

//================================================================================
// Проверяет всех мобов и задает им действия
//
void ACTIONCONTROLLER::Obj_Actions()
{
	int rnd;

	for (int i = 0; i < max_spawns; i++)
	{
		switch (mobs[i].move)
		{
		case OBJMOVE_NOT_MOVE:
			break;

		case OBJMOVE_RANDOM:
			if (mobs[i].action_status == OBJ_ACTION_STAND || mobs[i].action_status == OBJ_ACTION_MOVE)
			{
				srand(GetTickCount());
				rnd = rand() % 100;
				if (rnd < 20)
				{
					srand(GetTickCount());
					mobs[i].action_status = OBJ_ACTION_MOVE;
					rnd = rand();
					if (rnd % 2)
					{
						srand(GetTickCount());
						rnd = rand() % mobs[i].move_distance;
						if (rnd % 3)
						{
							mobs[i].next_pos_x = mobs[i].base_pos_y + rnd;

						}
						else
						{
							mobs[i].next_pos_x = mobs[i].base_pos_y - rnd;

						}
					}
					srand(GetTickCount());
					rnd = rand();
					if (rnd % 2)
					{
						srand(GetTickCount());
						rnd = rand() % mobs[i].move_distance;
						if (rnd % 3)
						{
							mobs[i].next_pos_y = mobs[i].base_pos_y + rnd;

						}
						else
						{
							mobs[i].next_pos_y = mobs[i].base_pos_y - rnd;

						}
					}
				}
				else
				{
					mobs[i].action_status = OBJ_ACTION_STAND;
					mobs[i].pos_x = mobs[i].base_pos_x;
					mobs[i].pos_y = mobs[i].base_pos_y;
					mobs[i].pos_z = mobs[i].base_pos_z;
				}
				//				_GET_DISTANCE(dist, mobs[i].pos_x, mobs[i].move_distance,
				//									mobs[i].pos_y, mobs[i].move_distance,
				//									mobs[i].pos_z, mobs[i].move_distance);


			}
			break;

		case OBJMOVE_POINTS:
			break;

		}
	}
}