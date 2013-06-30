/*
 ============================================================================
 Name        : calculator.c
 Author      : Batov
 Version     :
 Copyright   : 171gr
 Description : , Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libstack.h"
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define WRONGNAME 3
#define WRONGINPUT 0
#define DIVISIONBYZERO 5

float mpow(float a, int n)
{
	int i;
	float answr;
	answr = 1;
	for (i = 0; i < abs(n); i++)
	{
		answr = answr * a;
	}
	if (n < 0) answr = 1 / answr;
	return answr;
}
int strtoint(char* str)
{
	int rslt, i;
	rslt = 0;
	if (!str) error(WRONGINPUT);
	int stl = strlen(str);
	for (i = 0; i < stl; i++)
	{
		if (isdigit(str[i])) rslt = rslt
				+ (str[i] - '0') * mpow(10, stl - 1 - i);
		else error(WRONGINPUT);
	}
	return rslt;
}
int foroperation(char* str)
{
	if ((strlen(str) == 1))
	{
		if ((str[0] != '+') && (str[0] != '-') && (str[0] != '*')
				&& (str[0] != '/')) return 1; // если не оперaция то выходим
	}
	else return 1;
	char operation = str[0];
	switch (operation)
	{
		case '+':
		{
			int first = pop();
			int second = pop();
			push(first + second);
			break;
		}
		case '-':
		{
			int second = pop();
			int first = pop();
			push(first - second);
			break;
		}
		case '*':
		{
			int first = pop();
			int second = pop();
			push(first * second);
			break;
		}
		case '/':
		{
			int second = pop();
			int first = pop();
			if (second != 0) push(first / second);
			else error(DIVISIONBYZERO);
			break;
		}
	}
	return 0;
}
void analyze(char* str)
{
	if (!strcmp(str, "print"))
	{
		print();
	}
	else if (!strcmp(str, "dub"))
	{
		dub();
	}
	else if (!strcmp(str, "swap"))
	{
		swap();
	}
	else if (foroperation(str))
	{
		push(strtoint(str));
	}

}
int main(void)
{
	InitStack();
	char inputstr[50];

	FILE *f = fopen("input.txt", "r");
	if (f == NULL ) error(WRONGNAME);

	while (!feof(f))
	{
		fscanf(f, "%s", inputstr);
		analyze(inputstr);
	}
	CloseStack();
	return EXIT_SUCCESS;
}
