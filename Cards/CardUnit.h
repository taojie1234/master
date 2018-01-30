#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class CardUnit
{
public:
	int getGrade(int id) ;
	bool bubbleSortCards(vector<Card> cards) ;
	void sortCards(vector<Card> cards) ;
};