#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
static char pairs[2][2] = {{'[', ']'}, {'(', ')'}};  
  
struct stack  
{  
	char data[10000];  
	int top;  
};  
  
void init_stack(struct stack *s)  
{  
	s->top = -1;  
}  
  
void push_stack(struct stack *s, char value)  
{  
	s->data[++s->top] = value;  
}  
  
void pop_stack(struct stack *s)  
{  
	--(s->top);  
}  
  
int is_empty(struct stack *s)  
{  
	return (s->top == -1);  
}  
  
char stack_top(struct stack *s)  
{  
	return s->data[s->top];  
}  
  
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
  
int check_pair(char *buf, int n, struct stack *s)  
{  
	int i;  
  
	if (n <= 0)  
		return 0;  
  
	for ( i = 0; i < n; i++ ) {  
		if (is_first_pair(buf[i]))  
			push_stack(s, buf[i]);  
		else if ( !is_empty(s) && is_pair(stack_top(s), buf[i]) )   
			pop_stack(s);  
		else  
			return 0;  
	}  
  
	if (is_empty(s))  
		return 1;  
	else   
		return 0;  
}  
  
int main( int argc, char **argv )  
{  
	int n;  
	char buf[10000];  
	struct stack s;  
	int i;  
  
	scanf("%d", &n);  
	for ( i = 0; i < n; i++ ) {  
		init_stack(&s);  
		buf[0] = '\0';  
		scanf("%s", buf);   
		if (check_pair(buf, strlen(buf), &s))  
			printf("Yes\n");  
		else  
			printf("No\n");  
	}  
  
	return 0;  
}  