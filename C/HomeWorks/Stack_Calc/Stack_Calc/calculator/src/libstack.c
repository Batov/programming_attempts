/*
 * libstack.c
 *
 *  Created on: 02.11.2012
 *      Author: Batov
 */
#include "libstack.h"
#include <stdlib.h>
#include <stdio.h>
#define STACKISEMPTY 1
#define STACKISNOTEMPTY 2
#define WRONGNAME 3
#define WRONGINPUT 0
#define ZERO 5
#define ISEMPTY ((top->value == 0) && (top->next == NULL )) ? 1 : 0
stack* top;

void error(int type)
{
	switch (type)
	{
		case STACKISEMPTY:
		{
			fprintf(stderr,"\nСтек пуст... :(\n");
			break;
		}
		case STACKISNOTEMPTY:
		{
			fprintf(stderr,"\nВ стеке остались элементы!\n");
			break;
		}
		case WRONGNAME:
		{
			fprintf(stderr,"\nНеверное имя файла\n");
			break;
		}
		case WRONGINPUT:
		{
			fprintf(stderr,"\nНеверная команда\n");
			break;
		}
		case ZERO:
		{
			fprintf(stderr,"\nДеление на '0'\n");
			break;
		}
	}
	CloseStack();
	exit(1);
}
void InitStack()
{
	stack* new = (stack*) malloc(sizeof(stack));
	new->value = 0;
	new->next = NULL;
	top = new;
}
void CloseStack()
{ //если все в порядке то очищяем нижний элемент и все хорошо
	if ((top->next == NULL )&&(top->value==0)){
	free(top);
}
else //а если нет, то очищаем пока не станет хорошо...
{
	do
	{
		stack* tempTop=top->next;
		free(top);
		top=tempTop;
	}
	while ((top->next != NULL )&&(top->value!=0));
	error(STACKISNOTEMPTY);
}
}
void push(int value)
{
	stack* new = (stack*) malloc(sizeof(stack));
	new->value = value;
	new->next = top;
	top = new;
}
int pop()
{
	if (ISEMPTY)
	{
		return 0;
		error(STACKISEMPTY);
	}
	else
	{
		int forReturn = top->value;
		stack* forDestroy = top;
		top = top->next;
		free(forDestroy);
		return forReturn;

	}

}
void print()
{
	if (ISEMPTY)
	{
		error(STACKISEMPTY);
	}
	else
	{
		printf("%d\n", pop());
	}
}
void dub()
{
	if (ISEMPTY)
	{
		error(STACKISEMPTY);
	}
	else
	{
		push(2 * pop());
	}
}
void swap()
{
	if (ISEMPTY)
	{
		error(STACKISEMPTY);
	}
	else
	{
		int temp = pop();
		int temp2 = pop();
		push(temp);
		push(temp2);
	}
}
