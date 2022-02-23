/*
Să se citească de la tastatură un număr n<=5 iar apoi n valori de tip intreg. Să se afișeze toate valorile ale căror modul (valoare absolută) este strict mai mare decat 10.
 */
#include<stdio.h>

int abs(int n)
{
  if(n<0) n=-n;
  return n;
}

int main()
{
  int n, i, v[6];
  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&v[i]);
  
  for(i=0;i<n;i++)
    {
      if(abs(v[i]) > 10) printf("%d ", v[i]);
    }
  return 0;
}
