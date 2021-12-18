/*
Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char text[100];
  char i;
  int j fr[100];
  fgets(text,100,stdin);
  for(i='a'; i <= 'z';i++)
    {
      for(j=0;j<text;j++)
	{
	  if(text[j] == i) fr[i]++;
	}
    }
}
