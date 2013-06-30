//Lupachev E.
//tail

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 100

char* read_string(FILE* f)
{
	int i = 0, l = 200, is_eof;
	char* string;

	is_eof = fgetc(f);
	if(is_eof + 1)
	{
		char* string = (char*)malloc(M * sizeof(char));
		while((is_eof != '\n') && (is_eof != EOF))
		{
			string[i] = is_eof;
			i++;
			is_eof = fgetc(f);
			if(i % M == M - 1)
				{
					string = (char*)realloc(string, l * sizeof(char));
					l = l + M;
				}
		}
		string[i] = '0';
	}
	else
	{
		return NULL;
	}
		/*if(string[i] == EOF)
		{
			if(string[0] == EOF)
			{
				string[0] = 0;
			}
			else
			{
				string[i+1] = 0;
			}
			is_eof = 1;
			break;
		}*/

	return string;
}
void read_file(char *way, int n)
{
	int i = 0, k = 0, j = 0;
	char* string= malloc(256);
	FILE* f;
	if (strcmp(way, "stdin"))
	{
		f = fopen(way, "r");
		if (f== NULL) help();
	}
	else
	{
		f = stdin;
	}
	char ** arrstring = malloc(n * sizeof(char));

	//string = read_string(f);
	fgets(string,256,f);
	while(string != NULL)
	{
		if(i < n)
		{
			//printf("2");
			arrstring[i] = string;
			k++;
			i++;
		}
		else
		{
			//printf("3");
			for (j = 0; j < n - 1; j++)
			{
				arrstring[j] = arrstring[j + 1];
			}
			arrstring[n] = string;
			i++;
		}
		//printf("5");
		//string = read_string(f);
		fgets(string,25,f);
	}

	printf("Out");
	for(i = 0; i < k; i++)
	{
		printf("Print");
		printf("%d   %s\n", i+1, arrstring[i]);
		free(arrstring[i]);
	}

	free(arrstring);
	free(string);
}
void help()
{
	printf( "****************************************************\n"
			"*Input error.                                      *\n"
			"*Plese, check your commands.                       *\n"
			"*It must look like: tail.exe -n 5 name_of_file     *\n"
			"****************************************************");
}
int main (int argc, char* argv[])
{
	int n = 10;
	char* way;
	if(argc == 1)
	{
		n = 10;
		way = "stdin";
	}
	if(argc == 2)
	{
		if(strcmp(argv[1], "-n"))
		{
			n = 10;
			way = argv[1];
		}
		else
		{
			help();
			return 0;
		}
	}
	if(argc == 3)
	{
		if((!strcmp(argv[1],"-n")) && (!isalpha(argv[2][0])))
		{
			n = atoi(argv[2]);
			way = "stdin";
		}
		else
		{
			help();
			return 0;
		}
	}
	if(argc == 4)
	{
		if(!strcmp(argv[1],"-n"))
		{
			n = atoi(argv[2]);
			way = argv[3];
		}
		else
		{
			n = atoi(argv[3]);
			way = argv[1];
		}
	}
    read_file(way, n);

		return 0;
}
