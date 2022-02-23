/*
Scrieți un program care interschimbă valorile a două variabile de tip întreg utilizând pointeri.
 */

#include<stdio.h>

int main(void)
{
  int a, b, *p;
  printf("a = ");
  scanf("%d",&a);


  printf("b = ");
  scanf("%d",&b);

  p = &a;
  // &a = &b;
  // &b = p;

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  
  return 0;
}
