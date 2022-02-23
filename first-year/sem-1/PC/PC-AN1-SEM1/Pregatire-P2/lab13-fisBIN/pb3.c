/*
Sa se scrie si testeze o functie ce primeste ca argument o cale de fisier sursa si o cale de fisier destinatie. Programul va copia continutul fisierului sursa in fisierul destinatie. Se vor folosi functii specializate de lucru cu fisiere binare.
 */

#include <stdio.h>
#include <stdlib.h>

void copyFile(FILE *sursa, FILE *destinatie)
{
  char *buffer;
  size_t fileSize = 0;
  int copied = 0;

  fseek(sursa,0,SEEK_END);
  fileSize = ftell(sursa);
  rewind(sursa);

  buffer = (char*)malloc(fileSize*sizeof(char));
  if(buffer == NULL)
    {
      printf("Memorie insuficienta!\n");
      exit(-1);
    }

  fread(buffer,sizeof(char),fileSize,sursa);
  fwrite(buffer,sizeof(char),fileSize,destinatie);

  copied = fwrite(buffer,sizeof(char),fileSize,destinatie);
  if(copied == fileSize)
    {
      printf("Fisier copiat cu suuces!\n");
    }
  free(buffer);
}


int main(void)
{
  FILE *sursa = NULL, *destinatie = NULL;
  sursa = fopen("integers.bin","rb");
  destinatie = fopen("copiedIntegers.bin", "wb");
  copyFile(sursa,destinatie);
  return 0;
}
