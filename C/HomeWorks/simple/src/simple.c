/*
 ============================================================================
 Name        : Сумма простых чисел <N
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int is_Prime(int N)
{
	int i;
	for (i = 2; i * i <= N; i++)
	{
		if (N % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int N = 15, answr, i;
	answr = 0;
	for (i = 2; i < N; i++)
	{
		if (is_Prime(i)) answr += i;
	}

	printf("%d", answr);
	return 0;
}
