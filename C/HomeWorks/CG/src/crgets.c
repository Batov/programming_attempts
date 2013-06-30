/*
 ============================================================================
 Name        : Crack gets
 Author      : Batov
 ============================================================================
 */

#include <stdio.h>

int main()
{
	printf(">>>");
	char buf[3];
	char c[1];
	c[1] = ' ';
	gets(buf);
	if (c[1] == ' ') printf("No");
	else printf("Yes");
	return 0;
}
