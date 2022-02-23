#include<stdio.h>

int main(void)
{
  int n, a, b, c, cresc = 0 , descresc = 0, egal = 0;
  printf("n = ");
  scanf("%d",&n);
  printf("n = %d\n",n);

  scanf("%d",&a);
  scanf("%d",&b);

  if(a<=b) cresc = 1;
  else if(a>=b) descresc = 1;
  else if(a==b) egal = 1;
  
  for(int i=3;i<=n;i++)
    {
      scanf("%d",&c);
      if(b<=c && cresc) cresc  = 1;
      else cresc = 0;
      if(b>=c && descresc) descresc = 1;
      else descresc = 0;
      if(b==c && egal) egal = 1;
      else egal = 0;
      b = c;
    }
  
  if(cresc) printf("Sirul este crescator\n");
  if(descresc) printf("Sirul este descrescator\n");
  if(egal) printf("Sirul este egal\n");
  
  return 0;
}
