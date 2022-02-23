#include <stdio.h>
#include <string.>
#include <stdlib.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

char *getLine(FILE *f)
{
  char ch = 0;
  char *line = NULL;
  int size = 0, i = 0;

  while((ch = fgetc(f)) != EOF)
    {
      if(i==size)
	{
	  size += CHUNK;
	  line = (char*)realloc(line,size*sizeof(char));
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
  int size = 0, i = 0;

  while((line = getLine(f)) != NULL)
    {
      if(i == size)
	{
	  size += ARRAY_CHUNK;
	  lines = (char**)realloc(lines,size*sizeof(char*));
	}
      lines[i++] = line;

      if(i == size)
	{
	  size ++;
	  lines = (char**)realloc(lines,size*sizeof(char*));
	}
      lines[i] = NULL;
    }
  return lines;
}
  

int main(void)
{
  return 0;
}
