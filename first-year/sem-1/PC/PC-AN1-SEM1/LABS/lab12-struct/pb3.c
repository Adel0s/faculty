/*
Se consideră o structură Persoana care are un câmp nume și altul varsta. Să se scrie o funcție care primește ca parametru o persoană și îi modifică numele astfel încât prima literă să fie mare iar restul mici. Să se testeze funcția cu o persoană citită de la tastatură.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
  char nume[100];
  int varsta;
}Persoana;

void toUpper(Persoana *p)
{
  int i;
   if(p->nume[0]>='a' && p->nume[0]<='z')
     {
       p->nume[0] = p->nume[0] - 32;
     }
  for(i=1;i<strlen(p->nume);i++)
    {
      if(p->nume[i]>='a' && p->nume[i]<='z')
	p->nume[i] = p->nume[i] - 32;
      if(p->nume[i]>='A' && p->nume[i]<='Z')
	p->nume[i] = p->nume[i] + 32;
    }
}

int main(void)
{
  Persoana p;
  scanf("%s", p.nume);
  toUpper(&p);
  printf("%s\n",p.nume);
  return 0;
}
