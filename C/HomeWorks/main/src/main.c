/*
 ============================================================================
 Name        : main.c
 Author      : Batov
 Version     :
 Copyright   : 171gr
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio>

int main()
{
	int i;
	int n = 10;
	scanf("%d", &n);
	int* MyBuffer [100];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &MyBuffer[i]);
	}
	sort(MyBuffer, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d ", MyBuffer[i]);
	}
}
