/*
Să se scrie un program care citește un număr n<10 iar apoi citește 2 vectori v1 și v2 de câte n elemente de tip int. Pentru citirea elementelor unui vector se folosește o funcție citire(v,n). Se va implementa o funcție egal(v1,v2,n), care testează dacă toate elementele din v1 sunt egale cu cele din v2 la poziții corespondente.
 */

#include<stdio.h>

void citire(int v[], int n)
{
  int i=0;
  for(i=0;i<n;i++)
    {
      scanf("%d",&v[i]);
    }
}

int egal(int v1[], int v2[], int n)
{
  int i=0;
  for(i=0;i<n;i++)
    {
      if(v1[i] != v2[i]) break;
    }
  if(i==n) return 1;
  else return 0;
}

int main(void)
{
  int n, v1[10], v2[10];
  printf("n = ");
  scanf("%d",&n);

  citire(v1,n);
  citire(v2,n);

  printf("%d\n",egal(v1,v2,n));

  if(egal(v1,v2,n))
    {
      printf("Vectorii sunt egali!");
    }
  else
    {
      printf("Vectorii NU sunt egali!");
    }
  
  return 0;
}
