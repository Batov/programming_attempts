#include <stdio.h>
#include <stdlib.h>

int is_file(int k, char** m, int* n)
{
	int i, is_f = 0;
	if (k == 1) *n = 10;
	else for (i = 1; i <= k - 1; i++)
	{
		if (m[i][1] == 'n')
		{
			*n = m[i + 1][0] - '0';
		}
		if (m[i][1] == 'f') is_f = 1;
	}
	if (is_f) return 1;
	else return 0;
}

void head_for_file(int n)
{
	FILE *f = fopen("input.txt", "r");
	int i;
	char temp_s[128];
	if (f == NULL) printf("!!!");
	i = 0;
	while ((i < n) && (!feof(f)))
	{
		if (fgets(temp_s, 126, f)) printf("%s", temp_s);
		i++;
	}
	fclose(f);
}

void head_for_console(int n)
{
	char st[n][100];
	int i;
	for (i = 0; i < n; i++)
		fscanf(stdin,"%s", st[i]);

	for (i = 0; i < n; i++)
		printf("%s\n", st[i]);
}

int main(int argc, char** argv)
{
	int n;
	if (is_file(argc, argv, &n)) head_for_file(n);
	else head_for_console(n);
	printf("END\n");
	return 0;
}
