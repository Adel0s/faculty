/*uint64_t resetbits(uint64_t x, uint8_t p, uint8_t n) --- functia returneaza numarul x cu n biti incepand cu pozitia p resetati la 0 (ceilalti raman neschimbati)*/

#include<stdio.h>
#include<stdint.h>

void showBits(uint16_t a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

uint64_t resetbits(uint64_t x, uint8_t p, uint8_t n){

    uint64_t mask=0;
    for(int i=p; i<p+n; i++){
        mask=mask|(1<<i);
    }
    showBits(mask);
    return x&(~mask);

}

int main(void)
{  
  uint64_t x = 349;
  showBits(x);
  printf("\n");
  
  resetbits(x,2,4);
    
  showBits(x);
  printf("\n");
  
  //printf("%ld", resetbits(x,2,4));  
  printf("\n");
  return 0;
}
