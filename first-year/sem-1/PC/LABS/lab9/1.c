/*
Să se citească o linie de la tastatură. Linia conține cuvinte care sunt formate doar din litere, cuvintele fiind despărțite prin orice alte caractere ce nu sunt litere. Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze șirul rezultat 
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char s[100];
  int i;
  printf("Introduceti textul: ");
  fgets(s,100,stdin);
  s[0] = toupper(s[0]);

  for(i=1; i<s[i]; i++)
    {
      if( !(isalpha(s[i-1])) && isalpha(s[i])) s[i] = toupper(s[i]);
    }

  printf("text final: %s", s);
  return 0;
}
