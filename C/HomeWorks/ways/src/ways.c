/*
 ============================================================================
 Name        : Количество путей из 00 в ij
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int seach(int i, int j)
{
	int answ;
	if ((i == 0) || (j == 0) || (i == -1) || (j == -1)) answ = 1;
	else answ = seach(i, j - 1) + seach(i - 1, j);
	return answ;
}

int main()
{
	int i, j, a;
	printf(">>>");
	scanf("%d", &i);
	scanf("%d", &j);
	a = seach(i, j);
	printf("%d", a);
	return 0;
}
