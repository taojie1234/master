#include <iostream>
#include <string.h>
using namespace std;

#define MAX 10000

static char pairs[2][2] = {{'[',']'}, {'(', ')'}};
class stack
{
private:
	char arr[MAX];
	int top;
public:
	stack()
	{
		inItStack();
	}
	void inItStack()
	{
		top = -1;
	}
	
	void push(char str)
	{
		top++;
		if (top < MAX) {
			arr[top] = str;
		} else {
			cout<<"STACK FULL!"<<top;
		}
	}
	bool isEmpty()
	{
		if (top == -1) 
			return true;
		else
			return false;
	}
	char pop()
	{
		if (isEmpty()){
			cout<<"STACK IS EMPTY";
			return '\0';
		} else {
			char data = arr[top];
			arr[top] = '\0';
			top--;
			return data;
		}
	}
	
};

int is_first_pair(char a)  
{  
	int i;  
	int n = sizeof(pairs) / sizeof(pairs[0]);  
	for ( i = 0; i < n; i++ ) {  
		if ( pairs[i][0] == a ) {  
			return 1;  
		}  
	}  
  
	return 0;  
}  
  
int is_pair(char a, char b)  
{  
	int i;  
	int n = sizeof(pairs) / sizeof(pairs[0]);  
	for ( i = 0; i < n; i++ ) {  
		if (pairs[i][0] == a) {  
			if (pairs[i][1] == b) {  
				return 1;  
			} else {  
				return 0;   
			}  
		}  
	}  
  
	return 0;  
}

int main()
{
	char buf[MAX];
	int n = 0, i = 0;
	cin>>n;
	if (n <= 0)
		return 0;
	
	while (n--)
	{
		buf[0] = '\0';
		cin>>buf;
		
		stack stk;
		bool flag = false;
		int len = strlen(buf);
		for (int j = 0; j < len; j++)
		{
			char s = buf[j];
			
			if (is_first_pair())
				stk.push(s);
			else {
				if (stk.isEmpty()) {
					flag = false;
					break;
				}
				char f = stk.pop();
				if (f == '[' && s == ']')
					flag = true;
				else if (f == '(' && s == ')' )
					flag = true;
				else
					flag = false; 
			}
				
		}
		if (flag && stk.isEmpty()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}