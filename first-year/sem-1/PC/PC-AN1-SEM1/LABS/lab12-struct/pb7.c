/*
Sa se implementeze o baza de date care contine urmatoarele tipuri de produse:
     - stick USB: interfata (A sau C), capacitate(GB)
     - baterie: voltaj
Fiecare produs va avea asociate un pret, stoc si un cod unic. Operatiile vor fi:
     - introducere - introduce un nou produs, inclusiv codul sau. Daca codul exista deja, se incrementeaza stocul, altfel se considera stoc=1
     - listare - se listeaza doar produsele existente pe stoc
     - stergere - se da un cod si se decrementeaza stocul. Produsele cu stoc 0 raman in baza de date. Daca deja este 0, se emite mesaj de atentionare.
Programul va folosi alocare dinamica, astfel incat sa se foloseasca doar strictul necesar de memorie. Utilizatorul va avea la dispozitie un meniu, de unde va putea apela fiecare functie.
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
  {
   STICK,
   BAT
  }TipProdus;

typedef enum
  {
   A,
   C
  }TipInterfata;

typedef struct
{
  unsigned stoc;
  unsigned cod;
  float pret;
  TipProdus tip;
  union
  {
    struct
    {
      TipInterfata interfata;
      unsigned capacitate;
    }stick;

    struct
    {
      float voltaj;
    }baterie;
  };
}PRODUS;

PRODUS *produse = NULL;
int NrProduse=0;

void adaugare()
{
  unsigned cod;
  printf("Cod: ");
  scanf("%u",&cod);
  int i;

  for(i=0;i<NrProduse;i++)
    {
      if(cod == produse[i].cod)
	{
	  produse[i].stoc++;
	  return;
	}
    }

  PRODUS *aux = (PRODUS*)realloc(produse,sizeof(PRODUS)*(NrProduse+1));
  if(aux == NULL)
    {
      printf("Memorie insuficienta!\n");
      exit(-1);
    }
  produse = aux;
  produse[NrProduse].cod = cod;

  printf("Pret: ");
  scanf("%f", &produse[NrProduse].pret);
  produse[NrProduse].stoc = 1;

  int tipProd, tipInt;
  printf("Tip produs: 0 -> stick   1 -> baterie   :> ");
  scanf("%d",&tipProd);

  switch(tipProd)
    {
    case 0:
      produse[NrProduse].tip = STICK;
      printf("Tip interfata: 0 -> A   1 -> C   :> ");
      scanf("%d",&tipInt);
      switch(tipInt)
	{
	case 0:
	  produse[NrProduse].stick.interfata = A;
	  break;
	case 1:
	  produse[NrProduse].stick.interfata = C;
	  break;
	default: printf("Interfata incorecta!\n");
	}
      printf("Capacitate stick(GB): ");
      scanf("%u",&produse[NrProduse].stick.capacitate);
      break;
      
    case 1:
      produse[NrProduse].tip = BAT;
      printf("Voltaj baterie(V): ");
      scanf("%f",&produse[NrProduse].baterie.voltaj);
      break;

    default: printf("Tip produse incorect!\n");
    }

  NrProduse++;
}

void listare()
{
  int i;
  for(i=0;i<NrProduse;i++)
    {
      if(produse[i].stoc > 0)
	{
	  printf("Cod produs - %u; stoc - %u; pret - %g\n", produse[i].cod, produse[i].stoc, produse[i].pret);
	  switch(produse[i].tip)
	    {
	    case STICK:
	      printf("Interfata - %c; capacitate - %uGB\n", produse[i].stick.interfata == A ? 'A' : 'C', produse[i].stick.capacitate);
	      break;
	    case BAT:
	      printf("Voltaj baterie - %g V\n",produse[i].baterie.voltaj);
	      break;
	    }
	}
    }
}

void stergere()
{
  unsigned cod;
  printf("Introduceti codul produsului pe care doritit sa il stergeti -> ");
  scanf("%u",&cod);

  int i;
  for(i=0;i<NrProduse;i++)
    {
      if(produse[i].cod == cod)
	{
	  if(produse[i].stoc == 0)
	    {
	      printf("Produsul nu se afla pe stoc!\n");
	    }
	  else
	    {
	      produse[i].stoc--;
	    }
	  //return ;
	}
    }
}

int main(void)
{
  int opt;
  for(; ;)
    {
      printf("\n");
      printf("1. Adaugare\n");
      printf("2. Listare\n");
      printf("3. Stergere\n");
      printf("4. Iesire\n");
      printf("Optiunea ta este -> ");

      scanf("%d",&opt);
      printf("\n");

      switch(opt)
	{
	case 1:
	  adaugare();
	  break;
	case 2:
	  listare();
	  break;
	case 3:
	  stergere();
	  break;
	case 4:
	  return 0;
	  break;
	}
      
    }
  return 0;
}
