/*
Se citește un număr k. Să se afișeze dacă în vectorul {7, -5, 4, 3, -9, 2, -8} există cel puțin un număr mai mare decat k.
 */

#include<stdio.h>

int main(void)
{
  int k, i, ok = 0;
  scanf("%d",&k);
  int v[] = {7, -5, 4, 3, -9, 2, -8};

  for(i=0;i<7;i++)
    {
      if(v[i]>k) ok++;
    }
  if(ok) printf("Exista cel putin un nr mai mare decat k!\n");
  else printf("NU exista cel putin un nr mai mare decat k!\n");
  return 0;
}
