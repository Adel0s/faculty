/*
Se citește un număr n<=10 și apoi n numere pozitive. Se cere să se insereze înainte de fiecare valoare impară din vectorul original valoarea 0.
 */

#include<stdio.h>

int main(void)
{
  int n, i, j, v[11];
  scanf("%d", &n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&v[i]);
    }
  
  for(i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
  
   for(i=0;i<n;i++)
    {
      if(v[i]%2==1)
	{
	  for(j=n;j>i;j--)
	    {
	      v[j] = v[j-1];
	    }
	  v[i] = 0;
	  n++;
	  i++;
	}
    }

   for(i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
   
  return 0;
}
