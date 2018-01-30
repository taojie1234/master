#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "common.h"

class Pack
{	
public:
	//初始化一副牌
	void initOnePack();
	//洗牌
	Card** shuffle();
	char* getCardName(const Card* card);
	void sort(Card** cards, int cardsCount, COMPARE compare_func);
	
public:
	Card pokers[CARD_COUNT];
	
};