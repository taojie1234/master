#include "CardUnit.h"

int CardUnit::getGrade(int id) 
{   
   if (id < 1 || id > 54) {  
	   printf("牌的数字不合法");  
   }   

   int grade = 0;   

   // 2个王必须放在前边判断  
   if (id == 53) {  
	   grade = 16;  
   } else if (id == 54) {  
	   grade = 17;  
   } else {  
	   int modResult = id % 13;   

	   if (modResult == 1) {  
		   grade = 14;  
	   } else if (modResult == 2) {  
		   grade = 15;  
	   } else if (modResult == 3) {  
		   grade = 3;  
	   } else if (modResult == 4) {  
		   grade = 4;  
	   } else if (modResult == 5) {  
		   grade = 5;  
	   } else if (modResult == 6) {  
		   grade = 6;  
	   } else if (modResult == 7) {  
		   grade = 7;  
	   } else if (modResult == 8) {  
		   grade = 8;  
	   } else if (modResult == 9) {  
		   grade = 9;  
	   } else if (modResult == 10) {  
		   grade = 10;  
	   } else if (modResult == 11) {  
		   grade = 11;  
	   } else if (modResult == 12) {  
		   grade = 12;  
	   } else if (modResult == 0) {  
		   grade = 13;  
	   }   

   }   

   return grade;  
}

bool CardUnit::bubbleSortCards(vector<Card> cards) 
{  
	if (cards.empty()) {  
		return false;  
	}   

	int size = cards.size();  
	// 冒泡排序,从左到右，从小到大  
	for (int i = 0; i < size; i++) {  
		for (int j = 0; j < size – i – 1; j++) {  
			int gradeOne = cards.get(j).grade;  
			int gradeTwo = cards.get(j + 1).grade;   

			boolean isExchange = false;  
			if (gradeOne > gradeTwo) {  
				isExchange = true;  
			} else if (gradeOne == gradeTwo) {  
				// 2张牌的grade相同  
				CardBigType type1 = cards.get(j).bigType;  
				CardBigType type2 = cards.get(j + 1).bigType;   

				// 从做到右，方块、梅花、红桃、黑桃  
				if (type1.equals(CardBigType.HEI_TAO)) {  
					isExchange = true;  
				} else if (type1.equals(CardBigType.HONG_TAO)) {  
					if (type2.equals(CardBigType.MEI_HUA)  
							|| type2.equals(CardBigType.FANG_KUAI)) {  
						isExchange = true;  
					}  
				} else if (type1.equals(CardBigType.MEI_HUA)) {  
					if (type2.equals(CardBigType.FANG_KUAI)) {  
						isExchange = true;  
					}  
				}  
			}   

			if (isExchange) {  
				Card cardOne = cards.get(j);  
				Card cardTwo = cards.get(j + 1);  
				// 交换  
				cards.set(j + 1, cardOne);  
				cards.set(j, cardTwo);  
			}  
		}  
	}  
	return true;  
}

void CardUnit::sortCards(vector<Card> cards) 
{  
	// 策略模式；复用已有类；  
	Collections.sort(cards, new CardComparator());  
}