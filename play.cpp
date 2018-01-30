#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define LINE 20
#define ROW 18

int PX = 17;
int PY = 4;
DWORD h1;
DWORD h2;
DWORD h3;
DWORD h4;
DWORD h5;

int flag = 0;

struct Pos{
	int x;
	int y;
};

enum{
	BLANK,
	WALL,
	MYPLY,
	ATPLY,
	BUL
};

enum{
	BUL,   //子弹
	PLA    //敌机
};

vector<Pos> vecBul;   //子弹容器
vector<Pos> vecPla;   //飞机容器
map<Pos, int> mapMove;  //子弹和飞机容器

int ary[LINE][ROW] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
bool cls() //编程方式实现清除屏幕
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};    /* here's where we'll home the cursor */ 
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
    DWORD dwConSize;                 /* number of character cells in the current buffer */ 
 
    /* get the number of character cells in the current buffer */ 
    if(!GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return false;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 
    /* fill the entire screen with blanks */ 
    if(!FillConsoleOutputCharacter( hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten ))
        return false;
 
    /* get the current text attribute */ 
    if(!GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return false;
 
    /* now set the buffer's attributes accordingly */ 
    if(!FillConsoleOutputAttribute( hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten ))
        return false;
 
    /* put the cursor at (0, 0) */ 
    if(!SetConsoleCursorPosition( hConsole, coordScreen ))
        return false;
}

//打印线程
DWORD WINAPI PrintProc(LPVOID lparent)  
{  
	while(1){
		cls();
		int i, j;
		for(i = 0; i < LINE; i++){
			for(j = 0; j < ROW; j++){
				switch(ary[i][j]){
				case BLANK:
					cout<<" ";
					break;
				case WALL:
					cout<<"*";
					break;
				case MYPLY:
					cout<<"^";
					break;
				case ATPLY:
					cout<<"v";
					break;
				case BUL:
					cout<<".";
					break;
				default:
					break;
				}
			}
			cout<<endl;
		}
		if(flag == 1)
			return 0;
		Sleep(1000);
	}
    return 0;  
}

//子弹移动线程
DWORD WINAPI MoveBulProc(LPVOID lparent)
{
	while(1){
		for(map<Pos>::iterator it = mapMove.begin(); it != mapMove.end(); it++){
			ary[(*it).first.x][(*it).first.y] = BLANK;
			if((*it).second == BUL){
				
				vecBul.erase(it);
				//ary[tmp.x][tmp.y] = WALL;
				break;
			} else if ((*it).second == PLA){
				
			}
			if(ary[(*it).x][(*it).y] == ATPLY){
				vecBul.erase(it);
				ary[(*it).x][(*it).y] = BLANK;
			} else 
				ary[(*it).x][(*it).y] = BUL;
		}
		if(flag == 1)
			return 0;
		Sleep(1000);
	}
	return 0;
}

void DelBul(Pos p)
{
	for(vector<Pos>::iterator it = vecBul.begin(); it != vecBul.end(); it++){
		if ((*it).x == p.x && (*it).y == p.y){
			vecBul.erase(it);
			break;
		}
	}
}
//敌机移动线程
DWORD WINAPI MovePlaProc(LPVOID lparent)
{
	while(1){
		for(vector<Pos>::iterator it = vecPla.begin(); it != vecPla.end(); it++){
			ary[(*it).x][(*it).y] = BLANK;
			if ((*it).x++ == 17){
				vecPla.erase(it);
				break;
			}
			if (ary[(*it).x][(*it).y] == BUL){
				ary[(*it).x][(*it).y] = BLANK;
				//DelBul(*it);
				vecPla.erase(it);
				break;
				//vector<Pos>::iterator its = find_if(vecBul.begin(), vecBul.end(), p);
				
			}
			else if (ary[(*it).x][(*it).y] == MYPLY){
				cout<<"GAME OVER!"<<endl;
				flag = 1;
				return 0;
			}
			else
				ary[(*it).x][(*it).y] = ATPLY;
		}
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI MoveMyPlaProc(LPVOID lparent)
{
	while(1){
		if (KEY_DOWN('A')){
			if(PY > 1){
				ary[PX][PY] = BLANK;
				PY = PY - 1;
				ary[PX][PY] = MYPLY;
			}
		} else if(KEY_DOWN('D')){
			if(PY < ROW-1){
				ary[PX][PY] = BLANK;
				PY = PY + 1;
				ary[PX][PY] = MYPLY;
			}
		} else if(KEY_DOWN('W')){
			Pos p;
			p.x = PX-1;
			p.y = PY;
			vecBul.push_back(p);
		}
		if(flag == 1)
			return 0;
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI AddPlaProc(LPVOID lparent)
{
	while(1){
		Pos p;
		p.x = 1;
		p.y = rand()%(ROW-2)+1;
		vecPla.push_back(p);
		if(flag == 1)
			return 0;
		Sleep(2000);
	}
	return 0;
}
int main()
{
	ary[PX][PY] = MYPLY;
	
	//system("cls");
	/*Pos p;
	p.x = 15;
	p.y = 4;
	vecBul.push_back(p);
	p.x = 2;
	p.y = 2;
	vecPla.push_back(p);*/
	
	CreateThread(NULL,0,MoveMyPlaProc,NULL,0,&h1);
	CreateThread(NULL,0,PrintProc,NULL,0,&h2);
	CreateThread(NULL,0,MoveBulProc,NULL,0,&h3);
	CreateThread(NULL,0,MovePlaProc,NULL,0,&h4);
	CreateThread(NULL,0,AddPlaProc,NULL,0,&h5);
	
	//Print();
	
	getchar();
}