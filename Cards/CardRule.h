#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class CardRule : CardUtil
{
public:
	bool isDan(vector<Card> myCards) ;
	bool isDuiZi(vector<Card> myCards) ;
	int isSanDaiYi(vector<Card> myCards) ;
	bool isSanBuDai(vector<Card> myCards) ;
};