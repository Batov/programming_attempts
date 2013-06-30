
/*
 ============================================================================
 Name        : Степень
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float deg(float a, int n)
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

int main(void)
{
	int n;
	float a, answr;

	printf("?\n");
	scanf("%f", &a);
	printf("deg\n");
	scanf("%d", &n);

	answr = deg(a, n);
	printf("%f", answr);

	return 0;
}
