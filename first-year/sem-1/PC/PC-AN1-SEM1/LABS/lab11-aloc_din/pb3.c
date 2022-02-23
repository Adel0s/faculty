/*
Jocul fazan: se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, TAB sau ENTER), până la întâlnirea cuvântului vid. Pornind de la cuvintele citite, se construieşte un şir de caractere după următoarele reguli:
    - Primul cuvânt citit se adaugă la şirul de caractere
    - Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului coincid cu primele două litere ale cuvântului (nu se face distincţie între literele mici şi cele mari);
Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’. Să se afişeze şirul astfel construit. Programul va folosi alocare dinamică astfel încât spaţiul de memorie utilizat să fie minim.
Spre exemplu, pentru intrarea:

Fazan Antic Noe icoana Egipt naftalina nimic Narcisa trei altceva santier iarba Caine Pisica erudit

se afişează:
Fazan-Antic-icoana-naftalina-Narcisa-santier-erudit 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *get_word()
{
  char *cuv = NULL, ch = 0;
  int size = 0, i = 0;

  while((ch = getchar()) != EOF)
    {
      if(i==size)
	{
	  size++;
	  cuv = realloc(cuv,sizeof(char)*size);
	}

      if(ch == ' ' || ch == '\t' || ch == '\n')
	{
	  cuv[i] = '\0';
	  return cuv;
	}
      cuv[i] = ch;
      i++;
    }
  return cuv;
}


int main(void)
{
  char *cuvant = NULL, uc = 0, puc = 0, *text = NULL;
  int size = 1;
  
  cuvant = get_word();
  uc = tolower(cuvant[strlen(cuvant) - 1]);
  puc = tolower(cuvant[strlen(cuvant) - 2]);

  size = size + strlen(cuvant);
  text = (char*)malloc(sizeof(char)*size);

  strcpy(text, cuvant);
  free(cuvant);

  while((cuvant=get_word()) != NULL)
    {
      if(tolower(cuvant[0]) == puc  && tolower(cuvant[1]) == uc)
	{
	  size = size + strlen(cuvant) + 1;
	  text = realloc(text, sizeof(char) * size);

	  strcat(text,"-");
	  strcat(text,cuvant);

	  uc = tolower(cuvant[strlen(cuvant)-1]);
	  puc = tolower(cuvant[strlen(cuvant)-2]);
	}
      free(cuvant);
    }

  printf("%s\n",text);
  free(text);
  
  return 0;
}
