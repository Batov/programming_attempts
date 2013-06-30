/*
 ============================================================================
 Name        : Произведения без "*"
 Author      : Batov
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b,i,res;

	scanf("%d",&a);
	scanf("%d",&b);

	res=0;
	for(i=1;i<=abs(b);i++)
	{
		res=res+abs(a);
	}
	if ((a<0 && b>0)||(a>0 && b<0))
			res=0-res;

	printf("%d",res);
	return 0;
}
