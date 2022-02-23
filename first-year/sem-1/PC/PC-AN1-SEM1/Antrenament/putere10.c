#include <stdio.h>

int main()
{
  int n = 0, nrc = 0, uc=0, og = 0;
  printf("Introduceti valoarea lui n: ");
  scanf("%d",&n);
  printf("n are valoarea %d\n",n);

  while(n!=0)
    {
      og=og*10+n%10;
      n=n/10;
      nrc++;
    }
  nrc--;

  uc = og%10;
  og = og/10;
  printf("%d*10^%d",uc,nrc);
  nrc--;
  
  while(og!=0)
    {
      uc = og%10;
      printf(" + %d*10^%d",uc,nrc);
      nrc--;
      og=og/10;
    }
  printf("\n");
  
  return 0;
}
