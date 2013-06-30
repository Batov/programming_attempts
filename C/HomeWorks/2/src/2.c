/*
 ============================================================================
 Name        : Факториал рекурсия
 Author      : Batov
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int f(int n) // Рекурсивная функция
{
	int res;
	if (n==1 || n==0)  res=1;
		else res=f(n-1)*n;
	return res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	if (n<0) puts("-");
	else
	{
		int resq=f(n);
		printf("%d",resq);
	}

	return 0;
}
