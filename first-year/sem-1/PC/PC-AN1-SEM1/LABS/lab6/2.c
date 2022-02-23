/*
Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8}
 */

#include<stdio.h>

int main(void)
{
  int i, min;
  int v[] = {7, -5, 4, 3, -9, 2, -8};
  min = v[0];

  for(i=0;i<7;i++)
    if(v[i]<min) min = v[i];

  printf("%d\n",min);
  return 0;
}
