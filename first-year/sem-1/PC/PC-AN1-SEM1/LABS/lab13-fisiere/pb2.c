/*
Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0. Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o singură linie, separate prin | (bară verticală).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *out = NULL;
  int n, aux, sort, i=0, v[100];
  
  scanf("%d",&n);
  while(n!=0)
    {
      v[i] = n;
      i++;
      scanf("%d",&n);
    }

  n=i;

  do{
    sort = 0;
    for(i=1;i<n;i++)
      {
	if(v[i-1] > v[i])
	  {
	    sort = 1;
	    aux = v[i-1];
	    v[i-1] = v[i];
	    v[i] = aux;
	  }
      }
    
  }while(sort);

  if((out = fopen("out.txt", "w")) == NULL)
    {
      perror(NULL);
      return 0;
    }

  for(i=0;i<n;i++)
    {
      if(i==0)
	fprintf(out, "%d", v[i]);
      else
	fprintf(out, " | %d", v[i]);
    }
  
  return 0;
}
