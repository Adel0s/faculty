/*
Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere astfel încât numerele impare să fie înaintea celor pare
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  int n, i, v[11], s, aux;
  
  scanf("%d",&n);


  for (i = 0; i < n; i++)
    {
      scanf("%d", &v[i]);
    }

  do
    {
      s=0;
      for(i=1;i<n;i++)
	{
	  if(v[i]%2 == 1 && v[i-1]%2 == 0 )
	    {
	      aux  = v[i];
	      v[i] = v[i-1];
	      v[i-1] = aux;
	      s=1;
	    }
	}
    }while(s);

  for (i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
  
  return 0;
}
