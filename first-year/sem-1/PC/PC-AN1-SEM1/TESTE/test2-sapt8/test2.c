#include<stdio.h>

void showBits(int a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}


int countBits(int a){
  int nrBits = 0;
  while(a)
    {
      nrBits++;
      a = a>>1;
    }
  return nrBits;
}

int functie(int n, int k)
{
  int mask = n>>(k-1);
  
  return mask & 1;
}

int simetric(int n)
{
  int biti = countBits(n);
  int m1,m2;
  m1 = 1<<(biti-1);
  m2 = 0x0001;

  int ok = 1;

  while(m1)
    {
      if( (m1&n) != (m2&n) )
	{
	  ok = 0;
	  break;
	}
      m1 = m1>>1;
      m2 = m2<<1;
    }
  
  if(ok)
    {
      return 1;
    }
  else return 0;
}

int main(void)
{
  int a, k;

  scanf("%d",&a);
  scanf("%d",&k);
  
  printf("Nmarul are %d cifre binare\n",countBits(a));
  printf("Bitul de ordin %d este %d \n",k,functie(a,4));
  
  printf("Este simetric numarul? %d\n",simetric(a));
  return 0;
}
