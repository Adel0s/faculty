/*
Se citește un n oricât de mare și apoi n puncte în plan, definite prin coordonatele lor (x,y). Să se afișeze toate punctele, grupate în seturi de puncte care sunt pe aceeași linie orizontală (au același y). Memoria folosită va fi minimă.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x;
  int y;
}POINT;

int main(void)
{
  int n, i, j;
  POINT *points = NULL;
  
  printf("n = ");
  scanf("%d",&n);

  points = (POINT *)malloc(n*sizeof(POINT));

  if(points == NULL)
    {
      printf("Memorie insuficienta!");
      perror(NULL);
      exit(-1);
    }

  for(i=0;i<n;i++)
    {
      printf("points[%d].x = ", i);
      scanf("%d",&points[i].x);
      printf("points[%d].y = ", i);
      scanf("%d",&points[i].y);
    }

  for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
	if(points[i].y == points[j].y)
	  {
	    printf("{ (%d, %d); (%d, %d) }",points[i].x, points[i].y, points[j].x, points[j].y);
	  }
      printf("\n");
    }
  free(points);
  /* for(i=0;i<n;i++)
    {
      printf("points[%d].x = %d\n", i, points[i].x);
      printf("points[%d].y = %d\n", i, points[i].y);
      printf("\n");
      }*/

  return 0;
}
