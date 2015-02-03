////////////////////////////////////////////////
// Authors: Tahoma
////////////////////////////////////////////////
#ifndef _SM_PLAYER_INFO_H_
#define _SM_PLAYER_INFO_H_

inline void SM_PLAYER_INFO(PACKET* pck, int char_id, float pos_x, float pos_y, float pos_z, float rotate, int lvl)
{
	pck->CreateBufForSend();
	pck->writeB(1);				// visible
	pck->writeB(0);
	pck->writeW(0);
	pck->writeD(char_id);
	pck->writeD(0);
	pck->writeF(pos_x);
	pck->writeF(pos_y);
	pck->writeF(pos_z);
	pck->writeF(rotate);
	pck->writeB(0);				// 1 sitdown, 2 angry, 0 stay
	pck->writeB(0);
	pck->writeB(0);

	pck->writeA("00010000000100000000000000");
	pck->writeW(lvl);				// lvl
	pck->writeA("00000000A040000010400000803F000070430000704300401C4600002F4300000000000000000000000000000000000000000000C84200007A440000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000400000005000000FFFFFFFFFF00000000000000F2F2F2FFF0FF1300FFFFFFFF0100004254006F006D006200C0C930AE0000000000000000000000000000000000000000000000000000000000000000000000006400010000000000FFFFFFFF00000000FFFFFFFF000000006500010000000000FFFFFFFF00000000FFFFFFFF00000000FFFFFFFF00000000FFFFFFFF00000000FFFFFFFF00000000C102000000000000FFFFFFFF000000000101010101010101010101C100000000FFFFFFFF0000000000000000000000000000000000000000000000000000000000000000000000000000000002000000FFFFFFFF000000000000000000000000030000000000000000000000");
	pck->PackSend(OPCODE_SM_PLAYER_INFO);
}
/*
        public override void Write(BinaryWriter writer)
        {
            const string femaleObjectStringId = "01";
            const string maleObjectStringId =   "0A";

            string sex = "";

            switch (Player.PlayerData.Sex)
            {
                case SexEnum.Male:
                    sex = maleObjectStringId;
                    break;
                case SexEnum.Female:
                    sex = femaleObjectStringId;
                    break;
            }
          
            WriteH(writer, 1); //unk 01 spawn 00 no spawn
            WriteH(writer, 0);
            WriteD(writer, Player.UID);
            WriteD(writer, 0); 
          
            WriteF(writer, SpawnedPos.X);
            WriteF(writer, SpawnedPos.Y);
            WriteF(writer, SpawnedPos.Z);
            WriteF(writer, SpawnedPos.Heading); 
        
            WriteC(writer, 0);
            WriteB(writer, "0000"); // 1 sitdown, 2 angry, 0 stay (Change first char! "1000", "2000", "0000")
            WriteB(writer, "00010000000100000000000000");
            WriteH(writer, (short) Player.PlayerData.Level);
            WriteB(writer, new byte[16]); //B840333313403333933F

            WriteB(writer, "61430000");
            WriteB(writer, "61430000");
            WriteB(writer, "E1430000");
            WriteB(writer, "E1430000");
            WriteD(writer, 0);
            WriteD(writer, 0);
            WriteB(writer, new byte[16]);
            WriteD(writer, 0);
            WriteB(writer, new byte[264]);
            WriteH(writer, 0);
            WriteH(writer, 3);
            WriteD(writer, 0);

            WriteH(writer, 0);
            WriteH(writer, 1);
            WriteH(writer, 0);
            WriteH(writer, 5);
            WriteH(writer, 0);

            WriteB(writer, "FC040580");
            WriteB(writer, "FF000000");
            WriteD(writer, 0);

            WriteB(writer, "00000000");
            WriteB(writer, "05001400");
            WriteB(writer, "000000FF");
            WriteC(writer, 1);

            WriteC(writer, Player.PlayerData.ClassType);
            WriteB(writer, sex);
            WriteC(writer, 0); 
            WriteB(writer, CharName);
            WriteB(writer, new byte[24]);

            #region Armor
            if (Player.PlayerData.Storage != null)
                WriteD(writer, Player.PlayerData.Storage.Storage != null ? Player.PlayerData.Storage.Storage.First(s => s.Slot == 1).ItemId : 0x00010064);
            else if (Player.PlayerData.Storage == null)
                WriteD(writer, 0x00010064);

            WriteD(writer, 0);
            #endregion

            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Foot
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Unk
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //Weapon
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //??
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //??
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //??
            WriteD(writer, 0);
            WriteD(writer, 0xFFFFFFFF);  //??
            WriteD(writer, 0);

            WriteB(writer, new byte[32]);
            WriteD(writer, 0);
            WriteD(writer, 2);

            WriteD(writer, 0xFFFFFFFF);  //??
            WriteD(writer, 0);

            WriteD(writer, 0);
            WriteD(writer, 0);

            WriteD(writer, 3);
            WriteD(writer, 0);
            WriteD(writer, 0);
        }
    }
}

1017 0000
01000000
0EE70180
006D7140   .............mq@
2DFB4A44
DBA55744
F7A8C341 0x41c3a8f7
00000943
00 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00   ................
02 00 00 00 00 00 A0 40 00 00 00 40 00 00 80 3F   .......@...@...?
00 00 B9 43 00 00 B9 43 00 00 7A 43 00 00 7A 43   ...C...C..zC..zC
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 7A 44 00 00 00 00   ..........zD....
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 0A 00 00 00 00 00 00 00   ................
01 00 00 00 05 00 00 00 FF FF FF FF FF 00 00 00   ................
00 00 00 00 E1 E1 E1 FF F1 FF 13 00 FF FF FF FF   ................
01 05 00 42 EC C5 38 AE 2C AF 00 00 00 00 00 00   ...B..8.,.......
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 01 00 00 62 00 01 00 00 00 00 00 FF FF FF FF   ....b...........
00 00 00 00 FF FF FF FF 00 00 00 00 63 00 01 00   ............c...
00 00 00 00 FF FF FF FF 00 00 00 00 FF FF FF FF   ................
00 00 00 00 FF FF FF FF 00 00 00 00 FF FF FF FF   ................
00 00 00 00 FF FF FF FF 00 00 00 00 BD 02 00 00   ................
00 00 00 00 22 00 02 00 00 00 00 00 C1 00 00 00   ...."...........
FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
00 00 00 00 00 00 00 00 00 00 00 00 02 00 00 00   ................
FF FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00   ................
03 00 00 00 00 00 00 00 00 00 00 00               ............
*/
#endif

