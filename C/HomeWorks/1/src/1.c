
/*
 ============================================================================
 Name        : Факториал итерация
 Author      : Batov
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n;
	int res;
	int i;
	scanf("%d",&n);
	if (n<0) puts("-");
	else
	{
		res=1;
		for(i=0;i<n;i++)
		{
			res=res*(i+1);
		}
		printf("%d",res);
	}

	return 0;
}
