/*
Sa se scrie o functie cu urmatorul antent

uint32_t string_replace(char *where, const char *what, const char *replace)

Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Se considera ca zona de memorie a lui where este suficient de mare ca sa poata contine noul string. Functia returneaza numarul de inlocuiri

char s1[] = "Acesta este un string si un string este terminat cu 0x00";
char s2[] = "string";
char s3[] = "sir de caractere";

int r = string_replace(s1, s2, s3);

s1 devine "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s2, s3 - raman neschimbate
r = 2
Se va considera ca zona de memorie a lui where este exact cat string-ul iar dupa apelul functiei aceasta zona de memorie va fi ajustata astfel incat sa incapa exact string-ul rezultat. Se presupune deci ca zona de memorie a lui where este alocata dinamica inainte de apelul functiei iar implementarea presupune realocarea zonei astfel incat sa fie exact cat string-ul rezultat.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t string_replace(char *where, const char *what, const char *replace)
{
  char *p = NULL;
  char *new_string;
  int len_what = strlen(what);
  int len_replace = strlen(replace);
  int size = 0;

  if(len_what >= len_replace) size = len_replace;
  else size = len_replace - len_what;
  int nrAparitii = 0;

  //while(where)
    {
      if((new_string = strstr(where,what)) != NULL)
	{
	  nrAparitii++;
	  p = realloc(p,sizeof(char)*(size)+1);

	  if(p == NULL)
	    {
	      printf("Memorie insuficienta!\n");
	      exit(-1);
	    }
	  for(int i=0;i<len_replace;i++)
	    {
	      new_string[i] = replace[i];
	    }
	  printf("%s\n",new_string);
	}
    }
  return nrAparitii;
}


char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    len_rep = strlen(rep);
    len_with = strlen(with);
    
    // count the number of replacements needed
    ins = orig;
    tmp = strstr(ins, rep); //prima adresa unde este gasit sirul cautat
    for (count = 0; tmp; count++) {
        ins = tmp + len_rep; //merge la urmatoarea adresa sarind peste sirul cautat
	tmp = strstr(ins, rep); //urmatoarea adresa unde este gasit sirul cautat
    }

    tmp = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
    result  = tmp;
    if (result == NULL)
      {
	printf("Memorie insuficienta!");
        exit(-1);
      }
    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}


int main(void)
{

  char s1[] = "Acesta este un string si un string este terminat cu 0x00";
  char s2[] = "string";
  char s3[] = "sir de caractere";

  //string_replace(s1, s2, s3);
  char *r = str_replace(s1,s2,s3);
  printf("%s\n",r);

  //int r = string_replace(s1, s2, s3);


  /*char s1[] = "Acesta este un string si un string este terminat cu 0x00";
  char s2[] = "Acesta este un sir si un sir este terminat cu 0x00";

  char s3[] = "string";
  char s4[] = "sir";
  printf("s1 = %d;   s2 = %d;   s3 = %d;   s4 = %d",strlen(s1),strlen(s2),strlen(s3),strlen(s4));*/
  return 0;
}
