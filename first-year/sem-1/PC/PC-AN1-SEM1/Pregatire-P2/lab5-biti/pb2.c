#include <stdio.h>
#include <stdint.h>

void showBits(unsigned n)
{
  for(int i=sizeof(n)*8-1;i>=0;i--)
    {
      printf("%d",(n>>i)&1);
    }
  printf("\n");
}

int fct(unsigned a, unsigned b)
{
  unsigned m = 0b1111;
  int count = 0;
  for(int i=0; i<sizeof(a)*8-5; i++)
    {
      showBits(a);
      if((a&m) == b)
	{
	  count++;
	}
      a = a>>1;
    }
  return count;
}

int main(void)
{
  unsigned a,b;
  a = 10516;
  b = 2;

  printf("%d\n", fct(a,b));
  return 0;
}
