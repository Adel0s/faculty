#include<stdio.h>

int main(void)
{
  int n, b, r;
  printf("n = ");
  scanf("%d",&n);
  printf("baza = ");
  scanf("%d",&b);

  /* while(n!=0)
    {
      r = n%b;
      printf("%d",r);
      n=n/b;
      }*/

  while(n != 0)
    {
      r = n%b;
      if(r==10) printf("A");
      else if(r==11) printf("B");
      else if(r==12) printf("C");
      else if(r==13) printf("D");
      else if(r==14) printf("E");
      else if(r==15) printf("F");
      else printf("%d",r);
      n=n/b;
    }
  return 0;
}
