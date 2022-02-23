/*
Se citește un număr n<=10 și apoi n numere întregi. Se cere să se șteargă din vector toate acele elemente care sunt urmate de un număr strict mai mare decât ele, păstrându-se ordinea elementelor
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

  for(i=0;i<n-1;i++)
    {
      if(v[i]<v[i+1])
	{
	  for(j=i+1;j<n;j++)
	    {
	      v[j-1] = v[j];
	    }
	  n--;
	  i--;
	}
    }

  for(i=0;i<n;i++)
    {
      printf("%d ",v[i]);
    }
  
  return 0;
}
