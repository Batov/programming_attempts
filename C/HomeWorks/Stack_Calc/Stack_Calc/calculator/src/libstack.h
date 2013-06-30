/*
 * libstack.h
 *
 *  Created on: 02.11.2012
 *      Author: Batov
 */

#ifndef LIBSTACK_H_
#define LIBSTACK_H_

typedef struct stack
{
int value;
struct stack* next;
} stack;
extern stack* top;
void error(int type);
void InitStack();
void push(int value);
int pop();
void CloseStack();
void print();
void dub();
void swap();

#endif /* LIBSTACK_H_ */
