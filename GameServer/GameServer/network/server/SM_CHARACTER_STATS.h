////////////////////////////////////////////////
// Authors: Tahoma, Karyzirus, Trixiejack
////////////////////////////////////////////////
#ifndef _SM_CHARACTER_STATS_H_
#define _SM_CHARACTER_STATS_H_

inline void SM_CHARACTER_STATS(PACKET* pck)
{
	pck->CreateBufForSend();
//	pck->writeA("0000643D0980000000000000000000AAA340CDCC92429A995542000000000000000000001041000010415C0FCE425C0FA4425A54773FC518793FEC51B83E1B2F5D3DCD4CC64200000000856BC642000000007B14AE3F00000000713D0A3F000040410000004100001041000040410000404100004040000040400000DE430000964300000000000000000000000000000000000000000000C84200007A4400007A4400007A4400007A440000A040000000400000803F0000803F0000000000007A440000984100006041F1F0F03DF1F0F03D986E923F1A2F5D3E000000410000404100004042000000000000000000000000000000000000000000000000000000000000000000000000000000000000DE430000964300000000000000000000000000007A44000000000000C84200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000001000000000000000B000000FFFFFFFF0100000000000000");
//	pck->PackSend(OPCODE_SM_ENTER_WORLD);
//	return;
	pck->writeD(pck->me->id); // character id
//	pck->writeA("000000000000000000AAA340CDCC92429A995542000000000000000000001041000010415C0FCE425C0FA4425A54773FC518793FEC51B83E1B2F5D3DCD4CC64200000000856BC642000000007B14AE3F00000000713D0A3F000040410000004100001041000040410000404100004040000040400000DE430000964300000000000000000000000000000000000000000000C84200007A4400007A4400007A4400007A440000A040000000400000803F0000803F0000000000007A440000984100006041F1F0F03DF1F0F03D986E923F1A2F5D3E000000410000404100004042000000000000000000000000000000000000000000000000000000000000000000000000000000000000DE430000964300000000000000000000000000007A44000000000000C84200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000001000000000000000B000000FFFFFFFF0100000000000000");
//	pck->PackSend(OPCODE_SM_ENTER_WORLD);
//	return;
	pck->writeD(0);				// 888
	pck->writeD(0);				// 889
	pck->writeD(0);				// 890
	pck->writeD(0x42893333);	//1
	pck->writeD(0x42426666);	//2
	pck->writeD(0);				//3
	pck->writeD(0);				//4
	pck->writeD(0x50e00000);	//5
	pck->writeD(0x40e00000);	//6
	pck->writeD(0x42ce0a3d);	//7		phys def
	pck->writeD(0x42a40a3d);	//8		magic def
	pck->writeD(0x3f77357e);	//9
	pck->writeD(0x3f79003f);	//10
	pck->writeD(0x3da5e355);	//11	evasion
	pck->writeD(0x3d1374bd);	//12
	pck->writeD(0x42c63d71);	//13	accuracy (прицел)
	pck->writeD(0);				//14
	pck->writeD(0x42c64c71);	//15
	pck->writeD(0);				//16
	pck->writeD(0x3fa28f5c);	//17	phys crit rate
	pck->writeD(0);				//18
	pck->writeD(0x3eb851ec);	//19
	pck->writeD(0x41000000);	//20	power
	pck->writeD(0x40c00000);	//21	agility
	pck->writeD(0x40e00000);	//22	intelligence
	pck->writeD(0x41000000);	//23	fitness
	pck->writeD(0x41000000);	//24	mentality
	pck->writeD(0x40000000);	//25
	pck->writeD(0x40000000);	//26
	pck->writeD(0x45710000);	//27	max_hp
	pck->writeD(0x45700000);	//28	max_mp
	pck->writeD(0);				//29
	pck->writeD(0);				//30
	pck->writeD(0);				//31
	pck->writeD(0);				//32
	pck->writeD(0);				//33
	pck->writeD(0x42c80000);	//34	хер значет (де плюсик стоит) max
	pck->writeD(0x447a0000);	//35
	pck->writeD(0x447a0000);	//36
	pck->writeD(0x447a0000);	//37
	pck->writeD(0x447a0000);	//38
	pck->writeD(0x40a00000);	//39
	pck->writeD(0x40000000);	//40
	pck->writeD(0x3f800000);	//41
	pck->writeD(0x3f800000);	//42
	pck->writeD(0);				//43
	pck->writeD(0x447a0000);	//44
	pck->writeD(0x41700000);	//45
	pck->writeD(0x41200000);	//46
	pck->writeD(0x3da0a0a1);	//47
	pck->writeD(0x3da0a0a1);	//48
	pck->writeD(0x3f8dd2f2);	//49		два меча
	pck->writeD(0x3e1374bc);	//50		phys crit
	pck->writeD(0x40c00000);	//51		phys crit
	pck->writeD(0x41000000);	//52
	pck->writeD(0x42000000);	//53		щит с тремя пупурышками
	pck->writeD(0);				//54
	pck->writeD(0);				//55
	pck->writeD(0);				//56
	pck->writeD(0);				//57
	pck->writeD(0);				//58
	pck->writeD(0);				//59
	pck->writeD(0);				//60
	pck->writeD(0);				//61
	pck->writeD(0);				//62
	pck->writeD(0);				//63
	pck->writeD(0x45100000);	//64		hp
	pck->writeD(0x45200000);	//65		mp
	pck->writeD(0);				//66
	pck->writeD(0);				//67
	pck->writeD(0);				//68
	pck->writeD(0x447a0000);	//69
	pck->writeD(0);				//70
	pck->writeD(0x42c80000);	//71		хер значет (де плюсик стоит) 
	pck->writeD(0);				//72
	pck->writeD(0);				//73
	pck->writeD(0);				//74
	pck->writeD(0);				//75
	pck->writeD(0);				//76
	pck->writeD(0);				//77
	pck->writeD(0);				//78
	pck->writeD(0);				//79
	pck->writeD(0);				//80
	pck->writeD(0);				//81	
	pck->writeD(0);				//82
	pck->writeD(0);				//83
	pck->writeD(0);				//84
	pck->writeD(0);				//85
	pck->writeD(1);	
	pck->writeD(1);
	pck->writeD(0);
	pck->writeD(0xb);
	pck->writeD(0xffffffff);
	pck->writeD(1);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_CHARACTER_STATS);
}

#endif


