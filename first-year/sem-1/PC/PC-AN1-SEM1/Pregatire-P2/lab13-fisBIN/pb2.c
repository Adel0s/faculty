/*
Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt fisier in format text, fiecare numar in zecimal pe un alt rand. Program testa functionalitatea prin citirea aceluiasi fisier ca si cel de la exercitiul anterior, va sorta datele obtinute si le va scrie in fisier conform cerintei.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t *v = NULL;
int nValori = 0;
long fileSize = 0;

void citire()
{
  FILE *f;
  f = fopen("integers.bin", "rb");
  if(f == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }

  fseek(f, 0 , SEEK_END);
  fileSize = ftell(f);
  rewind(f);

  nValori = fileSize/sizeof(uint32_t);

  v = (uint32_t*)malloc(nValori*sizeof(uint32_t));
  if(v == NULL)
    {
      printf("Memorie insuficienta!");
      exit(-1);
    }

  fread(v, sizeof(uint32_t), nValori, f);
  fclose(f);
}

void sortare()
{
  int s,i,aux;
  do
    {
    s = 0;
    for (i = 1; i < nValori; i++)
      {
	if (v[i - 1] < v[i])
	  {
	    aux = v[i - 1];
	    v[i - 1] = v[i];
	    v[i] = aux;
	    s = 1;
	  }
      }
    } while (s);
}

void scriere()
{
  FILE *fis;
  fis = fopen("dateOut.txt","w");
  for(int i=0;i<nValori;i++)
    fprintf(fis, "v[%d] = %d\n", i, v[i]);
  
}

int main(void)
{
  citire();
  printf("%d\n", nValori);
  for(int i=0;i<nValori;i++)
    {
      printf("%d\n",v[i]);
    }
  sortare();
  scriere();
  
  free(v);
  return 0;
}
