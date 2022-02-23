/*

 Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program ce citeste un astfel de fisier si scrie numerele citite intr-un alt fisier in format text hexazecimal cu 8 cifre hexa cate unul pe rand. Pentru testare se poate folosi fisierul descarcat prin urmatoarea comanda:

http://staff.cs.upt.ro/~valy/pt/integers.bin
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void write_from_intToHex(FILE *in, FILE *out)
{
  long fileSize = 0;
  int nValori = 0, i = 0;
  uint32_t val = 0;
  
  fseek(in, 0, SEEK_END);
  fileSize = ftell(in);
  rewind(in);

  nValori = fileSize / sizeof(uint32_t);

  for(i = 0; i < nValori; i++)
    {
      fread(&val,sizeof(uint32_t),1,in);
      fprintf(out, "%d   -> %08X\n", val, val);
    }
}

int main(void)
{
  FILE *in = NULL;
  in = fopen("integers.bin","rb");

  FILE *out = NULL;
  out = fopen("intTOhex.txt","wb");

  write_from_intToHex(in, out);
  
  fclose(in);
  fclose(out);
  return 0;
}
