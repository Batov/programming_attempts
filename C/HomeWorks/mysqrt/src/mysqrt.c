/*
 ============================================================================
 Name        : кв. корень ньютон
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

float mant_and_exp(float fnum)
{
	union
	{
	float fl;
	int num;
	} f;
	f.fl = fnum;

	int s = (f.num >> 31) ? -1 : 1;
	//Эксп.
	int e = (f.num >> 23) & 0xff;
	e = (e - 127);
	//Мантиса
	float m = (f.num) & 0x7fffff;
	m = 1 + m / deg(2, 23);
	return fabs(m * e);
}

float mysqrt(float n)
{
	if (!n) return 0;
	float rslt = n;
	int i = 0;
	float E = 0.001;
	while (((fabs( < E)&& (i <= 149))
	//Это конечно круто...
	{
		rslt = 0.5 * (rslt + n / rslt);
		i++;
	}
	printf("%s%d\n", "Количество итераций=", i);
	return rslt;
}

int main()
{
	float n;
	scanf("%f", &n);
	printf("%f\n", mysqrt(n));
	return 0;
}
