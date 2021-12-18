#include<stdio.h>
int main()
{
  int i,j,p;
  for(i=0;i<=10;i++)
    {
      for(j=0;j<=10;j++)
	{
	  p=i*j;
	  printf("%d * %d = %d \n", i,j,p);
	}
      printf("\n");
    }
  return 0;
}
