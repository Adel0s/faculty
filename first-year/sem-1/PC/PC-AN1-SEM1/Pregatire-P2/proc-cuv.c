#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <char.h>
#define CHUNK 8 

double procent(long long nr, long long total)
{
  double proc = nr * 100 / (double)total;
  return proc;
}

void free_all(long long *aparitii, char **cuvinte, long long total)
{
  long long i;
  for(i=0; i<total; i++)
    {
      free(cuvinte[i]);
    }
  free(cuvinte);
  free(aparitii);
}

void afisare_procente(FILE *in, FILE *out)
{
  char **cuvinte = NULL;
  char cuv[20] = "";
  long long i = 0, size = 0, nrcuv = 0, total = 0, *aparitii = NULL;

  while(fscanf(in, "%s", cuv) != EOF)
    {
      total++;
      for(i = 0; i<nrcuv; i++)
	{
	  if(strcmp(cuvinte[i], cuv) == 0)
	    {
	      aparitii[i]++;
	      break;
	    }
	}
      
      if(i == nrcuv)
	{
	  if(nrcuv == size)
	    {
	      size += CHUNK;

	      cuvinte = (char **)realloc(cuvinte,size * sizeof(char *));
	      if(cuvinte == NULL)
		{
		  printf("Memorie insuficienta!");
		  exit(-1);
		}

	      aparitii = (long long *)realloc(aparitii, size * sizeof(long long));
	      if(aparitii == NULL)
		{
		  printf("Memorie insuficienta!");
		  exit(-1);
		}
	    }
	  
	  cuvinte[nrcuv] = (char *)malloc((strlen(cuv) + 1) * sizeof(char));
	  if(cuvinte[nrcuv] == NULL)
	    {
	      printf("Memorie insuficienta!");
	      exit(-1);
	    }
	  
	  aparitii[nrcuv] = 1;
	  strcpy(cuvinte[nrcuv], cuv);
	  nrcuv++;
	}
    }

  for(i=0; i<nrcuv; i++)
    {
      fprintf(out, "%s : %1f%%\n", cuvinte[i], procent(aparitii[i], total));
    }
  free_all(aparitii, cuvinte, nrcuv);
}

int main(int argc, char **argv)
{
  if(argc < 3)
    {
      printf("Prea putine argumente\n");
      exit(-1);
    }

  FILE *in = NULL, *out = NULL;

  in = fopen(argv[1], "r");
  if(in == NULL)
    {
      printf("Fisierul nu a putut fi deschis\n");
      exit(-1);
    }

  out = fopen(argv[2], "w");
  if(out == NULL)
    {
      printf("Fisierul nu a putut fi deschis\n");
      exit(-1);
    }

  afisare_procente(in, out);
  return 0;
}
