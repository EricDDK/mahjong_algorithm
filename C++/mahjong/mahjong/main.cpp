#include "iostream"
#include <vector>
#include "MahjongLogicBase.h"

class Test
{
public:
	Test();
	~Test();
	vector<int> getCanTing(vector<int> &handCards);
	bool getCanHu(vector<int> &handCards);
private:

};

Test::Test()
{

}

Test::~Test()
{

}

//�������ƿ�����������������Ϳ��Ժ���Ҳ����
vector<int> Test::getCanTing(vector<int> &handCards)
{
	vector<int> result = { 0 };
	MahjongLogicBase* logic = new MahjongLogicBase;
	vector<int> myCards = { 0 };
	bool needAdd = ((handCards.size() - 1) % 3 == 0) ? true : false;
	//1 - 9 10 - 18 19 - 27 28 - 31��  32 - 34��  35 - 42��
	for (size_t i = 1; i <= 34; i++)
	{
		myCards = handCards;
		if (needAdd)
		{
			myCards.insert(myCards.end(), i);
		}
		//��ʼ�ж�
		if (getCanHu(myCards))
		{
			result.insert(result.end(), i);
		}
	}
	return result;
	delete logic;
}

bool Test::getCanHu(vector<int> &handCards)
{
	MahjongLogicBase* logic = new MahjongLogicBase;
	logic->sortCards(handCards);
	if (*(handCards.end() - 1) >= 35) //���ֻ��ͺ�����
	{
		delete logic;
		return false;
	}
	int size = handCards.size();
	vector<int> cards = { 0 };
	for (int i = 0; i < size - 1; i++)
	{
		if (handCards[i] == handCards[i + 1])
		{
			//��ȥ��һ������
			cards = handCards;
			cards.erase(cards.begin() + i + 1);
			cards.erase(cards.begin() + i);
			if (cards.empty() || logic->check3n(cards))
			{
				delete logic;
				return true;
			}
		}
	}
	delete logic;
	return false;
}

//main function
int main()
{
	//���Դ���
	//1 - 9 10 - 18 19 - 27 28 - 31��  32 - 34��  35 - 42��
	Test* test = new Test;
	vector<int> inputs = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5 };
	bool canhu = test->getCanHu(inputs);
	vector<int> tingVector = test->getCanTing(inputs);
	delete test;
	system("pause");
	return 0;
}

