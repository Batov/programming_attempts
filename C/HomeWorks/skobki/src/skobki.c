/*
 ============================================================================
 Name        : skobki.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int mas[10];

int count=0;

void push(int a)

{

mas[count]=a;

count++;

}

int pop()

{

if (count==0)

{

printf("Стек пуст");

return 1;

}

count--;

return mas[count];

}

main()

{

push(1);

push(2);

push(3);

while (count>0)

{

printf("Рузультат: %d\n", pop());

}

}
