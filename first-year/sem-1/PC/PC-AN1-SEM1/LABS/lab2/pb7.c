#include<stdio.h>
int main()
{
  int n, i, c=0;
  printf("n = ");
  scanf("%d",&n);
  
  if(n%2==0) n = n-1;
  
  for(i=n-2;i>1;i=i-2)
  {
    if(c>=2)
      {
	break;
      }
    else
      {
	printf("%d ",i);
	c++;
      }
  }
  return 0;
}
