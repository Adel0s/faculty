/*

Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea configurație (cap de tabel)

year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code

Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget.

Fișierul de test poate fi descărcat folosind urmatoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/movies.csv

Se vor realiza mai multe variante de procesare si extragere de informații dintr-o linie de date: folosind strtok, folosind strchr, agloritm propriu prin parcurgere caracter cu caracter a unei linii deja citite din fișier.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

typedef struct
{
  char *title;
  int year;
  int budget;
}MOVIE;

int nMovies = 0;
MOVIE *movies = NULL;

char *getLine(FILE *f)
{
  int size = 0, i = 0;
  char ch = 0, *line = NULL;
  while((ch = fgetc(f)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  line = (char*)realloc(line, size * sizeof(char));
	}

      if(ch == '\n')
	{
	  line[i] = '\0';
	  break;
	}
      line[i++] = ch;
    }
  return line;
}

MOVIE transformMovie(char *line)
{
  MOVIE movie;
  char *p = NULL;
  p = strtok(line, ",");
  movie.year = strtol(p, NULL, 10);

  p = strtok(NULL, ",");
  p = strtok(NULL, ",");

  movie.title = (char*)malloc((strlen(p)+1) * sizeof(char));
  strcpy(movie.title, p);
  for(int i=0;i<3;i++)
    {
      p = strtok(NULL, ",");
    }

  p = strtok(NULL, ",");
  movie.budget = strtol(p, NULL, 10);
  return movie;
}

MOVIE *getMovies(FILE *f)
{
  MOVIE movie;
  MOVIE *movies = NULL;
  char *line;
  int size = 0;

  while((line = getLine(f)) != NULL)
    {
      movie  = transformMovie(line);
      if(nMovies == size)
	{
	  size += ARRAY_CHUNK;
	  movies = (MOVIE *)realloc(movies, size*sizeof(MOVIE));
	}

      movies[nMovies] = movie;
      nMovies++;
      
      free(line);
      line = NULL;
    }
  return movies;
}

void freeMovies(MOVIE *movies)
{
  for(int  i=0; i<nMovies; i++)
    {
      free(movies[i].title);
    }
  free(movies);
}

void printMovies(MOVIE *movies)
{
  for(int i=0; i<nMovies; i++)
    {
      printf("%d) %s (%d) -> %d\n", i, movies[i].title, movies[i].year, movies[i].budget);
    }
}

void yearSort(MOVIE *movies)
{
  MOVIE movie;
  for(int i=0;i<=nMovies;i++)
    {
      for(int j=i+1;j<nMovies;j++)
	{
	  if(movies[i].year > movies[j].year)
	    {
	      movie = movies[i];
	      movies[i] = movies[j];
	      movies[j] = movie;
	    }
	}
    }
}

int main(void)
{
  FILE *f = NULL;
  f = fopen("movies.csv", "r");
  if(f == NULL)
    {
      printf("NU pot citi din fisier!\n");
      exit(EXIT_FAILURE);
    }

  movies = getMovies(f);
  printMovies(movies);
  yearSort(movies);
  printMovies(movies);
  return 0;
}
