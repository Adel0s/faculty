/*
Se citesc două variabile, a și b, de tip întreg. Să se stocheze într-un pointer adresa variabilei care conține valoarea maximă și apoi să se afișeze valoarea pointată
 */
#include<stdio.h>

int main(void)
{
  int a, b, *pmax;
  printf("a = ");
  scanf("%d",&a);

  printf("b = ");
  scanf("%d",&b);

  if(a>b) pmax = &a;
  else pmax = &b;

  printf("%d\n",*pmax);
  
  return 0;
}
