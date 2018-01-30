#include "CardRule.h"

bool CardRule::isDan(vector<Card> myCards) 
{  
      // 默认不是单  
     bool flag = false;  
     if (!myCards.empty() && myCards.size() == 1) {  
         flag = true;  
     }  
     return flag;  
}

bool CardRule::isDuiZi(vector<Card> myCards) 
{  
	// 默认不是对子  
	bool flag = false;  

	if (!myCards.empty() && myCards.size() == 2) {  

		int grade1 = myCards[0].grade;  
		int grade2 = myCards[1].grade;  
		if (grade1 == grade2) {  
			flag = true;  
		}  
	}  
	return flag;  
} 

int CardRule::isSanDaiYi(vector<Card> myCards) 
{  
  int flag = -1;  
  // 默认不是3带1  
  if (!myCards.empty() && myCards.size() == 4) {  
	  // 对牌进行排序  
	  CardUtil.sortCards(myCards);  

	  int grades[4] = {0};  
	  grades[0] = myCards[0].grade;  
	  grades[1] = myCards[1].grade;  
	  grades[2] = myCards[2].grade;  
	  grades[3] = myCards[3].grade;  

	  // 暂时认为炸弹不为3带1  
	  if ((grades[1] == grades[0]) && (grades[2] == grades[0])  
			  && (grades[3] == grades[0])) {  
		  return -1;  
	  }  
	  // 3带1，被带的牌在牌头  
	  else if ((grades[1] == grades[0] && grades[2] == grades[0])) {  
		  return 0;  
	  }  
	  // 3带1，被带的牌在牌尾  
	  else if (grades[1] == grades[3] && grades[2] == grades[3]) {  
		  return 3;  
	  }  
  }  
  return flag;  
}

bool CardRule::isSanBuDai(vector<Card> myCards) 
{  
       // 默认不是3不带  
   bool flag = false;  

   if (!myCards.empty() && myCards.size() == 3) {  
	   int grade0 = myCards[0].grade;  
	   int grade1 = myCards[1].grade;  
	   int grade2 = myCards[2].grade;  

	   if (grade0 == grade1 && grade2 == grade0) {  
		   flag = true;  
	   }  
   }  
   return flag;  
} 

bool isShunZi(vector<Card> myCards) 
{  
       // 默认是顺子  
	bool flag = true;  

	if (!myCards.empty()) {  

	   int size = myCards.size();  
	   // 顺子牌的个数在5到12之间  123
	   if (size < 5 || size > 12) {  
		   return false;  
	   }  

	   // 对牌进行排序  
	   CardUtil.sortCards(myCards);  

	   for (int n = 0; n < size - 1; n++) {  
		   int prev = myCards[n].grade;  
		   int next = myCards[n + 1].grade;  
		   // 小王、大王、2不能加入顺子  
		   if (prev == 17 || prev == 16 || prev == 15 || next == 17  
				   || next == 16 || next == 15) {  
			   flag = false;  
			   break;  
		   } else {  
			   if (prev - next != -1) {  
				   flag = false;  
				   break;  
			   }  

		   }  
	   }  
	}  

	return flag;  
} 
   
bool isZhaDan(vector<Card> myCards) 
{  
        // 默认不是炸弹  
	bool flag = false;  
	if (!myCards.empty() && myCards.size() == 4) {  

		int grades[4] = {0};  
		grades[0] = myCards[0].grade;  
		grades[1] = myCards[1].grade;  
		grades[2] = myCards[2].grade;  
		grades[3] = myCards[3].grade;  
		if ((grades[1] == grades[0]) && (grades[2] == grades[0])  
				&& (grades[3] == grades[0])) {  
			flag = true;  
		}  
	}  
	return flag;  
}  
	
bool isDuiWang(vector<Card> myCards) 
{  
      // 默认不是对王  
  bool flag = false;  

  if (!myCards.empty() && myCards.size() == 2) {  

	  int gradeOne = myCards[0].grade;  
	  int gradeTwo = myCards[1].grade;  

	  // 只有小王和大王的等级之后才可能是33  
	  if (gradeOne + gradeTwo == 33) {  
		  flag = true;  
	  }  
  }  
  return flag;  
}
  
bool isLianDui(vector<Card> myCards)
{  
 // 默认是连对  
 bool flag = true;  
 if (myCards.empty()) {  
	 flag = false;  
	 return flag;  
 }  
   
 int size = myCards.size();  
 if (size < 6 || size % 2 != 0) {  
	 flag = false;  
 } else {  
	 // 对牌进行排序  
	 CardUtil.sortCards(myCards);  
	 for (int i = 0; i < size; i = i + 2) {  
		 if (myCards[i].grade != myCards[i + 1].grade) {  
			 flag = false;  
			 break;  
		 }  

		 if (i < size - 2) {  
			 if (myCards[i].grade - myCards[i + 2].grade != -1) {  
				 flag = false;  
				 break;  
			 }  
		 }  
	 }  
 }  

 return flag;  
}
 
bool isFeiJi(vector<Card> myCards) 
{  
 bool flag = false;  
 // 默认不是单  
 if (!myCards.empty()) {  

	 int size = myCards.size();  
	 if (size >= 6) {  
		 // 对牌进行排序  
		 CardUtil.sortCards(myCards);  

		 if (size % 3 == 0 && size % 4 != 0) {  
			 flag = isFeiJiBuDai(myCards);  
		 } else if (size % 3 != 0 && size % 4 == 0) {  
			 flag = isFeiJiDai(myCards);  
		 } else if (size == 12) {  
			 flag = isFeiJiBuDai(myCards) || isFeiJiDai(myCards);  
		 }  
	 }  
 }  
 return flag;  
}
 
bool isFeiJiBuDai(vector<Card> myCards) {  
 if (myCards.empty()) {  
	 return false;  
 }  

 int size = myCards.size();  
 int n = size / 3;  

 int grades[] = new int[n];  

 if (size % 3 != 0) {  
	 return false;  
 } else {  
	 for (int i = 0; i < n; i++) {  
		 if (!isSanBuDai(myCards.subList(i * 3, i * 3 + 3))) {  
			 return false;  
		 } else {  
			 // 如果连续的3张牌是一样的，记录其中一张牌的grade  
			 grades[i] = myCards[i * 3].grade;  
		 }  
	 }  
 }  

 for (int i = 0; i < n - 1; i++) {  
	 if (grades[i] == 15) {// 不允许出现2  
		 return false;  
	 }  

	 if (grades[i + 1] - grades[i] != 1) {  
		 System.out.println("等级连续,如 333444"  
				 + (grades[i + 1] - grades[i]));  
		 return false;// grade必须连续,如 333444  
	 }  
 }  

 return true;  
}
 
bool isFeiJiDai(vector<Card> myCards) 
{  
   int size = myCards.size();  
   int n = size / 4;// 此处为“除”，而非取模  
   int i = 0;  
   for (i = 0; i + 2 < size; i = i + 3) {  
	   int grade1 = myCards[i].grade;  
	   int grade2 = myCards[i + 1].grade;  
	   int grade3 = myCards[i + 2].grade;  
	   if (grade1 == grade2 && grade3 == grade1) {  

		   // return isFeiJiBuDai(myCards.subList(i, i + 3 *  
		   // n));8张牌时，下标越界,subList不能取到最后一个元素  
		   ArrayList<Card> cards = new ArrayList<Card>();  
		   for (int j = i; j < i + 3 * n; j++) {// 取字串  
			   cards.add(myCards(j));  
		   }  
		   return isFeiJiBuDai(cards);  
	   }  

   }  

   return false;  
}
   
bool isSiDaiEr(vector<Card> myCards) 
{  
  bool flag = false;  
  if (!myCards.empty() && myCards.size() == 6) {  

	  // 对牌进行排序  
	  CardUtil.sortCards(myCards);  
	  for (int i = 0; i < 3; i++) {  
		  int grade1 = myCards[i].grade;  
		  int grade2 = myCards[i + 1].grade;  
		  int grade3 = myCards[i + 2].grade;  
		  int grade4 = myCards[i + 3].grade;  

		  if (grade2 == grade1 && grade3 == grade1 && grade4 == grade1) {  
			  flag = true;  
		  }  
	  }  
  }  
  return flag;  
}
