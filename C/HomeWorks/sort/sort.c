/*
 * sort.c
 *
 *  Created on: 29.10.2012
 *      Author: sten
 */

#include "sort.h"

void sort(int* buffer, long high_limit)
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

		if (R > 0) sort(buffer, R);
		if (high_limit > L) sort(buffer + L, high_limit - L);

}
