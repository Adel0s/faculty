#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *texttooct(const char *text)
{
  int i, ascii;
  char *oct = NULL, octal[20];
	
  if((oct = (char*)malloc(sizeof(char) * strlen(text) * 3 + 1)) == NULL)
    {
      printf("Eroare");
      exit(-1);
    }
  oct[0] = '\0';
  for(i = 0; i < strlen(text); i++)
    {
      ascii = text[i];
      sprintf(octal, "%03o", ascii);
      strcat(oct, octal);
    }
  return oct;
}

int main()
{	
  char *oct = NULL;
  oct = texttooct("absdxfcvghbjnnhfvgfdsc gfghj(");
  printf("%s\n", oct);
  free(oct);
  return 0;
}
