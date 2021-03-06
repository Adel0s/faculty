#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void read_random(int v[], int size)
{
  int i = 0;
  for(i=0;i<size;i++)
    {
      v[i] = rand() % 10;
    }
}

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

int delDiv3(int v[], int n)
{
  int i, j;
  for(i=0;i<n;i++)
    {
      if(v[i]%3==0)
	{
	  for(j=i+1;j<n;j++)
	    {
	      v[j-1] = v[j];
	    }
	  n--;
	  i--;
	}
    }
  return n;
}

int main(void)
{
  srand(time(NULL));
  int v[125];
  //read_from_stdin(v,6);
  read_random(v,6);

  int i;
  for(i=0;i<6;i++)
    printf("%d ",v[i]);
  return 0;
}
