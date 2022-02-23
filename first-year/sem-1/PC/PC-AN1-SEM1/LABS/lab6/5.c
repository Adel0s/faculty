/*
Se citesc 2 numere x și y cu x<y. Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8}, care se află în același timp și în intervalul [x,y].
 */

#include<stdio.h>

int main(void)
{
  int x, y, i, minim;
  scanf("%d",&x);
  scanf("%d",&y);

  int v[] = {7, -5, 4, 3, -9, 2, -8};
  minim = v[0];
  
  for(i=1;i<7;i++)
    {
      if(i >= x && i <= y)
	{
	  if(v[i]<minim) minim = v[i];
	}
    }

  printf("%d\n",minim);
  return 0;
}
