#include<stdio.h>
int main()
{
	float x,y;
	printf("x = ");
	scanf("%f",&x);

	printf("y = ");
	scanf("%f",&y);

	printf("1) Maximul dintre x si y\n 2) Minimul dintre x si y\n 3) x\n 4) y\n");

	int o = 0;
	printf("Alegeti operatia dorita:");
	scanf("%d",&o);

	if(o==1)
	{
		if(x>y) printf("%f", x);
		else printf("%f\n", y);
	}
	else if(o==2)
	{
		if(x<y) printf("%f", x);
		else printf("%f\n", y);
	}
	else if(o==3)
	{
		printf("%f\n", x);
	}
	else if(o==4)
	{
		printf("%f\n", y);
	}

  
  return 0;
}
