#include<stdio.h>
int main()
{
  float x, y;
  printf("x = ");
  scanf("%f",&x);

  printf("y = ");
  scanf("%f",&y);

  if(x*5 + y*7 <= 20)
    {
      printf("Suma de 20 de lei este de ajuns!\n");
    }
  else
    {
      printf("Suma de 20 de lei NU este de ajuns!\n");
    }
  return 0;
}
