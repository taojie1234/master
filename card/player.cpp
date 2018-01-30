#include "player.h"

void Play::dispatchCards(Player** players, int playerCount, const Card** shuffleCards)
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