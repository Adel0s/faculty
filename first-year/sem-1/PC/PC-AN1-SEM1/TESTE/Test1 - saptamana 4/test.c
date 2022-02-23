#include<stdio.h>

int main(void)
{
  int n, i, j;
  printf("n = ");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
      printf("%d: ",i);
      if(i%2==0)
	{
	  for(j=1;j<=i/2;j++)
	    {
	      printf("%d ",j);
	    }
	}
      else if(i%2==1)
	{
	  for(j=1;j<=i;j++)
	    {
	      printf("%d ",j);
	    }
	}
      printf("\n");
    }
  
  return 0;
}
