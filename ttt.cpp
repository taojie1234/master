#include <iostream>
#include <windows.h>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的  

void check(char c){//检测某个按键是否按下，按下就改变输出颜色  
    if(KEY_DOWN(c))
		cout<<"val="<<c<<endl;  
}  

int main()
{
	while(1){
		check('W');
		Sleep(100);
	}
	return 0;
}