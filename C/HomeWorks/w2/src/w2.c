/*
 ============================================================================
 Name        : Пути из 00 в Ij
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
long Mem[100][100];

long C(long i, long j)
{
	if (Mem[i][j] > 0) return Mem[i][j];
	if (j == 0 || i == 0) return 1;

	return Mem[i][j] = C(i, j - 1) + C(i - 1, j);
}

int main()
{
	long i, j;

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			Mem[i][j] = 0;

	scanf("%ld%ld", &i, &j);
	printf("%ld\n", C(i, j));
	return 0;
}
