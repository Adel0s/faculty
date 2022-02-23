#include<stdio.h>
int main()
{
  int an;
  printf("Introduceti anul: ");
  scanf("%d",&an);
  if( an % 400 != 0 && an % 100 == 0)
    {
      printf("Anul introdus NU este an bisect.\n");
    }
  else if(an % 4 == 0 || an % 400 == 0)
    {
      printf("Anul introdus este an bisect.\n");
    }
  return 0;
}
