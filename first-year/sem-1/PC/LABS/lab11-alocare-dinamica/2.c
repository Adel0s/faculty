/*Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă. Programul va folosi doar minimul necesar de memorie*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int n = 0, i;
  int *v = NULL;
  int *v2;

  printf("Cititi numere pana la intalnirea lui 0!\n");
  scanf("%d",&n);
  while(n!=0)
    {
      i++;
      v2 = (int *)realloc(v, i*sizeof(int));
      if(v2==NULL)
	{
	  printf("Memorie insuficienta!");
	  free(v);
	  return 1;
	}

      v=v2;
      v[i-1] = n;
      scanf("%d",&n);
    }

   for(i=0;i<n;i++)
     {
       printf("%d\n",v[i]);
     }
  
  return 0;
}
