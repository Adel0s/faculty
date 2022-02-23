/*
O structură conține ora (ca si o alta structura potrivita) la care s-a măsurat o anumită temperatură și valoarea acestei temperaturi (real). Se cere n<=10 și apoi n temperaturi. Se cere apoi o oră de început și una de sfârșit. Să se afișeze media temperaturilor care au fost măsurate în acel interval orar, inclusiv în capetele acestuia.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int h,m,s;
}ORA;

typedef struct
{
  ORA ora;
  float temp;
}temperaturi;

int main(void)
{
  temperaturi temps[11];
  int n, i, nTemps = 0;
  float suma = 0, media = 0;
  ORA inceput, sfarsit;
  
  printf("n = "); scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      printf("Inregistrarea %d\n", i+1);
      printf("ora = "); scanf("%d", &temps[i].ora.h);
      printf("minut = "); scanf("%d", &temps[i].ora.m);
      printf("secunde = "); scanf("%d", &temps[i].ora.s);
      printf("temperatura = "); scanf("%f", &temps[i].temp);
      printf("\n");
    }

  printf("Ora de inceput\n");
  printf("ora = "); scanf("%d", &inceput.h);
  printf("minut = "); scanf("%d", &inceput.m);
  printf("secunde = "); scanf("%d", &inceput.s);

  printf("\n");
  
  printf("Ora de sfarsit\n");
  printf("ora = "); scanf("%d", &sfarsit.h);
  printf("minut = "); scanf("%d", &sfarsit.m);
  printf("secunde = "); scanf("%d", &sfarsit.s);

  for(i=0;i<n;i++)
    {
      if(temps[i].ora.h >= inceput.h && temps[i].ora.h <= sfarsit.h)
	{
	  if(temps[i].ora.m >= inceput.m && temps[i].ora.m <= sfarsit.m)
	    {
	      if(temps[i].ora.s >= inceput.s && temps[i].ora.s <= sfarsit.s)
		{
		  nTemps++;
		  suma = suma + temps[i].temp;
		}
	    }
	}
    }
  media = suma/(float)nTemps;
  printf("media = %f\n", media);
}
