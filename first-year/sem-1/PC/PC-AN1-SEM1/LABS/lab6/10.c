/*Se citește un număr n<=10 și apoi n numere întregi, inclusiv negative. Se cere să se sorteze aceste numere astfel încât numerele pozitive să fie înaintea celorlalte numere.*/

#include<stdio.h>

int main(void)
{
  int n, i, v[11], s, aux;
  
  scanf("%d",&n);


  for (i = 0; i < n; i++)
    {
      scanf("%d", &v[i]);
    }

  for (i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
  printf("\n");

  do
    {
      s=0;
      for(i=1;i<n;i++)
	{
	  if(v[i-1]<0 && v[i]>=0)
	    {
	      aux = v[i-1];
	      v[i-1] = v[i];
	      v[i] = aux;
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
