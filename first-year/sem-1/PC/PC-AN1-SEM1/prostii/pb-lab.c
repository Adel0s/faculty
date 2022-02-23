#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *nume;
  char *functie;
  int salariu;
}Angajat;

Angajat *angajati = NULL;
int nAngajati = 0;

void eliberareAngajat(int idx)
{
  free(angajati[idx].nume);
  free(angajati[idx].functie);
}

void eliberare()
{
  for(int i=0;i<nAngajati;i++)
    {
      eliberareAngajat(i);
    }
  free(angajati);
}

char *getLine(FILE *f)
{
  char ch = 0;
  char *line = NULL;
  int size = 0, i = 0;

  ch = fgetc(f);
  while(ch != EOF)
    {
      if(i==size)
	{
	  size++;
	  line = realloc(line,size*sizeof(char));
	}
      if(ch == '\n')
	{
	  line[i] = '\0';
	  break;
	}
      line[i] = ch;
      i++;
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
	  lines = realloc(lines,size*sizeof(char*));
	}
      lines[i] = line;
      i++;
      if(i==size)
	{
	  size++;
	  lines = realloc(lines,size*sizeof(char*));
	}
      lines[i] = NULL;
      line = getLine(f);
    }
  return lines;
}

void print_lines(char **lines)
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
  int i = 0;
  f = fopen("movies.csv","r");
  if(f == NULL)
    {
      printf("NU am putut citi fisierul!\n");
      return 0;
    }

  char **lines = getLines(f);

  while(lines[i] != NULL)
    {
      angajati = (Angajat*)realloc(angajati, (nAngajati+1)*sizeof(Angajat));
      char *p = NULL;
      int salariu = 0;
      p = strtok(lines[i],",");
      if(p == NULL)
	{
	  continue;
	}
      salariu = strtol(p,NULL,10);
      angajati[nAngajati].salariu = salariu;

      p = strtok(lines[i],",");
      if(p == NULL)
	{
	  continue;
	}
      
      nAngajati++;
      i++;
    }
  
  free_lines(lines);
  
  fclose(f);
  return 0;
}
