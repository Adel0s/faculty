#include<stdio.h>
#include<stdint.h>

void showBits(uint32_t a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

void palindrom_biti(uint32_t a)
{
  uint32_t m1 = 0x8000;
  uint32_t m2 = 0x0001;
  showBits(m1);
  printf("\n");
  showBits(m2);
  printf("\n");
  
  //m1 = a >> p;

  //m2 = b << p;
}

int main(void)
{  
  uint8_t a=0b00011000 , b=0b00001000, n=8, p=4;
  //scanf("%d",&n);
  //scanf("%d",&p);
  palindrom_biti(a);
  return 0; 
}
