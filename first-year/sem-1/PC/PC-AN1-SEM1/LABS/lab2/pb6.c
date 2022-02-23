#include<stdio.h>
int main()
{
  int a,b;
  printf("a = ");
  scanf("%d",&a);
  
  printf("b = ");
  scanf("%d",&b);

  if(a*b>0)
    {
      printf("Numerele au acelasi semn.\n");
    }
  else
    {
      printf("Numerele au semne diferite.\n");
    }
  return 0;
}
