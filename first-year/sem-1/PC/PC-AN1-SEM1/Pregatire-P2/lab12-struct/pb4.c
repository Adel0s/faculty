/*
Se citește un n oricât de mare și apoi n puncte în plan, definite prin coordonatele lor (x,y). Să se afișeze toate punctele, grupate în seturi de puncte care sunt pe aceeași linie orizontală (au același y). Memoria folosită va fi minimă.
 */
/// (1,4) (2,3)  (1,3)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x, y;
}POINT;

int main(void)
{
  POINT *points = NULL;
  
  int n = 0, i = 0, j = 0, maxY = 0;
  printf("n = "); scanf("%d",&n);
  printf("\n");

  points = (POINT*)malloc(n*sizeof(POINT));

  for(i=0;i<n;i++)
    {
      printf("x = "); scanf("%d", &points[i].x);
      printf("y = "); scanf("%d", &points[i].y);
      
      if(points[i].y >= maxY) maxY = points[i].y;
      printf("\n");
    }
  printf("maxY = %d\n", maxY);

  int ok;
  for(i=0;i<=maxY;i++)
    {
      ok = 0;
      for(j=0;j<n;j++)
	{
	  if(points[j].y == i)
	    {
	      ok = 1;
	      printf("(%d,%d); ", points[j].x, points[j].y);
	    }
	}
      if(ok) printf("\n");
    }

  free(points);
  return 0;
}
