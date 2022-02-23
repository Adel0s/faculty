/*Se citește un număr n<=10 și apoi n numere întregi. Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.*/

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

  for (i = 0; i < n; i++)
    {
      for(j=n;j>i;j--)
	{
	  v[j] = v[j-1];
	}
      v[i+1] = v[i]*v[i];
      n++;
      i++;
    }

   for (i = 0; i < n; i++)
    {
      printf("%d ", v[i]);
    }
  printf("\n");
  return 0;
}
