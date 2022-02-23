char *getline_stdin(void)
{
  char *line = NULL;
  int ch;
  int i = 0;
  int size = 1;

  ch = getchar();
  while(ch != EOF)
    {
      line = realloc(line,size*sizeof(char));
      if(ch != '\n')
	{
	  line[i] = ch;
	  i++;
	}
      else
	{
	  break;
	}
      
      if(line != NULL)
	{
	  if(i == size)
	    {
	      size++;
	      line = realloc(line,size*sizeof(char));
	    }
	  line[i] = 0;
	}
      ch = getchar();
    }
  return line;
}

void print_lines(char **lines)
{
  char **p;
  int i = 0;
  p = lines;

  while(*p != NULL)
    {
      printf("%d - %s\n", i, *p);
      p++;
      i++;
    }
}

void free_lines(char **lines)
{
  char **p;
  p = lines;
  while(*p != NULL)
    {
      free(*p);
      p++;
    }
}

char **get_lines(void)
{
  char **lines = NULL;
  char *current_line = NULL;
  int i = 0;
  int size = 0;

  while((current_line = getline_stdin()) != NULL)
    {
      if(i == size)
	{
	  size++;
	  lines = realloc(lines, size*sizeof(char*));
	}
      lines[i] = current_line;
      i++;

      if(i == size)
	{
	  size++;
	  lines = realloc(lines,size*sizeof(char*));
	}
      lines[i] = NULL;
    }
  return lines;
}

int main(void)
{
  char **lines = NULL;
  lines = get_lines();
  print_lines(lines);
  free_lines(lines);
  free(lines);
  return 0;
}

