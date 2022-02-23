/*
O structură conține ora (ca si o alta structura potrivita) la care s-a măsurat o anumită temperatură și valoarea acestei temperaturi (real). Se cere n<=10 și apoi n temperaturi. Se cere apoi o oră de început și una de sfârșit. Să se afișeze media temperaturilor care au fost măsurate în acel interval orar, inclusiv în capetele acestuia.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
  int h;
  int m;
}TIME;

typedef struct
{
  TIME o;
  float temp;
}TEMP;

void afisare(TEMP t)
{
  printf("%gC - %d:%d\n", t.temp, t.o.h, t.o.m);
}

int main(void)
{
  int n, i;
  TEMP temps[11];
  printf("n = ");
  scanf("%d",&n);
  //getchar();

  for(i=0;i<n;i++)
    {
      printf("temperatura = ");
      scanf("%f",&temps[i].temp);
      
      printf("ora: ");
      scanf("%d",&temps[i].o.h);

      printf("minutul: ");
      scanf("%d",&temps[i].o.m);
      
    }

  printf("\n");

   for(i=0;i<n;i++)
    {
      afisare(temps[i]);
    }
   printf("\n");

   TIME o1, o2;
   float s = 0;
   int nr = 0;
   printf("ora de inceput:\n");
   printf("ore: "); scanf("%d",&o1.h);
   printf("minute: "); scanf("%d",&o1.m);

   printf("\n");
   
   printf("ora de final:\n");
   printf("ore: "); scanf("%d",&o2.h);
   printf("minute: "); scanf("%d",&o2.m);

   for(i=0;i<n;i++)
    {
      if(temps[i].o.h >= o1.h && temps[i].o.h <= o2.h)
	{
	  if(temps[i].o.m >= o1.m && temps[i].o.m <= o2.m)
	    {
	      s=s+temps[i].temp;
	      nr++;
	    }
	}
    }

   printf("%g\n",s/nr);
  
  
  return 0;
}
