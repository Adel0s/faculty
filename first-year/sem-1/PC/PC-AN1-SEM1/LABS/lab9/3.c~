/*Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. Să se afișeze de câte ori apare fiecare nume*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
  char nume[50], matrice_nume[10][50];
  int n, i, j, frecventa[10];
  printf("Introduceti cate nume se vor citi: ");
  scanf("%d", &n);

  for(i=0; i<n; i++)
    {
      frecventa[i] = 0;
    }

  for(i=0; i<n; i++)
    {
      scanf("%s",nume);
      strcpy(matrice_nume[i], nume);
    }

  for(i=0; i<n-1; i++)
    {
      for(j=i+1;j<n;j++)
	{
	  if(matrice_nume[i] == matrice_nume[j]) frecventa[i]++;
	}
    }

    for(i=0; i<n; i++)
    {
        printf("Numele %s apare de %d ori.\n", matrice_nume[i], frecventa[i]);
    }
  return 0;
}

/*
REZOLVARE DE LA ROBY
#include<stdio.h>
#include<string.h>
#define FOR(n) for(i=0; i<n; i++)
char numeuri[15][20];
int exista(char s[], int nn)
{
  int i;
  char s2[20];
  //printf("NN: %d\n", nn);
  FOR(nn+1)
    {
      strcpy(s2, numeuri[i]);
      //printf("Sir: %s si %s\n",numeuri[i],s);
      if(strcmp(s, s2) == 0)
	 return i + 1;
    }
  //printf("Nu exista\n");
      return 0;
}
int main()
{
  int n, i, nn=-1, cate[20];
  char nume[20];
  scanf("%d",&n);
  FOR(n)
    {
      scanf("%s", nume);
      getchar();
      if(exista(nume, nn))
	{
	  //printf("%d %d\n",exista(nume, nn), nn);
	  cate[exista(nume, nn) - 1]++;
	}
      else
	{
	  strcpy(numeuri[++nn], nume);
	  cate[nn] = 1;
	}
    }
  FOR(nn+1)
    {
      printf("%s apare de %d ori\n",numeuri[i], cate[i]);
    }
}
 */
