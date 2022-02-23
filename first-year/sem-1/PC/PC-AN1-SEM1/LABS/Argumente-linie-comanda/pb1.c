#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  printf("Numarul de argumente(argc) este = %d\n",argc);
  for(int i=0;i<argc;i++)
    {
      printf("%d - %s\n", i, argv[i]);
    }

  int n = 0;
  if(argc>=2)
    {
      n = atoi(argv[1]);

      if(n>0)
	{
	  printf("Primul argument este %d si este un numar pozitiv\n",n);
	}
    }
  return 0;
}
