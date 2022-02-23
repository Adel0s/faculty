/*
Se citește de la intrarea standard un număr necunoscut de perechi de 2 numere despărțite prin . - punct (exemplu 34.21 17.88 90.100). Aceste perechi reprezintă coordonatele unor puncte în sistemul cartezian primul reprezentând abscisa (x) si al doilea ordonata (y). Se va proiecta și implementa o structură de date corespunzătoare și se vor stoca toate punctele citite într-un tablou. Nu se cunoaște numărul de perechi de numere astfel ca se va aloca dinamic tabloul și se va folosi minimul de memorie. Programul va afișa la ieșirea standard punctul cel mai apropiat de origine.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int x;
  int y;
}POINT;

int main(void)
{
  char string_point[100], x[100], y[100];
  POINT points[100];
  int NrPoints = 0;
  char *p;

  while(fgets(string_point, 100, stdin) != NULL)
    {
      p = strtok(string_point, ".");
      strcpy(x,p);
      p = strtok(NULL, ".");
      strcpy(y,p);
      
      points[NrPoints].x = strtol(x,NULL,10);
      points[NrPoints].y = strtol(y,NULL,10);
      //printf("x = %d : y = %d \n", points[NrPoints].x, points[NrPoints].y);
      NrPoints++;
    }

  for(int i=0;i<NrPoints;i++)
    {
      printf("x = %d : y = %d \n", points[i].x, points[i].y);
    }
  return 0;
}
