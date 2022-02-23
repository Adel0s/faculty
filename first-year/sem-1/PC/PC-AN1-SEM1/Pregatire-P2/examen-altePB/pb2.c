#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int nrCampuri = 0;

void citire(FILE *f)
{
  size_t fileSize = 0;
  uint8_t tag;
  uint32_t data;
  char text[5];
  
  fseek(f,0,SEEK_END);
  fileSize = ftell(f);
  rewind(f);

  nrCampuri = fileSize/5;

  for(int i=0;i<nrCampuri;i++)
    {
      fread(&tag,1,1,f);
      if(tag == 0x55)
	{
	  fread(&data,4,1,f);
	  printf("%x %d\n",tag,data);
	}
      else
	{
	  fread(text,1,4,f);
	  text[4] = 0;
	  printf("%x %s\n",tag,text);
	}
    }
}

int main(void)
{
  FILE *f;
  f = fopen("frames2.dat", "rb");
  citire(f);
}
