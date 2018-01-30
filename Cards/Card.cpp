#include "Card.h"

// 通过牌的整型id构造一张牌  
Card::Card(int id) 
{  
	this->id = id;
	bigType = getBigType(id);  
	smallType = getSmallType(id);  
	grade = getGrade(id);  
	imageName = getImageName(id);  
	printf(imageName.c_str());
	//Icon icon = getImageIcon(imageName);  
	//setIcon(icon);  
}  

int Card::getBigType(int id) 
{  
	int bigType;  
	if (id >= 1 && id <= 13) {
		bigType = FANG_KUAI;  
	} else if (id >= 14 && id <= 26) {  
		bigType = MEI_HUA;  
	} else if (id >= 27 && id <= 39) {  
		bigType = HONG_TAO;  
	} else if (id >= 40 && id <= 52) {  
		bigType = HEI_TAO;  
	} else if (id == 53) {  
		bigType = XIAO_WANG;  
	} else if (id == 54) {  
		bigType = DA_WANG;  
	}  
	return bigType;  
}

int Card::getSmallType(int id) {  
	if (id < 1 || id > 54) {  
		printf("牌的数字不合法");  
	}  
  
	int smallType;  
  
	if (id >= 1 && id <= 52) {  
		smallType = numToType(id % 13);  
	} else if (id == 53) {  
		smallType = XW;  
	} else if (id == 54) {  
		smallType = DW; 
	} else {  
		smallType = 0;  
	}  
	return smallType;  
 }
 
int Card::numToType(int num) 
{  
  int type;  
  switch (num) {  
  case 0:  
   type = K;  
   break;  
  case 1:  
   type = A;  
   break;  
  case 2:  
   type = ER;  
   break;  
  case 3:  
   type = SAN;  
   break;  
  case 4:  
   type = SI;  
   break;  
  case 5:  
   type = WU;  
   break;  
  case 6:  
   type = LIU;  
   break;  
  case 7:  
   type = QI;  
   break;  
  case 8:  
   type = BA;  
   break;  
  case 9:  
   type = JIU;  
   break;  
  case 10:  
   type = SHI;  
   break;  
  case 11:  
   type = J;  
   break;  
  case 12:  
   type = Q;  
   break;  
  
  }  
  return type;  
 } 
 
int Card::getGrade(int id) 
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
  }  
  
  else {  
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

string Card::getImageName(int id) 
{  
  // 得到图片的前一个字符，表示是第几个牌  
  string imageName = "";  
  
  if (id == 53) {  
   imageName += "smallJoker";  
  } else if (id == 54) {  
   imageName += "bigJoker";  
  } else {  
   int mod = id % 13;  
   string firstLetter = "";  
   switch (mod) {  
   case 0:  
    firstLetter = "K";  
    break;  
   case 1:  
    firstLetter = "A";  
    break;  
   case 2:  
   case 3:  
   case 4:  
   case 5:  
   case 6:  
   case 7:  
   case 8:  
   case 9:  
   case 10:  
	char ch[8];
    sprintf(ch, "%d", mod);  
	firstLetter = string(ch);
    break;  
   case 11:  
    firstLetter = "J";  
    break;  
   case 12:  
    firstLetter = "Q";  
    break;  
   default:  
    break;  
   }  
  
   string secondLetter = "";  
   // 得到图片的后一个字符，表示什么颜色的牌  
   if (id >= 1 && id <= 13) {  
    secondLetter = "0";  
   } else if (id >= 14 && id <= 26) {  
    secondLetter = "1";  
   } else if (id >= 27 && id <= 39) {  
    secondLetter = "2";  
   } else if (id >= 40 && id <= 52) {  
    secondLetter = "3";  
   }  
  
   imageName = firstLetter + secondLetter;  
  }  
  string extension = ".gif";  
  
  return imageName + extension;  
} 