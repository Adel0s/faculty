#include <stdio.h>

int ridicareLogaritmica(int n, int p)
{
  int r = 1;
  while(p)
    {
      if(p%2 == 1) r = r*n;
      n = n*n;
      p = p/2;
    }
  return r;
}

int main(void)
{
  int n, p;
  printf("n = "); scanf("%d", &n);
  printf("p = "); scanf("%d", &p);
  
  printf("%d la puterea %d este egal cu %d\n", n, p, ridicareLogaritmica(n,p));
  return 0;
}
