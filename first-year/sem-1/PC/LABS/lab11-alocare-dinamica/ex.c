#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
  char *sir1="ion si ana citesc";
  char *p;
  p=(char*)malloc(sizeof(char) * ( strlen(sir1) ) +1 );
  if(p==NULL){
    printf("memorie insuficienta\n");
    return 1;
  }
  strcpy(p,sir1);
  puts(p);

  char *sir2=" cu placere.";
  char *aux = realloc(p, sizeof(char)*(strlen(p) + strlen(sir2)+1));
  if(aux==NULL){
    printf("memorie insuficienta\n");
    return 1;
  }
  strcat(p,sir2);
  puts(p);

  free(p);
  return 0;
}
