/*
 * libstrtoint.c
 *
 *  Created on: 25.11.2012
 *      Author: sten
 */
#include "libstrtoint.h"
#include <stdlib.h>
#include <stdio.h>
#define SYNTAX 123
#define ZERO 666
#define BRACKETS_ERROR 21
#define CLEAR 100;


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
	if (!str) error(SYNTAX);
	int stl = strlen(str);
	for (i = 0; i < stl; i++)
	{
		if (isdigit(str[i])) rslt = rslt
				+ (str[i] - '0') * mpow(10, stl - 1 - i);
		else error(SYNTAX);
	}
	return rslt;
}

