/*
 ============================================================================
 Name        : Битовое представление числа
 Author      : Batov
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

void Print_bit(int dec_n)
{
	int mask = 1 << 31;
	int i = 1;
	printf("%d",dec_n);
	printf("=");
	for (i = 1; i <= 32; i++)
	{
		if (dec_n & mask) putchar('1');
		else putchar('0');
		dec_n <<= 1;

		if ( i % 8 == 0)
		putchar(' ');
	}
}

int main()
{
	int dec_n;
	dec_n=1308;
	Print_bit(dec_n);
	return 0;
}
