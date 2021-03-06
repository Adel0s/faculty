#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *getLine_stdin()
{
  char ch, *line = NULL;
  int size = 0, i = 0;

  while((ch = getchar()) != EOF)
    {
      size++;
      line = (char*)realloc(line, size*sizeof(char));

      if(ch == '\n')
	{
	  line[i] = '\0';
	  break;
	}
      line[i++] = ch;
    }
  return line;
}

int main(void)
{
  char str[] = "Ioane!!! Mihai,Ana si    Maria te cheama.";
  char *line = NULL;
  line = getLine_stdin();

  for(int i=0; i<strlen(line)-1;i++)
    {
      if(!isalpha(line[i]))
	{
	  while(!isalpha(line[i+1]))
	    {
	      strcpy(line+i-1, line+i);
	      printf("INLOCUIRI: %s\n", line);
	    }
	}
      printf("%s\n", line);
    }

  printf("%s\n",line);
  free(line);
  return 0;
}
