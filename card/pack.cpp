#include "pack.h"

void Pack::initOnePack()
{
	int i;
	for(i = 0; i < CARD_COUNT - 2; i++){
		pokers[i].value = i/4+1;
		pokers[i].suit = Suit(i%4);
	}
	pokers[i].value = i/4+1;
	pokers[i].suit = joker1;
	
	pokers[i+1].value = i/4+2;
	pokers[i+1].suit = joker2;
}

Card** Pack::shuffle()
{
	int i;
	Card** retPokers = (Card**)malloc(CARD_COUNT*sizeof(Card*));
	Card** pokers2 = (Card**)malloc(CARD_COUNT*sizeof(Card*));
	
	for(i = 0; i < CARD_COUNT; i++){
		pokers2[i] = (Card*)&pokers[i];
	}
	
	srand(time(NULL));
	for(i = 0; i < CARD_COUNT; i++){
		unsigned int index = rand()%CARD_COUNT;
		if(pokers2[index] != NULL){
			retPokers[i] = pokers2[index];
			pokers2[index] = NULL;
		} else {
			i--;
		}
	}
	free(pokers2);
	return retPokers;
}

char* Pack::getCardName(const Card* card)
{
	char suitStr[16] = {0};
	switch(card->suit){
	case heart:
		strcpy(suitStr, "红");
		break;
	case spade:
		strcpy(suitStr, "黑");
		break;
	case diamond:
		strcpy(suitStr, "方");
		break;
	case club:
		strcpy(suitStr, "梅");
		break;
	}
	
	char valueStr[16];
	switch(card->value){
	case 1:
		strcpy(valueStr, "A");
		break;
	case 11:
        strcpy(valueStr,"J");
        break;
    case 12:
        strcpy(valueStr,"Q");
        break;
    case 13:
        strcpy(valueStr,"K");
        break;
    case 14:
        strcpy(valueStr,"小王");
        break;
    case 15:
        strcpy(valueStr,"大王");
        break;
    default:
        sprintf(valueStr,"%d",card->value);
        break;
    }
	char* ret = (char*)malloc(16);
	sprintf(ret, "%s%s", suitStr, valueStr);
	return ret;
}

void Pack::sort(Card** cards, int cardsCount, COMPARE compare_func)
{
	int i;
	for(i = 0; i < cardsCount-1; i++){
		int j;
		for(j = 0; j < cardsCount-i-1; j++){
			if(compare_func(cards[j], cards[j+1])){
				Card *tmp = cards[j];
				cards[j] = cards[j+1];
				cards[j+1] = tmp;
			}
		}
	}
				
}
