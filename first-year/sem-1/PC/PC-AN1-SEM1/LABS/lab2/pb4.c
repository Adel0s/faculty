#include<stdio.h>

int main()
{
	int n;
	printf("n = ");
	scanf("%d",&n);
	
	while(n!=0)
	{
		if(n<0)
		{
			printf("Error! Introduceti alt numar!\n");
			printf("n = ");
			scanf("%d",&n);
		}
		else
		{
			if(n%2==0) 
			{
				printf("Numarul este par!\n");
				n = 0;
			}
			else 
			{
				printf("Numarul este impar!\n");
				n = 0;
			}
		}
	}
	return 0;
}
