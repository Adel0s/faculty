/*

Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea configurație (cap de tabel)

year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code

Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget.

Fișierul de test poate fi descărcat folosind urmatoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/movies.csv
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
  int year;
  int budget;
  char *title;
}MOVIE;

MOVIE *movies = NULL;
int nMovies = 0;

void eliberareMovie(int idx)
{
  free(movies[idx].title);
}

void eliberare()
{
  for(int i=0; i<nMovies; i++)
    {
      eliberareMovie(i);
    }
  free(movies);
}

char *getLine(FILE *f)
{
  char ch = 0;
  char *line = NULL;
  int size = 0, i = 0;

  ch = fgetc(f);
  while(ch != EOF)
    {
      if(i == size)
	{
	  size++;
	  line = realloc(line, size*sizeof(char));
	}

      if(ch == '\n')
	{
	  line[i] = '\0';
	  break;
	}
      line[i++] = ch;
      ch = fgetc(f);
    }
  return line;
}

char **getLines(FILE *f)
{
  int size = 0, i = 0;
  char *line = NULL, **lines = NULL;

  line = getLine(f);
  while(line != NULL)
    {
      if(i==size)
	{
	  size++;
	  lines = realloc(lines, size * sizeof(char *));
	}
      lines[i++] = line;

      if(i==size)
	{
	  size++;
	  lines = realloc(lines, size*sizeof(char *));
	}
      lines[i] = NULL;
      line = getLine(f);
    }
  return lines;
}

void printLines(char **lines)
{
  int i = 0;
  while(lines[i] != NULL)
    {
      printf("%d - %s\n", i, lines[i]);
      i++;
    }
}

void free_lines(char **lines)
{
    int i = 0;
    while(lines[i] != NULL)
    {
        free(lines[i++]);
    }
    free(lines);
}

int main(void)
{
  FILE *f;
  f = fopen("movies.csv","r");
  if(f == NULL)
    {
      printf("Nu am putut citi din fisier!\n");
      return 0;
    }

  char **lines = getLines(f);
  int i = 0;

  printLines(lines);

  while(lines[i] != NULL)
    {
      movies = (MOVIE*)realloc(movies, (nMovies+1)*sizeof(MOVIE));
      char *p = NULL;
      char *title = NULL;
      int year = 0;
      int budget = 0;
      
      p = strtok(lines[i],",");
      year = strtol(p,NULL,10);
      //movies[nMovies].year = strtol(p,NULL,10);

      p = strtok(NULL,",");

      p = strtok(NULL,",");
      title = (char*)realloc(title,strlen(p)*sizeof(char));
      strcpy(title,p);
      // strcpy(movies[nMovies].title,p);

      p = strtok(NULL,",");

      p = strtok(NULL,",");

      p = strtok(NULL,",");
      budget = strtol(p,NULL,10);
      //movies[nMovies].budget = strtol(p,NULL,10);

      printf("%d - year = %d;   title = %s;               budget = %d\n", i, year, title, budget);
      
      nMovies++;
      i++;
    }

  
  free_lines(lines);
  fclose(f);
  eliberare();
  free(movies);
  return 0;
}



/*MOVIE **adaugare(char **lines)
{
  static MOVIE *m = NULL;
  char *line = NULL, *p = NULL;
  int i = 0;
  
  m = (MOVIE *)realloc(movies, (nMovies+1)*sizeof(MOVIE));
  if(m == NULL)
    {
      printf("Memorie insuficienta!\n");
      eliberare();
      exit(EXIT_FAILURE);
    }

  movies = m;
  getchar();

  while(lines[i] != NULL)
    {
      line = lines[i];
      p = strtok(line,",");
      if(p == NULL)
	{
	  return NULL;
	}
      movies[nMovies].year = strtol(p,NULL,10);

      p = strtok(NULL,",");
      if(p == NULL)
	{
	  return NULL;
	}

      p = strtok(NULL,",");
      if(p == NULL)
	{
	  return NULL;
	}
      strcpy(movies[nMovies].title, p);

      p = strtok(line,",");
      if(p == NULL)
	{
	  return NULL;
	}
      p = strtok(line,",");
      if(p == NULL)
	{
	  return NULL;
	}
      p = strtok(line,",");
      if(p == NULL)
	{
	  return NULL;
	}

      p = strtok(line,",");
      if(p == NULL)
	{
	  return NULL;
	}
      movies[nMovies].budget = strtol(p,NULL,10);
      i++;
    }
  nMovies++;
  return &movies;
}
*/

///////////////////////////////////////////////////////////////////////////

/*
char *citireSir()
{
  char ch;
  char *buff1 = NULL, *buff2 = NULL;
  size_t n = 0;

  for(;;)
    {
      n++;
      buff2 = (char *)realloc(buff1, n*sizeof(char));
      if(buff2 == NULL)
	{
	  printf("Memorie insuficienta!\n");
	  eliberare();
	  free(buff1);
	  exit(EXIT_FAILURE);
	}

      buff1 = buff2;
      ch = getchar();
      
      if(ch == '\n')
	{
	  buff1[n-1] = '\0';
	  return buff1;
	}
      buff1[n-1] = ch;
    }
}
 */
