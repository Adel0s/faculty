/*

Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții. Exemplu:

a - 16 %
b - 2 %
c - 17.8 %
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double procent(long long aparitii, long long total)
{
  double proc = aparitii * 100 / (double)total;
  return proc;
}

void afisare_procent(FILE *f)
{
  long long total = 0, aparitii[124];
  char ch = 0;
  int i = 0;

  for(int i=0; i<124; i++)
    {
      aparitii[i] = 0;
    }

  while((ch = fgetc(f)) != EOF)
    {
      if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
	  total++;
	  aparitii[(int)ch]++;
	}
    }

  for(i = 'a'; i <= 'z'; i++)
    {
      printf("%c -> %f%%\n", i, procent(aparitii[i],total));
    }

  printf("\n\n\n");

  for(i = 'A'; i <= 'Z'; i++)
    {
      printf("%c -> %f%%\n", i, procent(aparitii[i],total));
    }
}

int main(void)
{
  FILE *f;
  f = fopen("histograma.txt", "r");
  afisare_procent(f);
  return 0;
}
