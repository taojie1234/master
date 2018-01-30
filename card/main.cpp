#include <iostream>
#include "pack.h"
#include "player.h"
#include "common.h"

int compare1(Card* a, Card* b);

int main()
{
	Pack pa;
	Play pl;
	
	pa.initOnePack();
	
	Card** shuffledPokers = pa.shuffle();
	
	const int PLAYER_NUM = 3;
	Player player1;
	strcpy(player1.name, "张三");
	player1.cards = NULL;
	player1.cardsCount = 0;
	Player player2;
	strcpy(player2.name, "李四");
	player2.cards = NULL;
	player2.cardsCount = 0;
	Player player3;
	strcpy(player3.name, "王五");
	player3.cards = NULL;
	player3.cardsCount = 0;
	
	Player* players[] = {&player1, &player2, &player3};
	pl.dispatchCards(players, PLAYER_NUM, (const Card**)shuffledPokers);
	free(shuffledPokers);
	int i;
	for(i = 0; i < PLAYER_NUM; i++){
		printf("%s\n", players[i]->name);
		pa.sort(players[i]->cards, players[i]->cardsCount, compare1);
		int j;
		for(j = 0; j < players[i]->cardsCount; j++){
			char * name = pa.getCardName(players[i]->cards[j]);
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