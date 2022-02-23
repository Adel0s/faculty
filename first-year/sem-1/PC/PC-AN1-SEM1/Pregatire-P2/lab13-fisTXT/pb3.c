/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. Fișierul conține informații statistice oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei (https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună din anul 2021. Fișierul are următorul cap de tabel ce descrie câmpurile din liniile conținue

Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi

Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

Fișierul se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/indemnizatie.csv
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

typedef struct
{
  char *judet;
  int populatie, beneficiari, suma, altePlati;
}IND;

IND *inds = NULL;
int nInds = 0;

char* getLine(FILE *f)
{
  char *line = NULL;
  char ch = 0;
  int size = 0, i = 0;

  while((ch = fgetc(f)) != EOF)
    {
      if(i == size)
	{
	  size += CHUNK;
	  line = (char*)realloc(line, size * sizeof(char));
	}

      if(ch == '\n')
	{
	  ch = '\0';
	  break;
	}
      line[i++] = ch;
    }
  return line;
}

IND transformInd(char *line)
{
  char *p = NULL;
  IND ind;

  p = strtok(line,";");
  ind.judet = (char*)malloc((strlen(p)+1) * sizeof(char));
  if(ind.judet==NULL)
    {
      printf("Memorie insuficienta!\n");
      exit(-1);
    }
  strcpy(ind.judet, p);

  p = strtok(NULL,";");
  ind.populatie = strtol(p,NULL,10);

  p = strtok(NULL,";");
  ind.beneficiari = strtol(p,NULL,10);

  p = strtok(NULL,";");

  p = strtok(NULL,";");
  ind.suma = strtol(p,NULL,10);

  p = strtok(NULL,";");
  ind.altePlati = strtol(p,NULL,10);
  
  return ind;
}

IND *populateInd(FILE *f)
{
  IND ind;
  IND *inds = NULL;
  char *line = NULL;
  int size = 0;

  while((line = getLine(f)) != NULL)
    {
      ind = transformInd(line);
      if(nInds == size)
	{
	  size += ARRAY_CHUNK;
	  inds = (IND *)realloc(inds, size * sizeof(IND));
	}
      inds[nInds] = ind;
      nInds++;

      free(line);
      line = NULL;
    }
  return inds;
}

void freeInds(IND *inds)
{
  for(int i=0;i<nInds;i++)
    {
      free(inds[i].judet);
    }
  free(inds);
}

void printInds(IND *inds)
{
     for(int i=0;i<nInds;i++)
    {
      printf("%s -> %d;   %d;   %d;   %d\n", inds[i].judet, inds[i].populatie, inds[i].beneficiari, inds[i].suma, inds[i].altePlati);
    }
}

void judetSort(IND *inds)
{
  IND ind;
  for(int i=0;i<=nInds;i++)
    {
      for(int j=i+1;j<nInds;j++)
	{
	  if(strcmp(inds[i].judet, inds[j].judet) < 0)
	    {
	      ind = inds[i];
	      inds[i] = inds[j];
	      inds[j] = ind;
	    }
	}
    }
}

int main(void)
{
  FILE *f = NULL;
  f = fopen("indemnizatie.csv", "r");
  if(f == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }

  inds = populateInd(f);
  printInds(inds);

  judetSort(inds);
  printInds(inds);
  
  fclose(f);
  return 0;
}
