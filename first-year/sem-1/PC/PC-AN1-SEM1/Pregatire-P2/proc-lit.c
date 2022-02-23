/*
Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții. Exemplu:

a - 16 %
b - 2 %
c - 17.8 %

Fișierul de test se poate descărca folosind următoarea comandă: wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double procent(long long nr, long long total)
{
  double proc = nr * 100 / (double)total;
  return proc;
}

void histograma(FILE *in)
{
  char cuv[100];
  long long total = 0, aparitii[123];
  int i = 0;

  for(i = 0; i<123; i++) aparitii[i] = 0;

  while(fscanf(in, "%s", cuv) != EOF)
    {
      for(i=0; i<strlen(cuv); i++)
	{
	  if((cuv[i] >= 'a' && cuv[i] <= 'z') || (cuv[i] >= 'A' && cuv[i] <= 'Z'))
	    {
	      total++;
	      aparitii[(int)cuv[i]]++;
	    }
	}
    }

  for(i = 'a'; i <= 'z'; i++)
    {
      printf("%c : %f%%\n", i, procent(aparitii[i], total));
    }

  for(i = 'A'; i <= 'Z'; i++)
    {
      printf("%c : %f%%\n", i, procent(aparitii[i], total));
    }
}

int main(void)
{
  FILE *in = NULL;
  in = fopen("scrisoare.txt", "r");
  histograma(in);
  return 0;
}
