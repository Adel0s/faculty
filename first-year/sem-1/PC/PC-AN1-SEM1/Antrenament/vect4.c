#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define N 128

void read_from_stdin(int v[], int size)
{
  int n = 0, i = 0;
  while(scanf("%d", &n) != EOF)
    {
      if(i<size)
	{
	  v[i] = n;
	}
      i++;
    }
}

void print_array(int v[],int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%d ",v[i]);
    }
}

void functie(uint16_t *v1, uint16_t *v2, uint16_t n, uint16_t m)
{
  int i;
  uint16_t aux;
  for(i=0;i<=n;i++)
    {
      /*aux = *(v1+i);
      *(v1+i) = *(v2+i);
      *(v2+i) = aux;*/
    }
}

int main(void)
{
  int v1[N],v2[N];
  read_from_stdin(v1,3);
  read_from_stdin(v2,3);
  functie(&v1,&v2,1,2);
  print_array(v1,3);
  printf("\n");
  print_array(v2,3);
  return 0;
}
