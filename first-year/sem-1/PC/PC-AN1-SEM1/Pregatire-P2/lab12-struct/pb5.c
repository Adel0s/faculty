/*
Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești. O insectă se caracterizează prin număr picioare și durata medie de viată în zile, o pasăre prin viteza de zbor și lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește prin greutate, adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va defini un tablou de astfel de structuri și se vor implementa funcții de adaugare animal, stergere animal și printare animale.
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
  {
   insecta,
   pasare,
   mamifer,
   peste,
  }tipAnimal;

typedef enum
  {
   carnivor,
   ierbivor,
   omnivor,
  }tipMancare;

typedef struct
{
  tipAnimal tip;
  union
  {
    struct
    {
      int picioare;
      int durataViata;
    }insecta;

    struct
    {
      float vitezaZbor;
      float lAripi;
    }pasare;

    struct
    {
      float greutate;
      float inaltime;
      tipMancare tipM;
    }mamifer;

    struct
    {
      float greutate;
      float adancime;
      float salinitate;
    }peste;
  };
}ANIMAL;

ANIMAL *animale = NULL;
int nAnimale = 0;

void adaugare()
{
  nAnimale++;
  animale = (ANIMAL*)realloc(animale, nAnimale * sizeof(ANIMAL));
  if(animale == NULL)
    {
      printf("Memorie insuficienta!");
      exit(-1);
    }
  
  int tipAnimal, tipMancare;
  printf("Tip animal: 0 -> insecta   1 -> pasare   2 -> mamifer    3 -> peste\n");
  scanf("%d", &tipAnimal);

  switch(tipAnimal)
    {
    case 0:
      animale[nAnimale-1].tip = insecta;
      
      printf("Numar de picioare: ");
      scanf("%d", &animale[nAnimale-1].insecta.picioare);
      
      printf("Cate zile traieste in medie: ");
      scanf("%d", &animale[nAnimale-1].insecta.durataViata);
      break;

    case 1:
       animale[nAnimale-1].tip = pasare;

      printf("Viteza de zbor: ");
      scanf("%f", &animale[nAnimale-1].pasare.vitezaZbor);
      
      printf("Lungime aripi: ");
      scanf("%f", &animale[nAnimale-1].pasare.lAripi);
      break;

    case 2:
       animale[nAnimale-1].tip = mamifer;

        printf("Greutate(kg): ");
        scanf("%f", &animale[nAnimale-1].mamifer.greutate);
      
        printf("Inaltime(m): ");
        scanf("%f", &animale[nAnimale-1].mamifer.inaltime);
      
         printf("Mamiferul este: 0 -> carnivor   1 -> ierbivor   2 -> omnivor    ");
         scanf("%d", &tipMancare);
	 switch(tipMancare)
	   {
	   case 0:
	     animale[nAnimale-1].mamifer.tipM = carnivor;
	     break;

	   case 1:
	     animale[nAnimale-1].mamifer.tipM = ierbivor;
	     break;

	   case 2:
	     animale[nAnimale-1].mamifer.tipM = omnivor;
	     break;
	   
	   default: printf("Tip mancare incorect!\n");
	   }
	 break;

    case 3:
       animale[nAnimale-1].tip = peste;
       printf("Greutate(kg): ");
       scanf("%f", &animale[nAnimale-1].peste.greutate);
      
       printf("Adancime maxima(m): ");
       scanf("%f", &animale[nAnimale-1].peste.adancime);
      
       printf("Salinitate(%%): ");
       scanf("%f", &animale[nAnimale-1].peste.salinitate);
      break;

    default: printf("Tip animal incorect!\n");
    }
}

void printare()
{
  int i;
  for(i=0;i<nAnimale;i++)
    {
      switch(animale[i].tip)
	{
	case 0:
	  printf("Tip animal -> insecta\n");
	  printf("Are %d picioare si traieste in medie %d zile.\n", animale[i].insecta.picioare, animale[i].insecta.durataViata);
	  break;
	case 1:
	  printf("Tip animal -> pasare\n");
	  printf("Pasarea zboara cu %g km/h si are lungimea aripilor de %g metri\n", animale[i].pasare.vitezaZbor, animale[i].pasare.lAripi);
	  break;
	case 2:
	  printf("Tip animal -> mamifer\n");
	  printf("Mamimferul are %g kg si inaltime de %g metri\n", animale[i].mamifer.greutate, animale[i].mamifer.inaltime);
	  switch(animale[i].mamifer.tipM)
	    {
	    case 0:
	      printf("Mamiferul este carnivor\n");
	      break;
	    case 1:
	       printf("Mamiferul este ierbivor\n");
	      break;
	    case 2:
	       printf("Mamiferul este omnivor\n");
	      break;
	    }
	  break;
	case 3:
	  printf("Tip animal -> peste\n");
	  printf("Pestele are greutatea de %g kg traieste la o adancime de %g metri, la salinitate de %g procente\n,", animale[i].peste.greutate, animale[i].peste.adancime, animale[i].peste.salinitate);
	  break;
	}
      printf("\n");
    }
}

int main(void)
{
  int opt;

  for(; ;)
    {
      printf("\n");
      printf("1 - Adaugare animal \n");
      printf("2 - Stergere animal \n");
      printf("3 - Afisare animale \n");
      printf("4 - Close \n");
      
      printf("Optiunea aleasa este: ");
      scanf("%d", &opt);

      printf("\n");

      switch(opt)
	{
	case 1:
	  adaugare();
	  break;
	  
	case 2:
	  //stergere();
	  break;
	  
	case 3:
	  printare();
	  break;
	  
	case 4:
	  return 0;
	  break;
	  
	default: printf("Comanda incorecta!");
	}
    }
  return 0;
}
