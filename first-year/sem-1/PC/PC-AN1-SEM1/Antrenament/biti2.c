#include<stdio.h>
#include<stdint.h>

void showBits(uint8_t a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

void functie(uint8_t a, int b,  int p)
{
  uint8_t m1,m2;
  showBits(a);
  printf("\n");
  showBits(b);
  printf("\n");
  
  m1 = a >> p;
  //showBits(m1);
  //printf("\n");

  m2 = b << p;
  //showBits(m2);
  //printf("\n");
  

  uint8_t r = 0;
  r= m1|m2;
  showBits(r);
  printf("\n");
}

int main(void)
{  
  uint8_t a=0b00011000 , b=0b00001000, n=8, p=4;
  //scanf("%d",&n);
  //scanf("%d",&p);
  functie(a,b,p);
  return 0; 
}
