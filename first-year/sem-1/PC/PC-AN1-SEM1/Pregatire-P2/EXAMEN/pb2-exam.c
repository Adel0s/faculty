#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CHUNK 8

void free_all(long long *aparitii, char **cuvinte, long long nCuv)
{
  for(long long i=0; i<nCuv; i++)
    {
      free(cuvinte[i]);
    }
  free(aparitii);
  free(cuvinte);
}

double procent(long long aparitii, long long total)
{
  double proc = aparitii * 100 / (double)total;
  return proc;
}
void afisare_procente(FILE *in, FILE *out)
{
  char **cuvinte = NULL;
  char cuv[50] = "";
  long long i = 0, size = 0, nCuv = 0, total = 0, *aparitii = NULL;

  while(fscanf(in, "%s", cuv) != EOF)
    {
      if(!isalpha(cuv[strlen(cuv)-1])) cuv[strlen(cuv)-1] = 0;
      total++;
      for(i = 0; i<nCuv; i++)
	{
	  if(strcmp(cuvinte[i], cuv) == 0)
	    {
	      aparitii[i]++;
	      break;
	    }
	}
      
      if(i == nCuv)
	{
	  if(nCuv == size)
	    {
	      size += CHUNK;
	      
	      cuvinte = (char**)realloc(cuvinte, size * sizeof(char*));
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
	  cuvinte[nCuv] = (char *)malloc((strlen(cuv) + 1) * sizeof(char));
	  if(cuvinte[nCuv] == NULL)
	    {
	       printf("Memorie insuficienta!");
	       exit(-1);
	    }
	  
	  aparitii[nCuv] = 1;
	  strcpy(cuvinte[nCuv], cuv);
	  nCuv++;
	}
    }

  for(i = 0; i<nCuv; i++)
    {
      fprintf(out,"%lld) %s: %f%%\n", i, cuvinte[i], procent(aparitii[i], total));
    }
  free_all(aparitii, cuvinte, nCuv);
}

int main(int argc, char **argv)
{
  if(argc < 3)
    {
      printf("Prea putine argumente!\n");
      exit(-1);
    }

  FILE *in = NULL, *out = NULL;
  in = fopen(argv[1], "r");
  if(in == NULL)
    {
      printf("NU am putu deschide fisierul!\n");
      exit(-1);
    }

  out = fopen(argv[2], "w");
  if(out == NULL)
    {
      printf("NU am putut deschide fisierul!\n");
      exit(-1);
    }

   afisare_procente(in, out);

  fclose(in);
  fclose(out);
  return 0;
}
