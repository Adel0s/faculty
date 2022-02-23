/*
Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- idx senzor - nr fara semn pe 8 biti
- valoare - nr cu semn pe 16 biti
O inregistrare codifica valoarea citita de un senzor la o anumita data. Valorile corecte pot fi in intervalul [-1000,1000]. Daca un senzor da din cand in cand valori in afara intervalului, atunci se considera ca are probleme. Daca toate valorile sunt in afara intervalului, atunci senzorul este defect.
Cerinte:
- sa se scrie o functie care creaza un fisier de test, ce cuprinde valori pentru un senzor care merge, altul care are probleme si altul defect.
- sa se citeasca fisierul de test si sa se afiseze care senzor merge, care are probleme si care e defect.
- se cere de la tastatura un an si o luna. Se cere sa se afiseze toate valorile senzorilor din acel an/luna.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct
{
  uint16_t an;
  uint8_t luna;
  uint8_t zi;
  uint8_t idx;
  int16_t val;
}Rec;
  
uint32_t nDate;
Rec date[1000];

Rec dateTest[] =
  {
   {2021,7,10,1,570},
   {2021,7,12,0,-1570},
   {2021,7,20,1,-300},
   {2021,7,10,2,-5500},
   {2021,7,10,2,10000},
   {2021,7,10,0,31},
  };

void scriere()
{
  FILE *f;
  f = fopen("test.data","wb");
  if(f == NULL)
    {
      printf("Nu am putut deschide fisierul!\n");
      exit(-1);
    }

  uint32_t nRec = sizeof(dateTest)/sizeof(Rec);
  fwrite(&nRec, sizeof(nRec), 1, f);
  fwrite(dateTest, sizeof(Rec), nRec, f);
  
  fclose(f);
}

void citire()
{
  FILE *f;
  f = fopen("test.data", "rb");
  if(f == NULL)
    {
      printf("NU am putut deschide fisierul!\n");
      exit(-1);
    }

  fread(&nDate, sizeof(nDate), 1, f);
  fread(date, sizeof(Rec), nDate, f);
  
  fclose(f);
}

int main(void)
{
  scriere();
  citire();

  int nTotal, nBad;
  for(int s=0;s<256;s++)
    {
      nTotal = 0;
      nBad = 0;
      for(int i=0;i<nDate;i++)
	{
	  if(date[i].idx == s)
	    {
	      if(date[i].val <-1000 || date[i].val > 1000)
		{
		  nBad++;
		}
	      nTotal++;
	    }
	}
      
      if(nTotal)
	{
	  if(nBad == 0) printf("Senzorul %d este bun.\n", s);
	  if(nBad>0 && nBad<nTotal) printf("Senzorul %d are probleme.\n", s);
	  if(nBad == nTotal) printf("Senzorul %d e defect.\n", s);
	}
    }

  int an, luna;
  printf("an = "); scanf("%d", &an);
  printf("luna = "); scanf("%d", &luna);

  for(int i=0;i<nDate;i++)
    {
      if(date[i].an == an || date[i].luna == luna)
	{
	  printf("senzor = %d, valoare = %d\n", date[i].idx, date[i].val);
	}
    }
  
  return 0;
}
