#include <stdint.h>
#include <stdio.h>

void showBits(uint8_t n)
{
  for(int i=sizeof(n)*8-1;i>=0;i--)
    {
      printf("%d",(n>>i)&1);
    }
  printf("\n");
}


uint8_t fct(unsigned a, unsigned b)
{
  uint8_t c = 0;
  unsigned m = 0b1111;

  c |= a&m;
  c|= (b&m)<<4;
  
  return c;
}

int main(void)
{
  unsigned a = 123, b = 67;
  uint8_t c;

  showBits(a);
  showBits(b);

  c = fct(a,b);

  showBits(c);
  
  return 0;
}
