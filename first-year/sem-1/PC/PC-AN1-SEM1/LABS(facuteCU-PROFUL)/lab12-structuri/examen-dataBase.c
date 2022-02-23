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
  TP_STICK,
  TP_BAT
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
    struct{
      TipInterfata interfata;
      unsigned capacitate;
    }stick;

    struct{
      float voltaj;
    }baterie;
  };
}PRODUS;

PRODUS *produse = NULL;
int NrProduse = 0;

void introducere()
{
  unsigned cod;
  printf("Cod: ");
  scanf("%u", &cod);
  int i;
  for(i=0;i<NrProduse;i++)
    {
      if(cod == produse[i].cod)
	{
	  produse[i].stoc++;
	  return;
	}
    }

  PRODUS *aux = (PRODUS*)realloc(produse, sizeof(PRODUS)*(NrProduse + 1));
  if(aux == NULL)
    {
      perror("Memorie insuficienta!");
      exit(-1);
    }
  produse = aux;
  produse[NrProduse].cod = cod;  /// Adaugam noul produs daca acesta nu exista deja in baza de date si il vom adauga pe pozitia NrProduse fiind urmatoarea pozitie libera din vectorul produse adica daca avem 3 produse NrProduse este chiar 3 iar cum vectorul ia valori de la 0 la 2, 3 este urmatoarea pozitie libera

  printf("Pret: ");
  scanf("%f", &produse[NrProduse].pret);
  produse[NrProduse].stoc = 1;
  int tipAUX, tipInterfata;
  printf("Tip produs: 0 -> stick     1 -> baterie :> ");
  scanf("%d", &tipAUX);

  switch(tipAUX)
    {
    case 0:
      produse[NrProduse].tip = TP_STICK;
      printf("Tip interfata: 0 - A sau 1 - C :> ");
      scanf("%d", &tipInterfata);
      switch(tipInterfata)
	{
	case 0:
	  produse[NrProduse].stick.interfata = A;
	  break;

	case 1:
	  produse[NrProduse].stick.interfata = C;
	  break;

	default: printf("Interfata inexistenta");
	  printf("Capacitate stick(GB): ");
	  scanf("%d", &produse[NrProduse].stick.capacitate);
	}
      break;

    case 1:
      printf("Voltaj baterie: ");
      scanf("%f", &produse[NrProduse].baterie.voltaj);
      break;

    default: printf("Tip produs incorect");
    }

  NrProduse++;  ///pregatim pentru urmatorul produs incrementand numarul lor cu 1
}

void listare()
{
  int i;
  for(i=0;i<NrProduse;i++)
    {
      if(produse[i].stoc > 0)  ///daca se afla pe stoc atunci il listam
	{
	  printf("cod = %u, stoc = %u, pret = %g", produse[i].cod, produse[i].stoc, produse[i].pret);
	  switch(produse[i].tip)
	    {
	    case TP_STICK:
	      printf(", interfata = %c, capacitate = %u\n", produse[i].stick.interfata == A ? 'A' : 'C', produse[i].stick.capacitate);
	      break;

	    case TP_BAT:
	      printf(", voltaj = %g", produse[i].baterie.voltaj);
	      break;
	    }
	}
    }
}

void stergere()
{
  unsigned cod;
  printf("Introduceti codul produsului pe care doriti sa il stergeti: ");
  scanf("%u", &cod);
  int i;

  for(i=0;i<NrProduse;i++)
    {
      if(produse[i].cod == cod)
	{
	  if(produse[i].stoc == 0)
	    {
	      printf("Produsul nu se afla pe stoc!");
	    }
	  else
	    {
	      produse[i].stoc--;
	    }
	  return;
	}
    }
}

int main(void)
{
  int opt = 0;
  for(; ;)
    {
      printf("\n");
      printf("1 - Adaugare produs \n");
      printf("2 - Listare produse \n");
      printf("3 - Sterge un produs \n");
      printf("4 - Close \n");
      printf("Optiunea aleasa este:");
     
      scanf("%d", &opt);

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
	  
	default: printf("Comanda incorecta!");
	}
    }
  return 0;
}
