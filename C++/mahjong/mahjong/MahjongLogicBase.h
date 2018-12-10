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
	*����һ����
	*/
	void sortCards(vector<int> &cards);

	/**
	*�Ƿ���Ժ�
	*/
	virtual bool getCanHuByCards(vector<int> &cards);

	/**
	*Ѱ��������ͬ�ĵ��ƣ�Ҳ����DDD������
	*/
	virtual bool removeSameThree(vector<int> &cards);

	/**
	*Ѱ�������������ƣ�ABC���͵�
	*/
	virtual bool removeStraightThree(vector<int> &cards);

	/**
	*����Ƿ���ABC DDD�����ͣ��Ǿͺ������ǾͲ���
	*/
	virtual bool check3n(vector<int> &cards);

	/**
	*����Ƿ�����С��
	*/
	virtual bool checkIsSevenCouple(vector<int> &handCards);

	/**
	*��ȡ�ҷ��������(���������з��׵�������)������������������
	*/
	virtual unsigned short getCrazyWindCount(vector<int> &handCards, vector<MJ_Choice> &frontCards);

protected:

private:


};

#endif 