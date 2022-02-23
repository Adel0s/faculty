#include <stdio.h>

void showBits(unsigned n)
{
  for(int i=sizeof(n)*8-1;i>=0;i--)
    {
      printf("%d",(n>>i)&1);
    }
  printf("\n");
}

int palindromBiti(unsigned a)
{
  unsigned m1 = 1, pb, ub;
  unsigned m2 = 1<<(sizeof(a)*8-1);

  int ok = 1;
  
  for(int i=0;i<sizeof(a)*8/2 && ok;i++)
    {
      pb = a & m1;
      ub = a & m2;
      if((pb && !ub) || (!pb && ub)) ok = 0;
      m1 = m1 << 1;
      m2 = m2 >> 1;
    }
  return ok;
}

int main(void)
{
  showBits(2147483649);
  printf("%d\n",palindromBiti(2147483649));
  return 0;
}
