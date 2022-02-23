#include<stdio.h>

int main()
{
  int n, imp=0;
  printf("n = ");
  scanf("%d", &n);

  while(n!=0)
    {
      if(n%2 == 1)imp++;
      n=n/10;
    }
  printf("Numarul contine %d cifre impare\n",imp);
  return 0;
}
