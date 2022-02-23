/*
Să se scrie un program care ţine evidenţa mașinilor de spălat dintr-un magazin. Pentru fiecare produs se specifică în parte: producător, model, pret de furnizor, preț de vânzare, greutate, tip încărcare (frontală/verticală). În functie de tipul de încărcare introdus de la tastatură se vor citi următoarele caracteristici:
- Pentru încărcare frontală: capacitate de încărcare (kg), clasa de eficiență energetică,programe;
- Pentru încărcare verticală: tip afișaj, număr programe, selector centrifugare, nivel de zgomot la spălare;
Să se creeze un meniu care să conţină următoarele operaţii:
1. Citirea produselor deja salvate aflate în fișierul „magazin.bin” si afișarea acestora pe ecran
2. Adăugarea unui nou produs în stocul magazinului și salvarea acestuia în fișierul „magazin.bin” (nu se va crea un nou fisier deoarece pot exista produse adăugate anterior)
3. Afişarea tuturor mașinilor de spălat pe tipuri de încărcare din magazin.
4. Crearea unui fișier numit „oferta.txt” și salvarea tuturor mașinilor de spălat care au un preț mai mic dat de la tastatură.Nota: In cadrul fisierului oferta.txt informatia va fi structurata astfel incat fiecare linie din cadrul fisierului oferta.txt sa contina informatia completa despre o masina de spalat. Informatiile vor fi separate prin spatii astfel:
- pentru masinile de spalat cu incarcare frontala : producator model pret_de_furnizare tip_de_incarcare capacitate_de_incarcare clasa_de_eficienta programe
- pentru masinile de spalat cu incarcare verticala:
producator model pret_de_furnizare tip_de_incarcare tip_afisaj numar_programe selector_centrifugare nivel_de_zgomot
5. Cautarea unei mașini de spălat dupa greutate.
6. Sortarea categoriei încărcare frontală după clasa de eficiență energetică.
7. Să se afișeze toate mașinile de spălat de la un anumit producător precizând tipul de încărcare.
8. Iesire
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum
  {
   frontala,
   verticala,
  }TipIncarcare;

typedef struct
{
  char producator[1000];
  char model[1000];
  float pret_fur;
  float pret_vnz;
  float greutate;
  TipIncarcare tip;

  union
  {
    struct
    {
      int kg;
      int programe;
      char clasa[30];
    }frontala;

    struct
    {
      char tip_afisaj[100];
      int programe;
      int centrifugare;
      int zgomot;
    }verticala;
  };
}MASINA_SPALAT;

MASINA_SPALAT masini[1000];
int nMasini = 0;

MASINA_SPALAT masini[] =
  {
   {"whirpool","WH10078",1000,1200,100,verticala,{"digital",10,2,30}},
   {"beko","BK10345",1500,1800,90,frontala,{50,9,"AAA"}},
  };

int main(void)
{
  FILE *fis;
  fis = fopen("magazin.bin","wb");
  fclose(fis);
  return 0;
}
