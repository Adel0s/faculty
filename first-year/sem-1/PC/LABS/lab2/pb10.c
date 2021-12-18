#include<stdio.h>
int main()
{
  int x, y, z;
  printf("x = ");
  scanf("%d",&x);

  printf("y = ");
  scanf("%d",&y);

  printf("z = ");
  scanf("%d",&z);
  
  if(z>=x && z<y)
    {
      printf("Z este in interiorul intervalului!");
    }
  else
    {
      printf("Z NU este in interiorul intervalului!");
    }
  return 0;
}
