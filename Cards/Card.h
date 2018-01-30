#include <iostream>
using namespace std;

class Card
{
	// 一张牌的大类型  
public:
	enum CardBigType {  
		HEI_TAO, HONG_TAO, MEI_HUA, FANG_KUAI, XIAO_WANG, DA_WANG  
	};
	enum CardSmallType {  
		A, ER, SAN, SI, WU, LIU, QI, BA, JIU, SHI, J, Q, K, XW, DW  
	};
	
	Card(int id);
	static int getBigType(int id);
	static int getSmallType(int id);
	static int getGrade(int id);
	static string getImageName(int id);
 public:
	int id;  
  
 // 牌的大类型，方块，梅花,红桃,黑桃,小王,大王  
	int bigType;  
  
 // 牌的小类型，2_10,A,J,Q,K  
	int smallType;  
  
 // 牌的等级，对牌进行排序时会用到  
	int grade;  
  
 // 牌的图像名字，图形界面显示牌用到  
	string imageName;
private:
	static int numToType(int num);
};