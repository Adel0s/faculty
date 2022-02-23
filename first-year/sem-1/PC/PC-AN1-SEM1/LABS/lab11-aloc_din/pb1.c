/*
Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, folosind un bloc de memorie alocat dinamic pentru rezultat. Funcția va returna acest bloc de memorie. Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char s1[101], char s2[101])
{
  char *result, *p;
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);

  p = malloc(sizeof(char)*(len1+len2+1));
  if(p == NULL)
    {
      printf("Alocare esuata!");
      exit(-1);
    }
  result = p;

  result = strcat(s1, " ");
  result = strcat(s1, s2);

  return result;
}

int main(void)
{
  char s1[101] = "Andrei";
  char s2[101] = "si Ana";
  char *result = concat(s1,s2);
  printf("%s\n",result);
  return 0;
}
