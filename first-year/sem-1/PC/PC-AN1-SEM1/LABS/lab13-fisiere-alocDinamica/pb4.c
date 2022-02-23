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
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

char **lines = NULL;
int nLinii = 0;
FILE *f;

void eliberare()
{
  int i;
  for(i=0;i<nLinii;i++)
    {
      free(lines[i]);
    }
  free(lines);
}

char* read_line(FILE *f)
{
  char *line = NULL;
  char ch = 0;
  int size = 0, i = 0;
  
  ch = fgetc(f);
  while(ch != EOF)
    {
      size++;
      line = (char *)realloc(line, size*sizeof(char));

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

char **populate_lines(FILE *f)
{
  char *line = NULL;
  
  line = read_line(f);
  while(line != NULL)
    {
      nLinii++;
      lines = (char**)realloc(lines,nLinii*sizeof(char*));
      if(lines == NULL)
	{
	  printf("Memorie insuficienta!\n");
	  exit(EXIT_FAILURE);
	  eliberare();
	}
      lines[nLinii-1] = line;
      line = read_line(f);
    }
  return lines;
}

void print_lines(char **lines)
{
  for(int i=0;i<nLinii;i++)
    {
      printf("%d -> %s\n",i,lines[i]);
    }
}

void print_lines_filepath(char **lines, FILE *f)
{
  for(int i=0;i<nLinii;i++)
    {
      fprintf(f, "%d -> %s\n",i,lines[i]);
    }
}


void sortLines(char **lines)
{
  char *aux;
  for(int i = 0;i<nLinii;i++)
    {
      for(int j=i+1;j<nLinii;j++)
	{
	  if(strcmp(lines[i],lines[j]) >= 1)
	    {
	      aux = lines[i];
	      lines[i] = lines[j];
	      lines[j] = aux;
	    }
	}
    }
}

void write_sort(char **lines, char *filepath)
{
  FILE *f = NULL;
  f = fopen(filepath, "w");
  if(f == NULL)
  {
    printf("NU am putu scrie fisierul!\n");
    exit(EXIT_FAILURE);
  }
  sortLines(lines);
  print_lines_filepath(lines,f);
  fclose(f);
}

void write_random(char **lines, char *filepath)
{
  FILE *f = NULL;
  f = fopen(filepath, "w");
  if(f == NULL)
  {
    printf("NU am putu scrie fisierul!\n");
    exit(EXIT_FAILURE);
  }
  srand(time(NULL));
  int randomLine = 0;
  for(int i=0;i<nLinii;i++)
    {
      randomLine = rand() % (nLinii+1);
      fprintf(f, "%d -> %s\n",randomLine,lines[randomLine]);
    }
  fclose(f);
}

uint32_t find_word(char **lines, char *word)
{
  int aparitii = 0;
  char *p = NULL;
  for(int i=0;i<nLinii;i++)
    {
      p = strstr(lines[i],word);
      while(p)
	{
	  aparitii++;
	  p = strstr(lines[i],word);
	  p = p+strlen(word);
	  p = strstr(p,word);
	}
    }
  return aparitii;
}

int main(void)
{
  int aparitii = 0;
  f = fopen("scrisoare.txt","r");
  if(f == NULL)
    {
      printf("NU am putu citi fisierul!\n");
      exit(EXIT_FAILURE);
    }
  //line = read_line(f);
  lines = populate_lines(f);
  print_lines(lines);
  write_sort(lines,"scrisoare1.txt");
  write_random(lines,"scrisoare2.txt");
  aparitii =find_word(lines,"n");
  printf("nu apare de %d ori\n",aparitii);
  eliberare();

  fclose(f);
  return 0;
}
