////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#include "ai.h"

AI::AI(FILE* fg, DATABASE* mysql, ALL_PLAYERS* allplayers, MOB* mobs, int max_players, int max_spawns)
{
	this->fg = fg;
	this->mysql = mysql;
	this->players = allplayers;
	this->max_players = max_players;
	this->max_spawns = max_spawns;
	this->mobs = mobs;
}

AI::~AI()
{

}

void AI::SpawnObjects(int num_player)
{
	float dist;
	PACKET* pck = (PACKET*)players[num_player].pck;

	if (!pck->me->ingame)
		return;

	for (int i = 0; i < max_spawns; i++)
	{
		if (!mobs[i].accounts_show[num_player])
		{
//				_GET_DISTANCE(dist, pck->me->pos_x, mobs[i].pos_x, pck->me->pos_y, mobs[i].pos_y, pck->me->pos_z, pck->me->pos_z);
			dist = sqrt((mychar->pos.pos_x - mobs[i].pos_x) * (mychar->pos.pos_x - mobs[i].pos_x) +
				(mychar->pos.pos_y - mobs[i].pos_y) * (mychar->pos.pos_y - mobs[i].pos_y) +
				(mychar->pos.pos_z - mobs[i].pos_z) * (mychar->pos.pos_z - mobs[i].pos_z));

			if (dist <= 60)
			{
				// spawn
				mobs[i].accounts_show[num_player] = true;
				SM_GAMEOBJECT_SPAWN(pck, mobs[i]);
			}
		}
			/*else
			{
				_GET_DISTANCE(dist, pck->me->pos_x, mobs[i].pos_x, pck->me->pos_y, mobs[i].pos_y, pck->me->pos_z, pck->me->pos_z);
				if (dist <= 60)
				{
					SM_OBJECT_MOVE(pck, mobs[i].uid, mobs[i].action_status,
						mobs[i].pos_x,
						mobs[i].pos_y,
						mobs[i].pos_z,
						mobs[i].next_pos_x,
						mobs[i].next_pos_y,
						mobs[i].next_pos_z);
				}
			}*/
	}	
}

//================================================================================
// Обработчик основного цикла нити
//
void AI::Frame()
{
	for (int num_player = 0; num_player < max_players; ++num_player)
	{		
		PACKET* pck = (PACKET*)players[num_player].pck;
		if (players[num_player].status == true && players[num_player].socket != NULL && players[num_player].pck != NULL)
		{
			EnterCriticalSection(&players[num_player].gCSp);
			if (mychar->status == STATUS_NONE)
				mychar->status = STATUS_GETINFO;

			StatusHandler(num_player);
			SpawnObjects(num_player);

			mychar->status = STATUS_NONE;
			LeaveCriticalSection(&players[num_player].gCSp);			
		}		
	}
}

//================================================================================
// Обработка помещения вещи в инвентарь
//
void AI::PlayerGetItem(int num_player, int item_id)
{
	bool slots[8 * 24 + 1];
	uint32 PlayerItemUID = 0;
	int16 sid = 0;
	memset(slots, false, sizeof(slots));

	PACKET* pck = (PACKET*)players[num_player].pck;

	for (int i = 0; i < mychar->items_in_inventory; i++)
	{
		if (mychar->inventory[i].equip == 0)
			slots[mychar->inventory[i].slot] = true;
		if (PlayerItemUID < mychar->inventory[i].PlayerItemUID)
			PlayerItemUID = mychar->inventory[i].PlayerItemUID;
		if (sid < mychar->inventory[i].sid)
			sid = mychar->inventory[i].sid;
	}
	++PlayerItemUID;
	++sid;

	for (int i = 0; i < sizeof(slots); i++)
	{
		if (slots[i] == false)
		{	
			
			mychar->inventory[pck->me->items_in_inventory].count = 1;
			mychar->inventory[mychar->items_in_inventory].equip = 0;
			mychar->inventory[mychar->items_in_inventory].item_id = item_id;
			mychar->inventory[mychar->items_in_inventory].slot = i;
			mychar->inventory[mychar->items_in_inventory].sid = sid;
			mychar->inventory[mychar->items_in_inventory].PlayerItemUID = PlayerItemUID;	
			++mychar->items_in_inventory;
			SM_INVENTORY_RESPONSE(pck);			
			break;
		}
	}

}

//================================================================================
// Проверяем на ввод команды GM'а
//
char* AI::GMCommandsGetOffset(char* str, char* command)
{
	char* next_offset = NULL;
	if ((next_offset = strstr(str, command)) != NULL)
	{
		next_offset += strlen(command) + 1;
		return next_offset;
	}
	return NULL;
}

bool AI::GMCommands(int num_player)
{
	char* next_offset;
	char* next_offset2;
	PACKET* pck = (PACKET*)players[num_player].pck;
	if (mychar->chat_msg[0] != '\\')
		return false;

	if ((next_offset = GMCommandsGetOffset(mychar->chat_msg, "give_me_item")) != NULL)
	{
		if ((next_offset - mychar->chat_msg ) < 1)
		{
			SM_CHAT(pck, "give_me_item [item id]");			
		}
		else
		{
			int item_id = atoi(next_offset);
			if (item_id == 0)
			{
				SM_CHAT(pck, "item id < 1");
			}
			else
			{
				PlayerGetItem(num_player, item_id);
			}
		}
		return true;
	}
	return false;
}

//================================================================================
// Обработчик статусов игроков
//
void AI::StatusHandler(int num_player)
{
	PACKET* pck = (PACKET*)players[num_player].pck;

	switch (players[num_player].character.status)
	{
	case STATUS_NONE:
		break;

	case STATUS_CONNECT:
		lg::Info(fg, "GSNetwork [%s]: Connect character: %s\n", inet_ntoa(players[num_player].from), pck->me->tcharname);
		SM_UNK1(pck);
		SM_CONNECT(pck);

		for (int i = 0; i < max_spawns; i++)
		{
			if (mobs[i].accounts_show[num_player])
				mobs[i].accounts_show[num_player] = false;
		}
		break;

	case STATUS_SM_UNK3:
		SM_UNK3(pck, 0);
		SM_UNK3(pck, 12);
		SM_UNK3(pck, 19);
		SM_UNK3(pck, 15);
		SM_UNK3(pck, 12);
		SM_UNK3(pck, 11);
		SM_UNK4(pck);
		break;

	case STATUS_DISCONNECT:		
		mysql->UpdateCharacterInfo(&players[num_player].character);
		mychar->pos.pos_x = 0;
		mychar->pos.pos_y = 0;
		mychar->pos.pos_z = 0;
		break;

	case STATUS_CHAT:
		// тут делаем отправку сообщения всем игрокам в радиусе 60м
		if (mychar->access != ACCESS_CHARACTER_PLAYER)
		{
			if (GMCommands(num_player))
				break;
		}
		SM_CHAT(pck, mychar->chat_msg);
		break;
	}	
}