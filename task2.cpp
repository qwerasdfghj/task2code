#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct stack {
	char stck[MAX];
	int top;
}s;

void push(char item) {
	if (s.top == (MAX - 1))
		printf("Stack is Full\n");

	else {
		s.top = s.top + 1;
		s.stck[s.top] = item;
	}
}

void pop() {
	if (s.top == -1)
		printf("Stack is Empty\n");

	else
		s.top = s.top - 1;
}

int checkPair(char val1, char val2) {
	return ((val1 == '(' && val2 == ')') || (val1 == '[' && val2 == ']') || (val1 == '{' && val2 == '}'));
}

int checkBalanced(char expr[], int len) {

	for (int i = 0; i < len; i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
			push(expr[i]);
		}
		else
		{
			
			if (s.top == -1)
				return 0;
		    if (checkPair(s.stck[s.top], expr[i]))
			{
				pop();
				continue;
			}
			
			else {
				return 0;
			}
			
		}
	}
	int al = 0;
	int ar = 0;
	int bl = 0;
	int br = 0;
	int cl = 0;
	int cr = 0;

	for (int i = 0; i < len; i++) {
		if (expr[i] == '(') {
			al++;
		}
		if (expr[i] == ')') {
			ar++;
		}
		if (expr[i] == '[') {
			bl++;
		}
		if (expr[i] == ']') {
			br++;
		}
		if (expr[i] == '{') {
			cl++;
		}
		if (expr[i] == '}') {
			cr++;
		}
	}
	
	if ((al != ar) || (bl != br) || (cl != cr) ) {
		return 0;

	}

	if (expr[len-1] != ')' && expr[len - 1] != ']' && expr[len - 1] != '}') {
		return 0;
	}

	
	return 1;
	
	
}
int main() {
	char exp[MAX] = "()()({})()(";
	int i = 0;
	s.top = -1;
	int len = strlen(exp);
	
	
	
	checkBalanced(exp, len) ? printf("Balanced") : printf("Not Balanced");

	return 0;
}