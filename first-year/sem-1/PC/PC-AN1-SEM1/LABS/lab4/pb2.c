/*
Să se scrie o funcție care returnează maximul dintre 3 valori de tip intreg, primite ca parametri. Funcția nu va folosi nicio 
variabilă, cu excepția parametrilor săi. Se va testa funcția cu valori introduse de la tastatură. Citirea de la tastatura se 
va face in functia main.
 */

#include<stdio.h>

int maxim(int a, int b, int c)
{
  if(a>=b && a>=c) return a;
  else if(b>=a && b>=c) return b;
  else if(c>=a && c>=b) return c;
  else return a;
}

int main(void)
{
  int a, b ,c;
  printf("a = ");
  scanf("%d",&a);
  
  printf("b = ");
  scanf("%d",&b);
  
  printf("c = ");
  scanf("%d",&c);
  
  int r = maxim(a,b,c);
  printf("%d\n",r);
  return 0;
}
