/*
Se consideră un fișier text ce conține un număr necunoscut de linii de text de o dimensiune necunoscută. Să se scrie un program ce citește un astfel de fișier și stochează datele într-un tablou alocat dinamic de string-uri C alocate dinamic. Se va folosi o amprentă minimă de memorie. Se vor scrie de asemenea și următoarele funcții

    o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)
    o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a liniilor. Hint ! Se poate folosi funcția rand(....);
    o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.

Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

char **lines = NULL;
int nLines = 0;

char *getLine(FILE *f)
{
  int i = 0, size = 0;
  char ch = 0;
  char *line = NULL;

  while((ch = fgetc(f)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  line = (char*)realloc(line, size * sizeof(char));
	  if(line == NULL)
	    {
	      printf("Memorie insuficienta!\n");
	      exit(-1);
	    }
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

char **getLines(FILE *f)
{
  char *line = NULL, **lines = NULL;
  int size = 0;

  while((line = getLine(f)) != NULL)
    {
      if(size == nLines)
	{
	  size += ARRAY_CHUNK;
	  lines = (char**)realloc(lines,size * sizeof(char*));
	  if(lines == NULL)
	    {
	      printf("Memorie insuficienta!\n");
	      exit(-1);
	    }
	}
      
      if(strlen(line) <= 1) continue; //nu adauga liniile goale
      lines[nLines] = line;
      nLines++;

       if(size == nLines)
	{
	  size++;
	  lines = (char**)realloc(lines,size * sizeof(char*));
	  if(lines == NULL)
	    {
	      printf("Memorie insuficienta!\n");
	      exit(-1);
	    }
	}
       lines[nLines] = NULL;
    }
  return lines;
}

void freeLines(char **lines)
{
  for(int i=0;i<nLines;i++)
    {
      free(lines[i]);
    }
  free(lines);
}

void printLines(char **lines)
{
    for(int i=0;i<nLines;i++)
    {
      printf("%d) %s\n", i, lines[i]);
    }
}

void sortLines(char **lines)
{
  char *line = NULL;
  int i=0, j=0;
  for(i=0;i<nLines;i++)
    {
      for(j=i+1;j<nLines;j++)
	{
	  if(strcmp(lines[i],lines[j]) > 0)
	    {
	      line = lines[i];
	      lines[i] = lines[j];
	      lines[j] = line;
	    }
	}
    }
}

void write_sort(char **lines, char *filepath)
{
  FILE *f = NULL;
  f = fopen(filepath,"w");
  if(f == NULL)
    {
      printf("NU am putut deschide fisierul!\n");
      exit(-1);
    }
  
  sortLines(lines);
  
  for(int i=0;i<nLines;i++)
    {
      fprintf(f,"%d) %s\n", i, lines[i]);
    }
  fclose(f);
}

void write_random(char **lines, char *filepath)
{
  srand(time(NULL));
  
  FILE *f = NULL;
  f = fopen(filepath,"w");
  if(f == NULL)
    {
      printf("NU am putu deschide fisierul!\n");
      exit(-1);
    }

  int randomLine = 0;

  for(int i=0;i<nLines;i++)
    {
      randomLine = rand() % (nLines+1);
      fprintf(f,"%d) %s\n",randomLine, lines[randomLine]);
    }
  
  fclose(f);
}

uint32_t find_word(char **lines, char *word)
{
  uint32_t nWords = 0;
  char *p = NULL;
  int  i = 0;
  
  for(i=0; i<nLines; i++)
    {
      p = strstr(lines[i], word);
      while(p)
	{
	  nWords++;
	  //p = strstr(lines[i],word);
	  p = p + strlen(word);
	  p = strstr(p, word);
	}
    }

  return nWords;
}

int main(void)
{
  uint32_t aparitii = 0;
  FILE *f = NULL;
  f = fopen("scrisoare.txt", "r");
  if(f == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }

  lines = getLines(f);
  printLines(lines);
  write_sort(lines, "scrisoare1.txt");
  write_random(lines, "scrisoare2.txt");
  aparitii = find_word(lines, "neamul");
  printf("%d\n",aparitii);
  freeLines(lines);
  
  fclose(f);
  return 0;
}
