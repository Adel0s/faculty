/*
Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești. O insectă se caracterizează prin număr picioare și durata medie de viată în zile, o pasăre prin viteza de zbor și lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește prin greutate, adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va defini un tablou de astfel de structuri și se vor implementa funcții de adaugare animal, stergere animal și printare animale
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum 
  {
   insecta,
   pasare,
   mamifer,
   peste,
  }tip_animal_t;

typedef enum
  {
   carnivor,
   ierbivor,
   omnivor,
  }tip_mancare_t;

typedef struct
{
  tip_animal_t tip;
  union
  {
    struct
    {
      int picioare;
      int zile;
    }insecta;
  
    struct
    {
      float viteza;
      float lungime;
    }pasare;

    struct
    {
      float greutate;
      float inaltime;
      tip_mancare_t tip_mancare;
    }mamifer;

    struct
    {
      float greutate;
      float adancime;
      int salinitate;
    }peste;
  };
}ANIMAL;

ANIMAL animale[1000];
int NrAnimale = 0;

void adaugare()
{
  int tipAnimal;
  int tipMancare;
  printf("Tip animal: 0 -> insecta   1 -> pasare   2 -> mamifer   3 -> peste\n");
  scanf("%d",&tipAnimal);

  switch(tipAnimal)
    {
      case 0:
	animale[NrAnimale].tip = insecta;
	printf("Numar de picioare: ");
	scanf("%d",&animale[NrAnimale].insecta.picioare);
	
	printf("Cate zile traieste in medie: ");
	scanf("%d",&animale[NrAnimale].insecta.zile);
	break;
	
      case 1:
	animale[NrAnimale].tip = pasare;
	printf("Viteza de zbor: ");
	scanf("%f",&animale[NrAnimale].pasare.viteza);
	
	printf("Lungime aripi: ");
	scanf("%f",&animale[NrAnimale].pasare.lungime);
	break;
	
      case 2:
	animale[NrAnimale].tip = mamifer;
	printf("Greutate(kg): ");
	scanf("%f",&animale[NrAnimale].mamifer.greutate);
	
	printf("Inaltime(m): ");
	scanf("%f",&animale[NrAnimale].mamifer.inaltime);

	printf("Mamiferul este: 0 -> carnivor   1 -> ierbivor   2 -> omnivor\n");
	scanf("%d",&tipMancare);
	switch(tipMancare)
	  {
	  case 0:
	    animale[NrAnimale].mamifer.tip_mancare = carnivor;
	    break;
	  case 1:
	    animale[NrAnimale].mamifer.tip_mancare = ierbivor;
	    break;
	  case 2:
	    animale[NrAnimale].mamifer.tip_mancare = omnivor;
	    break;
	  default: printf("Tip mamifer incorect!\n");
	  }
	break;
	
    case 3:
      	animale[NrAnimale].tip = peste;
	printf("Greutate(kg): ");
	scanf("%f",&animale[NrAnimale].peste.greutate);
	
	printf("Adancime(m): ");
	scanf("%f",&animale[NrAnimale].peste.adancime);

	printf("Salinitate(procente): ");
	scanf("%d",&animale[NrAnimale].peste.salinitate);
      break;
      
    default: printf("Tip animal incorect!\n");
    }
  NrAnimale++;
}

void printare()
{
  int i;
  for(i=0;i<NrAnimale;i++)
    {
      switch(animale[i].tip)
	{
	case 0:
	  printf("Tip animal -> insecta\n");
	  printf("Are %d picioare si traieste in medie %d zile.\n", animale[i].insecta.picioare, animale[i].insecta.zile);
	  break;
	case 1:
	  printf("Tip animal -> pasare\n");
	  printf("Pasarea zboara cu %g km/h si are lungimea aripilor de %g metri\n", animale[i].pasare.viteza, animale[i].pasare.lungime);
	  break;
	case 2:
	  printf("Tip animal -> mamifer\n");
	  printf("Mamimferul are %g kg si inaltime de %g metri\n", animale[i].mamifer.greutate, animale[i].mamifer.inaltime);
	  switch(animale[i].mamifer.tip_mancare)
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
	  printf("Pestele are greutatea de %g kg traieste la o adancime de %g metri, la salinitate de %d procente\n,", animale[i].peste.greutate, animale[i].peste.adancime, animale[i].peste.salinitate);
	  break;
	}
      printf("\n");
    }
}


int main(void)
{
  int opt = 0;
  for(; ;)
    {
      printf("\n");
      printf("1 - Adaugare animal \n");
      printf("2 - Stergere animal \n");
      printf("3 - Afisare animale \n");
      printf("4 - Close \n");

      scanf("%d", &opt);

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
  //adaugare();
  //printare();
  return 0;
}
