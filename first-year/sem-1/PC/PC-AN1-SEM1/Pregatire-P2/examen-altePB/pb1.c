#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nume[51];
  int id;
}PERSOANA;

PERSOANA *persoane = NULL;
int nPersoane = 0;

PERSOANA *getPers(FILE *in)
{
  PERSOANA *pers = NULL;
  char nume[51];
  int id;
  while(fscanf(in,"%s%d", nume, &id) != EOF)
    {
      nPersoane++;
      pers = (PERSOANA*)realloc(pers, nPersoane*sizeof(PERSOANA));
      if(pers == NULL)
	{
	  printf("Memorie insuficenta!\n");
	  exit(-1);
	}

      strcpy(pers[nPersoane-1].nume, nume);
      pers[nPersoane-1].id = id;
    }
  return pers;
}

void printPers(PERSOANA *pers, FILE *out)
{
  for(int i=0;i<nPersoane;i++)
    {
      fprintf(out,"%s %d\n", pers[i].nume, pers[i].id);
    }
}

void sortNume(PERSOANA *pers, FILE *out)
{
  PERSOANA aux;
  int i, j;
  for(i=0;i<nPersoane;i++)
    {
      for(j=i+1;j<nPersoane;j++)
	{
	  if(strcmp(pers[i].nume, pers[j].nume) > 0)
	    {
	      aux = pers[i];
	      pers[i] = pers[j];
	      pers[j] = aux;
	    }
	}
    }
  
  for(int i=0;i<nPersoane;i++)
    {
      fprintf(out,"%s %d\n", pers[i].nume, pers[i].id);
    }
}

void sortID(PERSOANA *pers, FILE *out)
{
  PERSOANA aux;
  int i, j;
  for(i=0;i<nPersoane;i++)
    {
      for(j=i+1;j<nPersoane;j++)
	{
	  if(pers[i].id > pers[j].id)
	    {
	      aux = pers[i];
	      pers[i] = pers[j];
	      pers[j] = aux;
	    }
	}
    }
  
  for(int i=0;i<nPersoane;i++)
    {
      fprintf(out,"%d %s\n", pers[i].id, pers[i].nume);
    }
}

int main(int argc, char **argv)
{
  FILE *in, *out;
  if(argc < 4)
    {
      printf("Prea putine argumente!\n");
      exit(-1);
    }

  in = fopen(argv[1], "r");
  if(in == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }
  
  out = fopen(argv[2], "w");
  if(out == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }

  
  persoane = getPers(in);

  int opt = strtol(argv[3],NULL,10);

  if(opt >= 0)
    {
      sortNume(persoane, out);
    }
  else sortID(persoane,out);

  free(persoane);
  
  fclose(in);
  fclose(out);

}
