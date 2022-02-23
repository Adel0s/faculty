#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 8
#define VECTOR_CHUNK 4

typedef struct
{
  char *titlu;
  int an, buget;
}FILM;

char *getLine(FILE *f)
{
  int size = 0, i = 0;
  char ch = 0, *linie = NULL;
  while((ch = fgetc(f)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  linie = realloc(linie, size * sizeof(char));
	}
      if(ch == '\n')
	{
	  linie[i] = '\0';
	  break;
	}
      linie[i++] = ch;
    }
    return linie;
}

FILM transformFilm(char *linie)
{
  FILM film;
  char *p = strtok(linie, ",");
  film.an = atoi(p);
  p = strtok(NULL, ",");
  p = strtok(NULL, ",");

  film.titlu = malloc((strlen(p) + 1) * sizeof(char));
  strcpy(film.titlu, p);

  for(int i = 0; i < 4; i++)
    {
      p = strtok(NULL, ",");
    }
  film.buget = atoi(p);
  return film;
}

FILM *getFilme(FILE *f, int *marime)
{
  int size = 0, i = 0;
  char *linie = NULL;
  FILM *filme = NULL, film;

  while((linie = getLine(f)) != NULL)
    {
      film = transformFilm(linie);
      if(i == size)
	{
	  size += VECTOR_CHUNK;
	  filme = realloc(filme, size * sizeof(FILM));
	}
      
      filme[i++] = film;
      free(linie);
      linie = NULL;    
    }
  *marime = i;
  return filme;  
}

void curatatFilme(FILM *v, int marime)
{
  for(int i = 0; i < marime; i++)
    {
      free(v[i].titlu);
    }
  free(v);
}

void printareFilme(FILM *v, int marime)
{
  for(int i = 0; i < marime; i++)
    {
      printf("%s\n", v[i].titlu);
    }
}
int main()
{
  FILM *v = NULL;
  FILE *f = NULL;
  int marime;
  if((f = fopen("movies.csv", "r")) == NULL)
    {
      printf("Eroare\n");
      exit(-1);
    }
  
  //char *linie = getLine(f);
  //free(linie);
  //linie = NULL;

  v = getFilme(f, &marime);
  printareFilme(v, marime);
  curatatFilme(v, marime);
 
  if(fclose(f) != 0)
    {
      printf("Eroare\n");
      exit(-1);
    }
  return 0;
}
