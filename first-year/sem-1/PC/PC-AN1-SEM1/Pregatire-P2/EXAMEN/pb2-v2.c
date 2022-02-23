#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNK 8

double procent(long long aparitii, long long total)
{
  double proc;
  proc  = aparitii*100 / (double)total;
  return proc;
}
void free_all(long long *aparitii, char **cuvinte, long long nCuv)
{
  for(int i=0;i<nCuv;i++)
    {
      free(cuvinte[i]);
    }
  free(cuvinte);
  free(aparitii);
}

char *getLine(FILE *in)
{
  char *line = NULL;
  char ch = 0;
  int size = 0, i = 0;

  while((ch = fgetc(in)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  line = (char  *)realloc(line, size * sizeof(ch));
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

void afisare_procente(FILE *in, FILE *out)
{
  long long *aparitii = NULL, size = 0, nCuv = 0, i = 0, total = 0;
  char *p, *line = NULL, **cuvinte = NULL;

  while((line = getLine(in)) != NULL)
    {
      if(strlen(line)<=1) continue;
      p = strtok(line, " .,:;!?'""");
      while(p)
	{
	  total++;
	  for(i=0;i<nCuv;i++)
	    {
	      if(strcmp(cuvinte[i], p) == 0)
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
		      printf("Memorie insuficienta!\n");
		      exit(-1);
		    }

		  aparitii = (long long*)realloc(aparitii, size * sizeof(long long));
		  if(aparitii == NULL)
		    {
		      printf("Memorie insuficienta!\n");
		      exit(-1);
		    }
		}
	      
	      cuvinte[nCuv] = (char*)malloc((strlen(p)+1) * sizeof(char));
	      if(cuvinte[nCuv] == NULL)
		{
		  printf("Memorie insuficienta!\n");
		  exit(-1);
		}

	      aparitii[nCuv] = 1;
	      strcpy(cuvinte[nCuv], p);
	      nCuv++;
	    }
	  p = strtok(NULL," .,;:!?'""");
	}
    }

  for(i=0;i<nCuv;i++)
    {
      fprintf(out,"%lld) %s ---> %f%%\n", i, cuvinte[i], procent(aparitii[i], total));
    }
  free_all(aparitii,cuvinte,nCuv);
}

int main(int argc, char **argv)
{
  FILE *in = NULL;
  in = fopen("scrisoare2.txt", "r");

  FILE *out = NULL;
  out = fopen("scrisoare-out.txt", "w");
  afisare_procente(in, out);
  return 0;
}
