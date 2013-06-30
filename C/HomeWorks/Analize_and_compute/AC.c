/*
 * AC.c
 *
 *  Created on: 25.11.2012
 *      Author: batov
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libstrtoint.h"
#define EXIT_SUCCESS 0
#define TRUE 1
#define FALSE 0
#define NUM 10
//#define ERROR 666
#define PLUS 2
#define MINUS 3
#define MLT 4
#define DIV 5
#define LEFT_BRACKETS 7
#define RIGHT_BRACKETS 8
#define ZERO 666
#define CLEAR 100
#define SIZEOFSTR 256
#define BRACKETS_ERROR 21
#define SYNTAX 123
#define NOT_OPERATION ((instr[0][i] != '\0') && (instr[0][i] != '+') && (instr[0][i] != '-') && (instr[0][i] != '*') && (instr[0][i] != '/') && (instr[0][i] != '(') && (instr[0][i] != ')'))

char* slashhead(char* instr, int count) //Отрубает count элементов от строки
{
	int i;
	int inlen = strlen(instr);
	char* res = malloc(SIZEOFSTR * sizeof(char));
	for (i = count - 1; i <= inlen; i++)
	{

		res[i - count] = instr[i];
	}
	return res;
}
int GetNumber(char* instr) //Возвращает число
{
	int i = 0;
	char* rslt = malloc(SIZEOFSTR * sizeof(char));
	while (isdigit(instr[i]))
	{

		if (instr[i] != ' ')
			rslt[i] = instr[i];
		i++;
	}
	int temp = strtoint(rslt);
	free(rslt);
	return temp;
}
char* GetStrNum(char * instr) //Возвращает написание числа
{
	int i = 0;
	char* rslt = malloc(SIZEOFSTR * sizeof(char));
	while (isdigit(instr[i]))
	{
		if (instr[i] != ' ')
			rslt[i] = instr[i];
		i++;
	}
	//*instr = slashhead(&*instr, i);
	return rslt;
}

void nextLexem(Lexer* L)
{
	LEX rslt;
	rslt.type = NUM;
	char* instr = (*L).string;
	while (instr[0] == ' ')
	{
		instr = slashhead(instr, 1);
	}
	(*L).string = instr;
	char currentChar = instr[0];
	switch (currentChar)
	{
	case '+':
	{
		rslt.type = PLUS;
		rslt.string = "+";

		break;
	}
	case '-':
	{
		rslt.string = "-";
		rslt.type = MINUS;
		break;
	}
	case '*':
	{
		rslt.string = "*";
		rslt.type = MLT;
		break;
	}
	case '/':
	{
		rslt.string = "/";
		rslt.type = DIV;
		break;
	}
	case '(':
	{
		rslt.string = "(";
		rslt.type = LEFT_BRACKETS;
		break;
	}
	case ')':
	{
		rslt.string = ")";
		rslt.type = RIGHT_BRACKETS;
		break;
	}
	}
	if (rslt.type == NUM)
	{
		rslt.value = GetNumber(instr);
		rslt.string = GetStrNum(instr);
		if (rslt.value == 0)
			rslt.value = 0;
		(*L).curLex = rslt;
		(*L).position = (*L).position + 1;
		(*L).string = slashhead((*L).string, strlen((*L).curLex.string));
	}
	else
	{
		(*L).curLex = rslt;
		(*L).position = (*L).position + 1;
		(*L).string = slashhead((*L).string, strlen((*L).curLex.string));
	}
}
//===================================================================

int expression(Lexer* L)
{
	//*curLex = nextLexem(&*instr);
	int res = term(&*L);
	while ((((*L).curLex).type == PLUS) || (((*L).curLex).type == MINUS))
	{
		LEX LexOperation = (*L).curLex;
		nextLexem(&*L);
		int rhs = term(&*L);
		if (LexOperation.type == PLUS)
		{
			res = res + rhs;
		}
		else
		{
			res = res - rhs;
		}
	}
	return res;
}

int term(Lexer *L)
{
	int res = factor(&*L);
	while ((((*L).curLex).type == MLT) || (((*L).curLex).type == DIV))
	{
		LEX LexOperation = (*L).curLex;
		nextLexem(&*L);
		int rhs = factor(&*L);
		if (LexOperation.type == MLT)
		{
			res = res * rhs;
		}
		else
		{
			if (rhs != 0)
				res = res / rhs;
			else
				error(&*L, ZERO);
		}
	}
	return res;
}

int factor(Lexer *L)
{
	if (((*L).curLex).type == NUM)
	{
		if (((*L).curLex).string[0] != '\0')
		{
			int temp = ((*L).curLex).value;
			nextLexem(&*L);
			return temp;
		}
		else
			error(*&L, SYNTAX);
	}
	else if (((*L).curLex).type == LEFT_BRACKETS)
	{
		nextLexem(&*L);
		int Result = expression(&*L);
		if (((*L).curLex).type == RIGHT_BRACKETS)
			nextLexem(&*L);
		else
			error(*&L, BRACKETS_ERROR);
		return Result;
	}
	else
		error(&*L, SYNTAX);
}

//===================================================================

int Calculate(Lexer* L)
{
	L->position = 0;
	nextLexem(&*L);
//	nextLexem(&*L);
//	nextLexem(&*L);
	int rslt = expression(&*L);
	if ((L->string[0] == '\0') && (L->curLex.value == 0))
	{

		return rslt;
	}
	else if (!strcmp(L->curLex.string, ")"))
		error(*&L, BRACKETS_ERROR);
	else
		error(&*L, SYNTAX);
}

void error(Lexer *L, int type)
{
	switch (type)
	{
	case BRACKETS_ERROR:
	{
		fprintf(stderr, "\nНеверная скобочная структура\n");
		fprintf(stderr, "Номер лексемы:%d", (*L).position);
		break;
	}

	case SYNTAX:
	{
		fprintf(stderr, "\nСинтаксическая ошибка \n");
		fprintf(stderr, "Номер лексемы:%d", (*L).position);
		break;
	}

	case ZERO:
	{
		fprintf(stderr, "\nДеление на '0'\n");
		//printf(stderr, "%d", (*L).position);
		break;
	}
	case CLEAR:
	{
		fprintf(stderr, "\nПустая строка\n");
		//printf(stderr, "%d", (*L).position);
		break;
	}
	}
	exit(1);
}

int main()
{
	char* instr = malloc(SIZEOFSTR * sizeof(char));
	//scanf("%s",instr);
	gets(instr);
	Lexer startLexer;
	startLexer.string = instr;
	//debugNext("(1+1))");
	printf("=%d", Calculate(&startLexer));
	//free(instr);
	return EXIT_SUCCESS;
}

