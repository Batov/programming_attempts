/*
 ============================================================================
 Name        : stackoverflow.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
unsigned long long qw = 0;
void w()
{
	qw++;
	q();
}

void q(long l)
{
	printf("%d вызова\n",qw);
	printf("%d\n",&l);
	qw++;
	q(l);
}

int main(void) {
	q(1);
}
