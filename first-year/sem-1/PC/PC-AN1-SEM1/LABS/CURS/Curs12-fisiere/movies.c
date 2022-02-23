#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LINE_SIZE 5000
#define TITLE_SIZE 1000
#define ARRAY_SIZE 2000

typedef struct
{
  uint16_t year;
  char title[TITLE_SIZE];
}MOVIE;

MOVIE *processLine(char *line)
{
  static MOVIE m;
  char *p;
  if((p = strtok(line,",")) == NULL)
    {
      return NULL;
    }

  m.year = strtol(p,NULL,10); ///conversie din char*(sir de caractere) in intreg(int) baza 10

  if((p = strtok(NULL, ",")) == NULL)
    {
      return NULL;
    }
  
  if((p = strtok(NULL, ",")) == NULL)
    {
      return NULL;
    }
  strcpy(m.title, p);
  return &m;
} 

void printMovie(MOVIE *m)
{
  printf("%s (%d) \n", m->title, m->year);
}

void printMovieArray(MOVIE *array, int size)
{
  for(int i=0; i<size; i++)
    {
      printf("%d ", i);
      printMovie(&array[i]);
    }
} 

void selectMovies(MOVIE *array, int size, uint16_t year, char *outputFilePath)
{
  FILE *out = NULL;
  if((out = fopen(outputFilePath, "w")) == NULL)
    {
      perror(NULL);
      exit(-1);
    }

  for(int i=0; i<size; i++)
    {
      if(array[i].year == year)
	{
	  fprintf(out, "%s (%d) \n", array[i].title, array[i].year);
	}
    }
  
  if(fclose(out) !=0)
    {
      perror(NULL);
      exit(-1);
    }
}

int main(void)
{
  FILE *f = NULL;
  static char line[LINE_SIZE];
  static MOVIE movies[ARRAY_SIZE];
  MOVIE *aux;
  int count = 0;
  
  if((f = fopen("movies.csv", "r")) == NULL)
    {
      perror(NULL);
      exit(-1);
    }

  while(fgets(line, LINE_SIZE, f) != NULL)
    {
      //count++;
      //printf("%d - %s\n", count, line);
      if((aux = processLine(line)) != NULL)
	{
	  printMovie(aux);
	  movies[count++] = *aux; /// salvam intr-un vector informatiile
	}
    }

  printMovieArray(movies, count);
  
  if(fclose(f) !=0 )
    {
      perror(NULL);
      exit(-1);
    }

  selectMovies(movies, count, 1984, "out.txt");
  return 0;
}
