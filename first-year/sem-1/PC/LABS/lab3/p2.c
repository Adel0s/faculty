#include <stdio.h>

int main()
{
	int n, i=0, s=1;
	
	printf("n = ");
	scanf("%d",&n);
	
	printf("1");
	
	for(i=2;i<=n;i++)
	{
		s = s + i;
		printf(" + %d",i);
	}
	printf(" = %d\n",s);
	return 0;
}
