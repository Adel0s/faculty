/*
Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă. Programul va folosi doar minimul necesar de memorie
 */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x, nValori=0;
  printf("x = ");
  scanf("%d",&x);
  
  int *v = NULL;
  int *v2;
  
  while(x != 0)
    {
      nValori++;
      v2 = (int*)(realloc(v,nValori*sizeof(int)));
      if(v2 == NULL)
	{
	  printf("Memorie insuficienta!\n");
	  free(v);
	  return 0;
	}

      v = v2;
      v[nValori-1] = x;
      
      printf("x = ");
      scanf("%d",&x);
    }

  for(int i=nValori-1;i>=0;i--)
    {
      printf("v[%d] = %d\n",i,v[i]);
    }
  return 0;
}
