#ifndef _COMMON_H_
#define _COMMON_H_ 

#define CARD_COUNT 54

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

#endif