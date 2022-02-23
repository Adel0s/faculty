/*Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) și să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.*/
#include<stdio.h>

int main(void)
{
  double d1, d2;
  double *p1, *p2;
  
  printf("d1 = ");
  scanf("%lf",&d1);

  printf("d2 = ");
  scanf("%lf",&d2);

  p1 = &d1;
  p2 = &d2;
  
  printf("%p\n",p1);
  printf("%p\n",p2);

  if(p1<p2) printf("%lf\n",d1);
  else printf("%lf\n",d2);
  
  return 0;
}
