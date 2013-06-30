/*
 ============================================================================
 Name        : Печать ieee 754
 Author      : Batov
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quantity_of_digits(int num)
{
	int res = 1;
	while (num / 10 != 0)
	{
		res++;
		num /= 10;
	}
	if (num < 0) res++;
	return res;
}

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

int print_float(float fl_num)
{
	union
	{
	float fl;
	int num;
	} f;

	float res;
	f.fl = fl_num;
//Нули------------------------------------------------
	if (f.fl == 0x00000000)
	{
		printf("0");
		return 0;
	}
	if (f.fl == 0x80000000)
	{
		printf("-0");
		return 0;
	}

//Нули------------------------------------------------

//Знак
	int s = (f.num >> 31) ? -1 : 1;
//Эксп.
	int e = (f.num >> 23) & 0xff;
	e = (e - 127);
//Мантиса
	float m = (f.num) & 0x7fffff;
	m = 1 + m / deg(2, 23);
// NaN infinity--------------------------------
	if (e == 128)
	{
		if (m == 1.0)
		{
			if (s == 1)
			{
				printf("+inf");
				return 0;
			}
			else
			{
				printf("-inf");
				return 0;
			}
		}
		else
		{
			printf("NaN\n");
			return 0;
		}
	}
// NaN infinity--------------------------------

	res = s * m * deg(2, e);
	if ((e != -127)) // Нормализованные
	{
		if (s == -1) printf("    %d\n", e);
		else printf("   %d\n", e);
		printf("%d*2", s);
		int quan_d = quantity_of_digits(e);
		int i;
		for (i = 1; i <= quan_d; i++)
		{
			printf(" ");
		}
		printf("*%f\n", m);
	}
	else
	{
		if (s == -1) printf("    %d\n", -126); //Денормализованные
		else printf("   %d\n", -126);
		printf("%d*2", s);
		int quan_d = quantity_of_digits(e);
		int i;
		for (i = 1; i <= quan_d; i++)
		{
			printf(" ");
		}
		printf("*%f\n", m - 1);

	}
	return 0;
}

int main()
{
	float fl;
	scanf("%f", &fl);
	print_float(fl);

	return 0;
}
