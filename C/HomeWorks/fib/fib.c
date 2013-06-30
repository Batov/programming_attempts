/*
 ============================================================================
 Name        : Сумма четных чиссел фиббоначи
 Author      : Batov
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
	int answr;
	if ((n == 1) || (n == 0) || (n == 2)) answr = 1;
	else answr = f(n - 1) + f(n - 2);
	return answr;
}

int main()
{
	int n, answr, i, t;
	answr = 0;
	n = 40;

	for (i = 1; (t = f(i)) < n; i++)
	{
		if (t % 2 == 0) answr += t;
	}

	printf("%d", answr);

	return 0;
}
