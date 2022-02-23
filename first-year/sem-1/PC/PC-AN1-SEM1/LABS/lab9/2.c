/*
Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie afișat numele cel mai lung și lungimea sa
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  char nume[100], nume_max[100];
  int i,n;
  size_t max_length = 0; ///unsigned dimensiune max a vectorului
  
  printf("Introduceti cate nume se vor citi: ");
  scanf("%d",&n);
  getchar();
  
  for(i=0; i<n; i++)
    {
      scanf("%s",nume);

      if(strlen(nume) > max_length)
	{
	  max_length = strlen(nume);
	  strcpy(nume_max,nume);
	}
    }
  printf("Numele de lungime maxima este %s si are lungimea de %ld\n", nume_max, max_length);

  return 0;
}
