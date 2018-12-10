#ifndef __MAHJONG_BASE_LOGIC_H_
#define __MAHJONG_BASE_LOGIC_H_

#include "MahjongLogic.h"
#include <vector>

using namespace std;


class MahjongLogicBase
{
public:

	MahjongLogicBase();
	~MahjongLogicBase();

	/**
	*排序一副牌
	*/
	void sortCards(vector<int> &cards);

	/**
	*是否可以胡
	*/
	virtual bool getCanHuByCards(vector<int> &cards);

	/**
	*寻找三个相同的的牌，也就是DDD的牌型
	*/
	virtual bool removeSameThree(vector<int> &cards);

	/**
	*寻找三张连续的牌，ABC类型的
	*/
	virtual bool removeStraightThree(vector<int> &cards);

	/**
	*检测是否是ABC DDD的牌型，是就胡，不是就不胡
	*/
	virtual bool check3n(vector<int> &cards);

	/**
	*检测是否是七小对
	*/
	virtual bool checkIsSevenCouple(vector<int> &handCards);

	/**
	*获取乱风向的张数(东南西北中发白的总张数)，包括吃碰杠碰牌型
	*/
	virtual unsigned short getCrazyWindCount(vector<int> &handCards, vector<MJ_Choice> &frontCards);

protected:

private:


};

#endif 