/*
Sa se implementeze o baza de date care contine urmatoarele tipuri de produse:
     - stick USB: interfata (A sau C), capacitate
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
   A,
   C
  }tipInterfata;

typedef enum
  {
   stick,
   baterie
  }tipProdus;

typedef struct
{
  tipProdus tip;
  float pret;
  int stoc;
  int cod;
  union
  {
    struct
    {
      tipInterfata interfata;
      int capacitate;
    }stick;

    struct
    {
      float voltaj;
    }baterie;
  };
}PRODUS;

int nProduse = 0;
PRODUS *produse = NULL;

void introducere()
{
  int cod, i;
  printf("Cod: ");
  scanf("%d", &cod);

  for(i=0;i<nProduse;i++)
    {
      if(produse[i].cod == cod)
	{
	  produse[i].stoc++;
	  return;
	}
    }

  nProduse++;
  produse = (PRODUS*)realloc(produse, nProduse*sizeof(PRODUS));
  if(produse == NULL)
    {
      printf("Memorie insuficienta!\n");
      exit(-1);
    }

  produse[nProduse-1].cod = cod;

  printf("Pret: ");
  scanf("%f", &produse[nProduse-1].pret);
  produse[nProduse-1].stoc = 1;

  int tipProdus, tipInterfata;
  printf("Tip produs: 0 -> stick   1 -> baterie   :> ");
  scanf("%d", &tipProdus);

  switch(tipProdus)
    {
    case 0:
      produse[nProduse-1].tip = stick;
      printf("Tip interfata: 0 -> A   1 -> C   :> ");
      scanf("%d",&tipInterfata);

      switch(tipInterfata)
	{
	  
	case 0:
	  produse[nProduse-1].stick.interfata = A;
	  break;

	case 1:
	  produse[nProduse-1].stick.interfata = C;
	  break;
	default: printf("Tip interfata gresit!\n");
	}

      printf("Capacitate(GB): ");
      scanf("%d", &produse[nProduse-1].stick.capacitate);
      break;

    case 1:
      produse[nProduse-1].tip = baterie;
      printf("Voltaj(V): ");
      scanf("%f", &produse[nProduse-1].baterie.voltaj);
      break;

    default: printf("Tip produs incorect!\n");
    }
}

void listare()
{
  int i = 0;

  for(i=0;i<nProduse;i++)
    {
      if(produse[i].stoc > 0)
	{
	  printf("Cod produs - %u; stoc - %u; pret - %g\n", produse[i].cod, produse[i].stoc, produse[i].pret);
	  switch(produse[i].tip)
	    {
	    case stick:
		printf("Interfata - %c; capacitate - %uGB\n", produse[i].stick.interfata == A ? 'A'  : 'C',produse[i].stick.capacitate);
		break;
	    case baterie:
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
  for(i=0;i<nProduse;i++)
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
	}
    }
}

int main(void)
{
  int opt = 0;
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
	  introducere();
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
