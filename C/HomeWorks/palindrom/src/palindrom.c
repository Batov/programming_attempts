
/*
 ============================================================================
 Name        : Палиндром
 Author      : Batov
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_palindrom(char* s)
{
	int l = 0;
	int r = strlen(s) - 1;
	int stlen=strlen(s)-1;
	while (l < r)
	{
		while ((isalpha(s[l]) == 0) && (l<r))
			l++;
		while ((isalpha(s[r]) == 0) && (l<r))
			r--;
		//	printf("%d, %d\n", l, r);
		if ((r==0) && (l==stlen)) return 1;
		if (tolower(s[l]) != tolower(s[r])) return 0;
		l++;
		r--;
	}
	return 1;
}

int main(void)
{
	printf("Вот сюда надо ввести строку:");
	char st[100];
	gets(st);
	if (is_palindrom(st)) printf("+");
	else printf("-");

	return 0;
}
