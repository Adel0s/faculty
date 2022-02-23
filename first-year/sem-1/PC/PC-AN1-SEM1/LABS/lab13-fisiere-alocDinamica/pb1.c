/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea configurație (cap de tabel)

year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code

Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget.

Fișierul de test poate fi descărcat folosind urmatoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/movies.csv
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *titlu;
  int an, buget;
}FILM;

int nFilme = 0;

char *getLine(FILE *f)
{
  int size = 0, i = 0;
  char ch = 0;
  char *linie = NULL;

  ch = fgetc(f);
  while(ch != EOF)
    {
      size++;
      linie = (char*)realloc(linie, size*sizeof(char));

      if(ch == '\n')
	{
	  linie[i] = '\0';
	  break;
	}
      linie[i] = ch;
      i++;
      ch = fgetc(f);
    }
  return linie;
}

FILM transformFilm(char *linie)
{
  FILM film;
  char *p = strtok(linie, ",");
  film.an = strtol(p, NULL, 10);

  p = strtok(NULL, ",");
  p = strtok(NULL, ",");
  film.titlu = (char*)malloc((strlen(p) + 1)*sizeof(char));
  strcpy(film.titlu, p);

  for(int i = 0; i<4; i++)
    {
      p = strtok(NULL, ",");
    }
  film.buget = strtol(p,NULL,10);
  return film;
}

FILM *getFilme(FILE *f)
{
  int size = 0;
  char *linie = NULL;
  FILM film;
  FILM *filme = NULL;

  linie = getLine(f);
  while(linie != NULL)
    {
      film = transformFilm(linie);
      size++;
      filme = (FILM *)realloc(filme, size*sizeof(FILM));

      filme[nFilme] = film;
      nFilme++;
      free(linie);
      linie = getLine(f);
    }
  return filme;
}

void curataFilme(FILM *filme)
{
  for(int i = 0; i<nFilme; i++)
    {
      free(filme[i].titlu);
    }
  free(filme);
}

void printareFilme(FILM *filme)
{
  for(int i=0;i<nFilme;i++)
    {
      printf("%d -> %s(%d) - %d\n", i, filme[i].titlu, filme[i].an, filme[i].buget);
    }
}

void sortareAn(FILM *filme)
{
  FILM aux;
  for(int i=0; i<nFilme; i++)
    {
      for(int j=i+1;j<nFilme;j++)
	{
	  if(filme[i].an>filme[j].an)
	    {
	      aux = filme[i];
	      filme[i] = filme[j];
	      filme[j] = aux;
	    }
	}
    }
}
void printareFilmeAn(FILM *filme)
{
  FILE  *fout;
  fout = fopen("out1.txt","w");
  for(int i=0;i<nFilme;i++)
    {
      //printf("%d -> %s - %d\n", filme[i].an, filme[i].titlu, filme[i].buget);
      fprintf(fout,"%d -> %s - %d\n", filme[i].an, filme[i].titlu, filme[i].buget);
    }
}

void sortareTitlu(FILM *filme)
{
  FILM aux;
  for(int i=0; i<nFilme; i++)
    {
      for(int j=i+1;j<nFilme;j++)
	{
	  if(strcmp(filme[i].titlu,filme[j].titlu) >= 1)
	    {
	      aux = filme[i];
	      filme[i] = filme[j];
	      filme[j] = aux;
	    }
	}
    }
}
void printareFilmeTitlu(FILM *filme)
{
  FILE  *fout;
  fout = fopen("out2.txt","w");
  for(int i=0;i<nFilme;i++)
    {
      //printf("%s -> %d - %d\n", filme[i].titlu, filme[i].an, filme[i].buget);
      fprintf(fout,"%s -> %d - %d\n", filme[i].titlu, filme[i].an, filme[i].buget);
    }
}

void sortareBuget(FILM *filme)
{
  FILM aux;
  for(int i=0; i<nFilme; i++)
    {
      for(int j=i+1;j<nFilme;j++)
	{
	  if(filme[i].buget>filme[j].buget)
	    {
	      aux = filme[i];
	      filme[i] = filme[j];
	      filme[j] = aux;
	    }
	}
    }
}
void printareFilmeBuget(FILM *filme)
{
  FILE  *fout;
  fout = fopen("out2.txt","w");
  for(int i=0;i<nFilme;i++)
    {
      printf("%d -> %s - %d\n", filme[i].buget, filme[i].titlu, filme[i].buget);
      fprintf(fout,"%d -> %s - %d\n", filme[i].buget, filme[i].titlu, filme[i].buget);
    }
}

int main(void)
{
  char *linie = NULL;
  FILM *filme = NULL;
  FILE *f = NULL;

  f = fopen("movies.csv", "r");
  if(f == NULL)
    {
      printf("NU pot citi din fisier!\n");
      exit(EXIT_FAILURE);
    }

  linie = getLine(f);
  free(linie);
  linie = NULL;

  filme = getFilme(f);
  printareFilme(filme);
  
  sortareAn(filme);
  printareFilmeAn(filme);

  sortareTitlu(filme);
  printareFilmeTitlu(filme);

  sortareBuget(filme);
  printareFilmeBuget(filme);
  
  curataFilme(filme);
  return 0;
}
