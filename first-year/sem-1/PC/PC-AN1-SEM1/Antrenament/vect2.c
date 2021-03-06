#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 128

void read_random(int v[], int size)
{
  int i = 0;
  for(i=0;i<size;i++)
    {
      v[i] = rand() % 100001;
    }
}

int count_bit1(int n)
{
  int c=0;
  while(n)
    {
      if(n&1) c++;
      n=n>>1;
    }
  return c;
}

int count_in_array(int v[],int n)
{
  int i=0, rez=0;
  for(i=0;i<n;i++)
    {
      rez = rez + count_bit1(v[i]);
    }
  return rez;
}

void print_array(int v[],int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%d ",v[i]);
    }
}

int main(void)
{
  srand(time(NULL));
  int v[N];
  read_random(v,N);
  print_array(v,N);
  printf("\n");
  printf("%d\n",count_in_array(v,N));
  return 0;
}
