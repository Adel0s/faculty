#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

char *getLine(FILE *f)
{
  char ch = 0, *line = NULL;
  int i = 0, size = 0;

  while((ch = fgetc(f)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  line = realloc(line, size * sizeof(char));
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
  int i = 0, size = 0;

  while((line = getLine(f)) != NULL)
    {
      if(i == size)
	{
	  size += ARRAY_CHUNK;
	  lines = realloc(lines, size * sizeof(char*));
	}
      
      lines[i++] = line;
      
      if(i == size)
	{
	  size++;
	  lines = realloc(lines, size * sizeof(char*));
	}
      lines[i] = NULL;
    }
  return lines;
}

void print_lines(char **lines)
{
  int i = 0;
  while(lines[i] != NULL)
    {
      printf("%d) %s\n", i, lines[i]);
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
  f = fopen("scrisoare.txt", "r");
  
  if(f == NULL)
    {
      printf("Fisierul nu a fost deschis!\n");
      exit(-1);
    }
  

  char **lines = getLines(f);
  print_lines(lines);
  free_lines(lines);
  fclose(f);
  return 0;
}
