/*
Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. Să se calculeze pentru fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele.
 */

#include <stdio.h>
#include <string.h>

typedef struct{
  char nume[20];
  float cantitate, pret;
}Cuvant;

Cuvant cuvinte[100];
int nCuvinte;

Cuvant *cauta(char *txt)
 {
   for(int i=0;i<nCuvinte;i++)
     {
       if(strcmp(cuvinte[i].txt,txt)==0)return &cuvinte[i];
     }
   return NULL;
 } 

int main(void)
{
  int n, i;
  scanf("%d", &n);
  getchar();

  for(i=0; i<n; i++)
    {
      fgets(cuvinte[i].nume,20,stdin);
      scanf("%f",&cuvinte[i].cantitate);
      scanf("%f",&cuvinte[i].pret);
      getchar();

    }

  for(i=0; i<n; i++)
    {
      printf("%s\n",cuvinte[i].nume);
      printf("%f\n",cuvinte[i].cantitate);
      printf("%f\n",cuvinte[i].pret);
    }
  return 0;
}
