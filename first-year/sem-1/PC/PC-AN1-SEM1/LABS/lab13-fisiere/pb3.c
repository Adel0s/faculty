/*
Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define LINE_SIZE 5000
#define ARRAY_SIZE 2000


typedef struct
{
  char judet[100];
  uint32_t populatie;
  uint32_t benefP;
  uint16_t benefS;
  uint64_t sumaT;
  uint32_t altePlati;
}INDEMNIZATIE;

INDEMNIZATIE *processLine(char *line)
{
  static INDEMNIZATIE ind;
  
  char *p;
  if((p = strtok(line, ";")) == NULL)
    {
      return NULL;
    }
  strcpy(ind.judet, p);

  if((p = strtok(NULL, ";")) == NULL)
    {
      return NULL;
    }
  ind.populatie = strtol(p, NULL, 10);

  if((p = strtok(NULL, ";")) == NULL)
    {
      return NULL;
    }
  ind.benefP = strtol(p, NULL, 10);

  if((p = strtok(NULL, ";")) == NULL)
    {
      return NULL;
    }
  ind.benefS = strtol(p, NULL, 10);

  if((p = strtok(NULL, ";")) == NULL)
    {
      return NULL;
    }
  ind.sumaT = strtol(p, NULL, 10);

  if((p = strtok(NULL, ";")) == NULL)
    {
      return NULL;
    }
  ind.altePlati = strtol(p, NULL, 10);

  return &ind;
}

void printInd(INDEMNIZATIE *ind)
{
  printf("%s %d %d %ld %d \n", ind->judet, ind->benefP, ind->benefS, ind->sumaT, ind->altePlati);
}

void printIndArray(INDEMNIZATIE *array, int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%d ", i);
      printInd(&array[i]);
    }
}

void sortSUMAtotala(INDEMNIZATIE *inds, int nIND)
{
  char auxS[100];
  int auxI;
  int sorted = 0;
  do
    {
      sorted = 0;
      for(int i=1;i<nIND;i++)
	{
	  if(inds[i-1].sumaT>inds[i].sumaT)
	    {
	      strcpy(auxS,inds[i-1].judet);
	      strcpy(inds[i-1].judet, inds[i].judet);
	      strcpy(inds[i].judet , auxS);

	      auxI = inds[i-1].populatie;
	      inds[i-1].populatie = inds[i].populatie;
	      inds[i].populatie = auxI;
	      
	      auxI = inds[i-1].benefP;
	      inds[i-1].benefP = inds[i].benefP;
	      inds[i].benefP = auxI;

	      auxI = inds[i-1].benefS;
	      inds[i-1].benefS = inds[i].benefS;
	      inds[i].benefS = auxI;

	      auxI = inds[i-1].sumaT;
	      inds[i-1].sumaT = inds[i].sumaT;
	      inds[i].sumaT = auxI;

	      auxI = inds[i-1].altePlati;
	      inds[i-1].altePlati = inds[i].altePlati;
	      inds[i].altePlati = auxI;

	      sorted = 1;
	    }
	}
    }while(sorted);
}

int main(void)
{

  printf("startPROG\n");
  FILE *f = NULL;
  static char line[LINE_SIZE];
  static INDEMNIZATIE inds[ARRAY_SIZE];
  INDEMNIZATIE *aux;
  int count = 0;

  if((f = fopen("indemnizatie.csv", "r")) == NULL)
    {
      perror(NULL);
      exit(-1);
    }
  
  printf("Fisier deschis cu succes\n");
  fgets(line, LINE_SIZE, f); //pentru a ignora capul de tabel
  
  while(fgets(line, LINE_SIZE, f) != NULL)
    {
      if((aux = processLine(line)) != NULL)
	{
	  //printInd(aux);
	  inds[count++] = *aux;
	}
    }

  printIndArray(inds, count);
  printf("VECTOR SORTAT DUPA SUMA TOTALA:\n");
  sortSUMAtotala(inds,count);
  printIndArray(inds, count);

  if(fclose(f) != 0)
    {
      perror(NULL);
      exit(-1);
    }

  int maxPOP = inds[0].populatie;
  int maxPLATI = inds[0].altePlati;
  int maxPOPind=0;
  int maxPLATIind = 0;

  for(int i=1;i<count;i++)
    {
      if(inds[i].populatie>maxPOP)
	{
	 maxPOP = inds[i].populatie;
	 maxPOPind = i;
	}
      if(inds[i].altePlati>maxPLATI)
	{
	 maxPLATI = inds[i].altePlati;
	 maxPLATIind = i;
	}
    }
  FILE *out = NULL;
  out = fopen("rezultat.txt","w");
  fprintf(out, "Judetul cu populatia maxima de %d este: %s\n", inds[maxPOPind].populatie,inds[maxPOPind].judet);
  fprintf(out, "Judetul cu cea mai mare suma de %d este: %s\n", inds[maxPLATIind].altePlati, inds[maxPLATIind].judet);
  fclose(out);
  return 0;
}
