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

typedef struct
{
  char *judet;
  int populatie, platiti, suma, altePlati;
}IND;

int nInds = 0;

char *getLine(FILE *f)
{
  char ch = 0; 
  char *line = NULL;
  int size=0, i=0;
  
  ch = fgetc(f);
  while(ch != EOF)
    {
      size++;
      line = (char*)realloc(line, size*sizeof(char));

      if(ch == '\n')
	{
	  line[i] = '\0';
	  break;
	}
      line[i] = ch;
      i++;
      ch = fgetc(f);
    }
  return line;
}

IND transformInd(char *line)
{
  IND ind;
  char *p = strtok(line,";");
  ind.judet = (char*)malloc(strlen(p)*sizeof(char));
  strcpy(ind.judet,p);

  p = strtok(NULL,";");
  ind.populatie = atoi(p);

  p = strtok(NULL,";");
  ind.platiti = atoi(p);

  p = strtok(NULL,";");
  
  p = strtok(NULL,";");
  ind.suma = atoi(p);

  p = strtok(NULL,";");
  ind.altePlati = atoi(p);
  
  return ind;
}

IND *populateInd(FILE *f)
{
  int size = 0;
  char *line = NULL;
  IND ind;
  IND *inds = NULL;

  line = getLine(f);
  while(line != NULL)
    {
      ind = transformInd(line);
      
      size++;
      inds = (IND *)realloc(inds, size*sizeof(IND));
      
      inds[nInds] = ind;
      nInds++;
      
      free(line);
      line = getLine(f);
    }
  return inds;
}

void curataInds(IND *inds)
{
  for(int i = 0;i<nInds;i++)
    {
      free(inds[i].judet);
    }
  free(inds);
}

void printareInds(IND *inds)
{
  for(int i=0;i<nInds;i++)
    {
      printf("%s -> %d;   %d;   %d;   %d\n", inds[i].judet, inds[i].populatie, inds[i].platiti, inds[i].suma, inds[i].altePlati);
    }
}

int main(void)
{
  IND *inds = NULL;
  FILE *f = NULL;

  f = fopen("indemnizatie.csv","r");
  if(f == NULL)
    {
      printf("NU pot citi din fisier!\n");
      exit(EXIT_FAILURE);
    }

  inds = populateInd(f);
  printareInds(inds);
  return 0;
}
