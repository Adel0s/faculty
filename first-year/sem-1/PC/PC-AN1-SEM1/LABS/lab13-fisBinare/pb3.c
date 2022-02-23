/*
Sa se scrie si testeze o functie ce primeste ca argument o cale de fisier sursa si o cale de fisier destinatie. Programul va copia continutul fisierului sursa in fisierul destinatie. Se vor folosi functii specializate de lucru cu fisiere binare.
 */

#include <stdio.h>
#include <stdlib.h>

void copyFile(char *sursa, char *destinatie)
{
  FILE *fin, *fout;
  char *buffer;
  size_t fileSize = 0;
  int copied = 0;
  
  fin = fopen(sursa, "rb");
  if(fin == NULL)
    {
      printf("NU pot citi fisierul!\n");
      exit(EXIT_FAILURE);
    }

  ///cautam dimensiunea fisierului mergand cu cursorul la final si luand-i valoarea
  fseek(fin,0,SEEK_END); ///ducem la final cursorul
  fileSize = ftell(fin); ///aflam valoarea -> chiar dimensiunea fisierului
  rewind(fin);///ducem cursorul inapoi la inceputul fisierului

  ///alocam dinamic memorie bufferului(continutul fisierului)
  buffer = (char*)malloc(fileSize*sizeof(char));
  if(buffer == NULL)
    {
      printf("Memorie insuficienta!\n");
      exit(EXIT_FAILURE);
    }

  ///citim in buffer datele din fisierul de intrare
  fread(buffer,sizeof(char),fileSize,fin);

  fout = fopen(destinatie, "wb");
  if(fout == NULL)
  {
    printf("NU pot copia fisierul!\n");
    exit(EXIT_FAILURE);
  }

  ///copiem datele din sursa in destinatie
  fwrite(buffer, sizeof(char), fileSize, fout);

  ///verificam daca au fost scrise toate datele din buffer
  copied = fwrite(buffer, sizeof(char), fileSize, fout);
  if(copied == fileSize)
    {
      printf("Fisier copiat cu succes!\n");
    }
  
  free(buffer);
}

int main(void)
{
  copyFile("integers.bin","integersCopied.bin");
  return 0;
}
