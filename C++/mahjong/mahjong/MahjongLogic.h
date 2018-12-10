#ifndef __MAHJONG_LOGIC_COMMON_H_
#define __MAHJONG_LOGIC_COMMON_H_

#include <algorithm>

typedef struct structChoice{
	int from;
	int tile1;
	int tile2;
	int tile3;
	int tile4;
	int type;
}MJ_Choice;

typedef struct shanghaiMJCan{
	bool canSeqTiao;
	bool canSeqTong;
	bool canSeqWan;
}SHMJ_CAN;


#endif