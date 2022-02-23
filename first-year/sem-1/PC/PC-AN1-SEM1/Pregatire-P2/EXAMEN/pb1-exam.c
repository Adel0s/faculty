#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t *binary_string_to_array16(char *string, int *size)
{
  uint16_t decimal, *v16 = NULL;
  int new_size = 0;
  char *p = strtok(string," ");
  while(p)
    {
      decimal = strtol(p, NULL, 2);
      new_size++;
      v16 = (uint16_t *)realloc(v16, new_size*sizeof(uint16_t));
      if(v16 == NULL)
	{
	  printf("Memorie insuficienta!\n");
	  exit(-1);
	}
      v16[new_size-1] = decimal;
      p = strtok(NULL," ");
    }
  *size = new_size;
  return v16;
}
  

int main(void)
{
  char input[] = "0000000001111011 0000000001110011 0000000001010010 0000000000010011";  //123 115 82 19
  
  int size = 0;
  uint16_t *v = NULL;
  v = binary_string_to_array16(input, &size);
  
  for(int i = 0; i<size;i++)
    {
      printf("%d\n", v[i]);
    }
  
  free(v);
}
