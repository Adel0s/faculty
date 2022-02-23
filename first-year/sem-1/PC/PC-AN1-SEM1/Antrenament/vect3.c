#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>

#define N 4

void showBits(uint32_t a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

void read_random(int v[], int size)
{
  int i = 0;
  for(i=0;i<size;i++)
    {
      v[i] = rand() % 100001;
    }
}


void print_array(int v[],int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%d ",v[i]);
    }
}

int functie(uint32_t v[],int size)
{
  uint16_t n1, n2, rez;
  for(int i=0;i<size;i++)
    {
      n1 = v[i]>>16;
      n2 = (v[i]<<16)>>16;
    }
}

int main(void)
{
  srand(time(NULL));
  int v[N];
  read_random(v,N);
  print_array(v,N);
  printf("\n");
  return 0;
}
