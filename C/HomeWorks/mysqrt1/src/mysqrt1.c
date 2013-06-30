/*
 ============================================================================
 Name        : кв. корень ньютон
 Author      : Batov
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float mysqrt(float n)
{
	if (!n) return 0;
	float rslt = n;
	int i = 0;
	while ((i < 20 + n / 100) && (i <= 150))
	{
		rslt = 0.5 * (rslt + n / rslt);
		i++;
	}
	return rslt;
}

int main()
{
	float n;
	scanf("%f", &n);
	printf("%.5f\n", mysqrt(n));
	return 0;

}
