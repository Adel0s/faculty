/*
Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt fisier in format text, fiecare numar in zecimal pe un alt rand. Program testa functionalitatea prin citirea aceluiasi fisier ca si cel de la exercitiul anterior, va sorta datele obtinute si le va scrie in fisier conform cerintei.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t *v;
int nValori;
long fileSize;

void citire()
{
  FILE *fis;
  fis = fopen("integers.bin","rb");
  if(fis == NULL)
    {
      puts("NU pot citi din fisier!");
      exit(EXIT_FAILURE);
    }
  
  ///cautam dimensiunea fisierului mergand cu cursorul la final si luand-i valoarea
  fseek (fis , 0 , SEEK_END);///ducem la final cursorul
  fileSize = ftell(fis); ///aflam valoarea -> chiar dimensiunea fisierului in biti
  rewind (fis);///ducem cursorul inapoi la inceputul fisierului

  ///numarul de valori
  nValori = fileSize/sizeof(uint32_t); ///dimensiunea fisierului in bytes/ la 

  ///alocam dinamic memorie vectorului
  v = (uint32_t *)malloc(nValori*sizeof(uint32_t));

  if(v == NULL)
    {
      printf("Memorie insuficienta!");
      exit(EXIT_FAILURE);
    }
  
  fread(v,sizeof(int),nValori,fis);
  fclose(fis);
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
  printf("%d\n",nValori);
  for(int i=0;i<nValori;i++)
    printf("v[%d] = %d\n", i, v[i]);
  
  sortare();
  scriere();
  
  free(v); ///eliberam memoria alocata vectorului prin malloc
  return 0;
}
