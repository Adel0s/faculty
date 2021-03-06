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

MOVIE **movies = NULL;
int nMovies = 0;

void eliberareMovie(int idx)
{
  free(movies[idx] -> title);
}

void eliberare()
{
  for(int i=0; i<nMovies; i++)
    {
      eliberareMovie(i);
      free(movies);
    }
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

MOVIE **adaugare(char **lines)
{
  static MOVIE **m = NULL;
  char *line = NULL, *p = NULL;
  int i = 0;
  
  m = (MOVIE **)realloc(movies, (nMovies+1)*sizeof(MOVIE*));
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
      movies[nMovies] -> year = strtol(p,NULL,10);

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
      strcpy(movies[nMovies] -> title, p);

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
      movies[nMovies] -> budget = strtol(p,NULL,10);
      i++;
    }
  nMovies++;
  return movies;
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

  char **lines;
  lines = getLines(f);

  // printLines(lines);
  movies = adaugare(lines);
  printf("Adaugare cu succes!\n");
  fclose(f);
  eliberare();
  free(movies);
  return 0;
}
