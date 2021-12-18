/*
Se cere un număr impar n>4. Să se deseneze cifra „8”, scris ca un pătrat cu o linie orizontală în mijloc, în așa fel încât pe 
verticală și pe orizontală să fie câte n steluțe. În program nu vor fi admise duplicări de cod.
 */
#include<stdio.h>

void linieOrizontala(int n)
{
  int i, mij;
  mij = n/2+1;
  for(i=1;i<=n;i++)
    printf("*");
  printf("\n");
}

void linieVerticala(int n)
{
  int i, j;
   for(i = 3; i <= n; i++)
    {
        printf("*");
        for(j=1;j<=n-2;j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
}

int main(void)
{
  int n;
  printf("n = ");
  scanf("%d",&n);
  
  linieOrizontala(n);
  linieVerticala(n);
  linieOrizontala(n);
  
  return 0;
}
