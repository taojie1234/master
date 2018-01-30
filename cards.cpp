#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//using namespace std;



enum Suit{
	heart,
	spade,
	diamond,
	club,
	joker1,
	joker2
};

typedef struct Card{
	int value;
	enum Suit suit;
}Card;

typedef struct Player{
	char name[64];
	Card ** cards;
	int cardsCount;
}Player;

typedef int (*COMPARE)(Card*, Card*);

Card pokers[CARD_COUNT];

void initOnePack()
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

Card** shuffle(const Card* pokers)
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

void dispatchCards(Player** players, int playerCount, const Card** shuffleCards)
{
	int numberCards = CARD_COUNT/playerCount + 1;
	int i;
	for(i = 0; i < playerCount; i++){
		Card** cards = (Card**)malloc(numberCards*sizeof(Card*));
		players[i]->cards = cards;
	}
	for(i = 0; i < CARD_COUNT; i++){
		Player *curPlayer = players[i%playerCount];
		curPlayer->cards[curPlayer->cardsCount] = (Card*)shuffleCards[i];
		curPlayer->cardsCount++;
	}
}

void sort(Card** cards, int cardsCount, COMPARE compare_func)
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

int compare1(Card* a, Card* b)
{
	if(a->value > b->value){
		return 1;
	}else if(a->value < b->value){
		return 0;
	}else{
		if(a->suit > b->suit){
			return 1;
		}else{
			return 0;
		}
	}
}

char* getCardName(const Card* card)
{
	char suitStr[16] = {0};
	switch(card->suit){
	case heart:
		strcpy(suitStr, "????");
		break;
	case spade:
		strcpy(suitStr, "????");
		break;
	case diamond:
		strcpy(suitStr, "???");
		break;
	case club:
		strcpy(suitStr, "????");
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
        strcpy(valueStr,"????");
        break;
    case 15:
        strcpy(valueStr,"????");
        break;
    default:
        sprintf(valueStr,"%d",card->value);
        break;
    }
	char* ret = (char*)malloc(16);
	sprintf(ret, "%s%s", suitStr, valueStr);
	return ret;
}

int main()
{
	initOnePack();
	
	Card** shuffledPokers = shuffle(pokers);
	
	const int PLAYER_NUM = 3;
	Player player1;
	strcpy(player1.name, "????");
	player1.cards = NULL;
	player1.cardsCount = 0;
	Player player2;
	strcpy(player2.name, "????");
	player2.cards = NULL;
	player2.cardsCount = 0;
	Player player3;
	strcpy(player3.name, "????");
	player3.cards = NULL;
	player3.cardsCount = 0;
	
	Player* players[] = {&player1, &player2, &player3};
	dispatchCards(players, PLAYER_NUM, (const Card**)shuffledPokers);
	free(shuffledPokers);
	int i;
	for(i = 0; i < PLAYER_NUM; i++){
		printf("%s\n", players[i]->name);
		sort(players[i]->cards, players[i]->cardsCount, compare1);
		int j;
		for(j = 0; j < players[i]->cardsCount; j++){
			char * name = getCardName(players[i]->cards[j]);
			printf("%s ", name);
			free(name);
		}
		printf("\n");
	}
	for(i = 0; i < PLAYER_NUM; i++){
		free(players[i]->cards);
	}
	return 0;
}
