/*
 ============================================================================
 Name        : Подстрока в строке "В лоб"
 Author      : Batov
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stos(char *bigstr, char *str)
{
	int answr;
	int i, j;
	int stl;
	answr = 0;
	for (i = 0; i < strlen(bigstr); i++)
	{
		if (bigstr[i] == str[0])
		{
			int is_Substr = 1;

			for (j = 0; j < strlen(str); j++)
			{
				if (bigstr[i + j] != str[j])
					{
					is_Substr = 0;
					break;
					}
			}
			if (is_Substr) answr++;
		}
	}

	return answr;
}/*
 ============================================================================
 Name        : Степень
 Author      : Batov
 ============================================================================
*/

int main()
{
	char bigstr[100], smallstr[100];
	int a;

	printf("Строку:");
	gets(bigstr);
	printf("\n");
	printf("Еще строку:");
	gets(smallstr);

	a = stos(bigstr, smallstr);
	printf("%d", a);

	return 0;
}



