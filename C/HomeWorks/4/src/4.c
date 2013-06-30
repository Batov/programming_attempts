/*
 ============================================================================
 Name        : 4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int a,n,i,res;
	scanf("%d",&a);
	scanf("%d",&n);
	res=1;
		for(i=0;i<abs(n);i++)
			res=res*a;

	if (n<0)
	{
		res=1.0/res;
		printf("%f",res);
	} else
		printf("%d",res);
		return 0;
}
