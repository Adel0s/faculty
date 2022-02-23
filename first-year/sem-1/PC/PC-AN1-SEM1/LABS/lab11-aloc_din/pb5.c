#include <stdio.h>
#include <stdlib.h>

void BubbleSort(uint *v, uint n)
{
	int s,i,aux;
	do{
	  s = 0;
	  for (i = 1; i < n; i++)
	    {
	      if (v[i - 1] < v[i])
		{
		  aux = v[i - 1];
		  v[i - 1] = v[i];
		  v[i] = aux;
		  s = 1;
		}
	    }
	} while (s);
}

int main(void)
{
  uint x;
  char value[100];
  uint nrValori = 0;
  uint *p = NULL;
  uint *v;

  while(fgets(value,100,stdin))
    {
      x = strtol(value,NULL,10);
      nrValori++;
      p = realloc(p,sizeof(uint)*nrValori);

      if(p == NULL)
	{
	  printf("Memorie insuficienta!\n");
	  return 0;
	}
      v = p;
      v[nrValori-1] = x;
    }

  BubbleSort(v,nrValori);
  
  for(int i=0;i<nrValori;i++)
    {
      printf("v[%d] = %u\n",i,v[i]);
    }
  
  return 0;
}
