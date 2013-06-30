/*
 ============================================================================
 Name        : quicksort в кучеs
 Author      : Batov
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

void MyQuickSort(int* buffer, long high_limit)
{
	int L = 0, R = high_limit;
	int temp, Center;
	Center = buffer[high_limit >> 1];

	do
	{
		while (buffer[L] < Center)
			L++;
		while (buffer[R] > Center)
			R--;

		if (L <= R)
		{
			temp = buffer[L];
			buffer[L] = buffer[R];
			buffer[R] = temp;
			L++;
			R--;
		}
	}
	while (L <= R);

	if (R > 0) MyQuickSort(buffer, R);
	if (high_limit > L) MyQuickSort(buffer + L, high_limit - L);
}

int main(void)
{
	int i;
	int n = 10;
	scanf("%d", &n);
	int* MyBuffer = malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &MyBuffer[i]);
	}
	MyQuickSort(MyBuffer, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d ", MyBuffer[i]);
	}

	free(MyBuffer);
	return 0;
}
