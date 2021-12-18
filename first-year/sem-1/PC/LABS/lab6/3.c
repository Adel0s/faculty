/*
Să se citească de la tastatură un număr n<=10 iar apoi n valori de tip int. Să se afișeze dacă toate valorile pozitive sunt pare.
 */

#include<stdio.h>

int main(void)
{
  int n, i, v[11];
  scanf("%d", &n);

  for(i=0;i<n;i++)
    scanf("%d",&v[i]);
  
  for(i=0;i<n;i++)
    {
      if(v[i]>=0)
	{
	  if(v[i]%2!=0) break;
	}
    }

  if(i==n) printf("Toate valorile pozitive sunt pare!\n");
  else printf("NU toate valorile pozitive sunt pare!\n");
  
  return 0;
}
