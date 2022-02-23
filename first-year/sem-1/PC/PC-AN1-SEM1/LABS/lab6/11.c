/*
Se citește un număr n<=10 și apoi n numere întregi. Se cere să se șteargă toate duplicatele (ori de câte ori apar acestea) din vector, păstrându-se ordinea elementelor.
 */

#include<stdio.h>

int main(void)
{
  int n, i, j, v[11];
  
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

    for (i = 1; i < n; i++)
    {
      if(v[i-1] == v[i])
	{
	  for(j=i;j<n;j++)
	    {
	      v[j-1] = v[j];
	    }
	  n--;
	  i--;
	}
    }

    for (i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
   printf("\n");

  return 0;
}
