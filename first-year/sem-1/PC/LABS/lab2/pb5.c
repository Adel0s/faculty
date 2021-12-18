#include<stdio.h>

int main()
{
	int opt = 0;
	float x, y, r;
	printf("1) Adunare\n 2) Scadere\n 3) Inmultire\n 4) Impartire\n 5) Iesire\n Alegeti optiunea dorita: \n");
	scanf("%d", &opt);
	
	if(opt==1)
	{
		printf("x = ");
		scanf("%f",&x);
		
		printf("y = ");
		scanf("%f",&y);
		r = x+y;
		printf("x + y = %f", r);
	}
	else if(opt==2)
	{
		printf("x = ");
		scanf("%f",&x);
	       
		printf("y = ");
		scanf("%f",&y);
		r = x-y;
		printf("x - y = %f", r);
	}
	else if(opt==3)
	{
		printf("x = ");
		scanf("%f",&x);
		printf("\n");
		printf("y = ");
		scanf("%f",&y);
		r = x*y;
		printf("x * y = %f", r);
	}
	else if(opt==4)
	{
		printf("x = ");
		scanf("%f",&x);
		
		printf("y = ");
		scanf("%f",&y);
		r = x/y;
		printf("x / y = %f", r);
	}
	else if(opt==5)
	{
		return 0;
	}	
	return 0;
}
