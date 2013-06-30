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
#define ARGUMENT 7
#define MEMORY 15
#define ISEMPTY ((top->value == 0) && (top->next == NULL )) ? 1 : 0
stack* top;

void error(int type, int num)
    {
    switch (type)
	{
    case ARGUMENT:
	{
	if (num)
	fprintf(stderr, "\nСтрока №%d --> Ошибка в аргументе  :(\n",num);
	else
	    fprintf(stderr, "\nОшибка в аргументе  :(\n");
	break;
	}
    case MEMORY:
    	{
    	if (num)
    	fprintf(stderr, "\nСтрока №%d --> Указанный адрес не инициализирован  :(\n",num);
    	else
    	    fprintf(stderr, "\nУказанный адрес не инициализирован  :(\n");
    	break;
    	}
    case STACKISEMPTY:
	{
	if (num)
	fprintf(stderr, "\nСтрока №%d --> Стек пуст :(\n",num);
	else
	    fprintf(stderr, "\nСтек пуст :(\n");
	break;
	}
    case STACKISNOTEMPTY:
	{
/*	if (num)
	fprintf(stderr, "\nСтрока №%d --> Стек не пуст\n",num);
	else
	   fprintf(stderr, "\nСтек не пуст\n"); */
	break;
	}
    case WRONGNAME:
	{
	if (num)
	fprintf(stderr, "\nСтрока №%d --> Неверное имя файла\n",num);
	else
	    fprintf(stderr, "\nНеверное имя файла\n");
	break;
	}
    case WRONGINPUT:
	{
	if (num)
	fprintf(stderr, "\nСтрока №%d --> Неверная команда\n",num);
	else fprintf(stderr, "\nНеверная команда\n");
	break;
	}
    case ZERO:
	{
	if (num)
	fprintf(stderr, "\nСтрока №%d --> Деление на '0'\n",num);
	else fprintf(stderr, "\nДеление на '0'\n");
	break;
	}
	}
   // CloseStack();
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
    {
    if ((top== NULL) || ((top->next == NULL) && (top->value == 0)))
	{
	free(top);
	}
    else
	{
	do
	    {
	    stack* tempTop = top->next;
	    free(top);
	    top = tempTop;
	    }
	while ((top->next != NULL) && (top->value != 0));
	error(STACKISNOTEMPTY,0);
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
	//return 0;
	error(STACKISEMPTY,0);
	}
    else
	{
	int forReturn = top->value;
	stack* forDestroy = top;
	top = top->next;
	free(forDestroy);
	return forReturn;

	}
return 1;
    }
void print()
    {
    if (ISEMPTY)
	{
	error(STACKISEMPTY,0);
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
	error(STACKISEMPTY,0);
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
	error(STACKISEMPTY,0);
	}
    else
	{
	int temp = pop();
	int temp2 = pop();
	push(temp);
	push(temp2);
	}
    }
