/*
Se citește de la intrarea standard un număr necunoscut de perechi de 2 numere despărțite prin . - punct (exemplu 34.21 17.88 90.100). Aceste perechi reprezintă coordonatele unor puncte în sistemul cartezian primul reprezentând abscisa (x) si al doilea ordonata (y). Se va proiecta și implementa o structură de date corespunzătoare și se vor stoca toate punctele citite într-un tablou. Nu se cunoaște numărul de perechi de numere astfel ca se va aloca dinamic tabloul și se va folosi minimul de memorie. Programul va afișa la ieșirea standard punctul cel mai apropiat de origine.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int x, y;
}POINT;


int main(void)
{
  int x, y, nPoints = 0;
  POINT *points = NULL;
  
  while(scanf("%d.%d", &x, &y) != EOF)
    {
      nPoints++;
      points = (POINT*)realloc(points, nPoints*sizeof(POINT));
      points[nPoints-1].x = x;
      points[nPoints-1].y = y;
    }

  int minX = points[0].x, minY = points[0].y;
  for(int i=1;i<nPoints;i++)
    {
      printf("(%d, %d)\n", points[i].x, points[i].y);
    }
  printf("Cel mai apropiat punct de origine este: (%d, %d)\n", minX, minY);
  return 0;
}
