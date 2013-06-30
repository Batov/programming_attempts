/*
 ============================================================================
 Name        : Скобочная структура, 3 вида скобок.
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
#include <string.h>
int mas[20];
int count = 0;
#define br 1
#define sbr 2
#define fbr 3

void push(int a)
{
	mas[count] = a;
	count++;
}
int pop()
{
	if (count == 0)
	{
		printf("Стек пуст");
		return 1;
	}
	count--;
	return mas[count];
}

int checkstr(char* s)
{
	int i, t;
	for (i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
			case '(':
				push(br);
				break;
			case '[':
				push(sbr);
				break;
			case '{':
				push(fbr);
				break;
			case ')':
			{
				t = pop();
				if (t != br) return 0;
			}
				break;
			case ']':
			{
				t = pop();
				if (t != sbr) return 0;
			}
				break;
			case '}':
			{
				t = pop();
				if (t != fbr) return 0;
			}
				break;
		}
	}
	if (count == 0) return 1;
	else return 0;
}

int main()
{
	char* s[40];
	printf(">>>");
	gets(s);

	if (checkstr(s) == 1) printf("+");
	else printf("-");

	return 0;
}
