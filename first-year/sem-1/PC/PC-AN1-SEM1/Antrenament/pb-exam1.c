#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/*char *convert_to_octal(char *line)
{
  //char *converted_string;
  int ch = 0;
  int i = 0;
  line = realloc(line,strlen(line)*sizeof(char));
  while(line[i] != '\0')
    {
      ch = line[i];
      ch = strtol(ch,NULL,8);
      line[i] = ch;
      i++;
    }
}
*/

char *string2octal(char* input)
{
  char *output = NULL;
    int loop;
    int i; 
    output = realloc(output,3*strlen(input)*sizeof(char));
    i=0;
    loop=0;
    
    while(input[loop] != '\0')
    {
      sprintf((char*)(output+i),"%02o", input[loop]);
        loop+=1;
        i+=2;
    }
    output[i++] = '\0';
    return output;
}

int main(void)
{
  char *output;
  output = string2octal("ABCD");
  printf("%s\n",output);
  return 0;
}
