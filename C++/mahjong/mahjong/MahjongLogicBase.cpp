#include "MahjongLogicBase.h"

using namespace std;


//øÏÀŸ≈≈–Ú
void quickSort(vector<int> &iArray, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int piovt = iArray[left];
	int leftIndex = left;
	int rightIndex = right;

	while (leftIndex < rightIndex)
	{
		while (leftIndex < rightIndex)
		{
			if (piovt <= iArray[rightIndex])
			{
				rightIndex--;
			}
			else
			{
				iArray[leftIndex] = iArray[rightIndex];
				leftIndex++;
				break;
			}
		}

		while (leftIndex < rightIndex)
		{
			if (piovt >= iArray[leftIndex])
			{
				leftIndex++;
			}
			else
			{
				iArray[rightIndex] = iArray[leftIndex];
				rightIndex--;
				break;
			}
		}
	}
	iArray[leftIndex] = piovt;
	quickSort(iArray, left, leftIndex - 1);
	quickSort(iArray, rightIndex + 1, right);
}

MahjongLogicBase::MahjongLogicBase()
{

}
MahjongLogicBase::~MahjongLogicBase()
{

}

void MahjongLogicBase::sortCards(vector<int> &cards)
{
	//quickSort(cards, 0, cards.size() - 1);
	sort(cards.begin(), cards.end());
}

bool MahjongLogicBase::getCanHuByCards(vector<int> &cards)
{
	return true;
}

bool MahjongLogicBase::removeSameThree(vector<int> &cards)
{
	int size = cards.size();
	if (size < 3)
		return false;
	vector<int>::iterator it = cards.begin();
	for (int i = 0; i < size - 2; i++)
	{
		if (cards[i] == cards[i + 1] && cards[i + 1] == cards[i + 2])
		{
			cards.erase(cards.begin() + i + 2);
			cards.erase(cards.begin() + i + 1);
			cards.erase(cards.begin() + i);
			return true;
		}
	}
	return false;
}

bool MahjongLogicBase::removeStraightThree(vector<int> &cards)
{
	int size = cards.size();
	if (size < 3)
		return false;
	int ij;
	int ijk;
	int k = 1;
	for (int i = 0; i < size - 2; i++)
	{
		if (cards[i] <= 25 && cards[i] != 8 && cards[i] != 9 && cards[i] != 17 && cards[i] != 18)
		{
			for (int j = 1; j <= 4; ++j)
			{
				ij = i + j;
				if (ij < size && cards[ij] == cards[i] + 1)
				{
					ijk = ij + k;
					if (ijk < size && cards[ijk] == cards[ij] + 1)
					{
						cards.erase(cards.begin() + ijk);
						cards.erase(cards.begin() + ij);
						cards.erase(cards.begin() + i);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool MahjongLogicBase::check3n(vector<int> &cards)
{
	vector<int> tmpCards = cards;
	while (removeStraightThree(tmpCards))
	{
	}
	while (removeSameThree(tmpCards))
	{
	}
	if (tmpCards.empty())
	{
		return true;
	}

	tmpCards = cards;
	while (removeSameThree(tmpCards))
	{
	}
	while (removeStraightThree(tmpCards))
	{
	}
	if (tmpCards.empty())
	{
		return true;
	}

	return false;
}

bool MahjongLogicBase::checkIsSevenCouple(vector<int> &handCards)
{
	int size = handCards.size();
	if (size < 14)
	{
		return false;
	}
	else if (handCards[handCards.size() - 1] >= 32)
	{
		return false;
	}
	else
	{
		if (handCards[0] == handCards[1] &&
			handCards[2] == handCards[3] &&
			handCards[4] == handCards[5] &&
			handCards[6] == handCards[7] &&
			handCards[8] == handCards[9] &&
			handCards[10] == handCards[11] &&
			handCards[12] == handCards[13]
			)
		{
			return true;
		}
	}
	return false;
}

unsigned short MahjongLogicBase::getCrazyWindCount(vector<int> &handCards, vector<MJ_Choice> &frontCards)
{
	unsigned short windCount = 0;
	vector<MJ_Choice>::iterator iter = frontCards.begin();
	for (; iter != frontCards.end();)
	{
		if ((*iter).tile1 >= 28)
		{
			if ((*iter).type == 1)
			{
				windCount += 3;
			}
			else if ((*iter).type >= 2 && (*iter).type <= 4)
			{
				windCount += 4;
			}
			else
			{
				return 0;
			}
		}
		iter++;
	}
	vector<int>::iterator it = handCards.begin();
	for (; it != handCards.end();)
	{
		if ((*it) >= 28 && (*it) <= 34)
		{
			windCount += 1;
		}
		else
		{
			return 0;
		}
		it++;
	}
	return windCount;
}
