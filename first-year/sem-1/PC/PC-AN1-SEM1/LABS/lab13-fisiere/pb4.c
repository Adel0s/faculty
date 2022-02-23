/*

    Se consideră un fișier text ce conține un număr necunoscut de linii de text de o dimensiune necunoscută. Să se scrie un program ce citește un astfel de fișier și stochează datele într-un tablou alocat dinamic de string-uri C alocate dinamic. Se va folosi o amprentă minimă de memorie. Se vor scrie de asemenea și următoarele funcții

    o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)
    o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a liniilor. Hint ! Se poate folosi funcția rand(....);
    o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.

 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char **linii;  // char **linii <=> char *linii[]
int nLinii;
FILE *fin;

void eliberare()
{
  int i;
  for(i=0;i<nLinii;i++)
    {
      free(linii[i]);
    }
  free(linii);
  fclose(fin);
}

void adaugaLinie(const char *linie)
{
  char *linieNoua = (char *)malloc((strlen(linie)+1)*sizeof(char));
  if(linieNoua==NULL)
    {
      printf("Memorie insuficienta!\n");
      eliberare();
      exit(EXIT_FAILURE);
    }

  strcpy(linieNoua,linie);

  char **p = (char **)realloc(linii, (nLinii+1)*sizeof(char *));  // char *p[] <=> char **p
  if(p==NULL)
    {
      printf("Memorie insuficienta!\n");
      free(linieNoua);
      eliberare();
      exit(EXIT_FAILURE);
    }
  linii = p;
  linii[nLinii] = linieNoua;
  nLinii++;
  
}


void write_sort(char **lines, char *filepath)  ///?????? NU MERGE ????
{
  char aux[1000];
  FILE *fout;
  fout = fopen(filepath,"w");
  if(fout == NULL)
    {
      printf("Eroare la deschiderea fisierului!\n");
      fclose(fout);
      exit(EXIT_FAILURE);
    }

  int sorted = 0, i;
  do
    {
      sorted = 0;
      for(i=1;i<nLinii;i++)
	{
	  if(strcmp(lines[i-1],lines[i]) > 0)
	    {
	      strcpy(aux, lines[i-1]);
	      strcpy(lines[i-1],lines[i]);
	      strcpy(lines[i],aux);
	      sorted = 1;
	    }
	}
    }while(sorted);

  for(i=0;i<nLinii;i++)
    {
      //fputs(lines[i],fout);
      printf("%s\n", lines[i]);
    }
  
  fclose(fout);
}
void write_random(char **lines, char *filepath)
{
  int i;
  FILE *fout;
  fout = fopen(filepath,"w");
  if(fout==NULL)
    {
      printf("Eroare la deschiderea fisierului!\n");
      exit(EXIT_FAILURE);
      fclose(fout);
    }

  srand(time(NULL));
  int randomLine;
  for(i=0;i<nLinii;i++)
    {
      randomLine = rand() % (nLinii+1);
      fprintf(fout,"%s\n", lines[randomLine]);
    }
  
  fclose(fout);
}

uint32_t find_word(char **lines, char *word)  /// ??????? NU MERGE ????????
{
  uint32_t nWords = 0;
  int i;
  char lineWords[1000][1000];
  char *p;
  for(i=0;i<nLinii;i++)
    {
      p=strtok(lines[i]," ");
      while(p!=NULL)
	{
	  strcpy(lineWords[i],p);
	  p=strtok(NULL," ");
	}
    }

  for(i=0;i<nLinii;i++)
    {
      if(strcmp(word,lineWords[i])==0 && (strlen(word)==strlen(lineWords[i]))) nWords++;
    }
  return nWords;
}

int main(void)
{
  char linie[1000];
  int i;
  fin = fopen("scrisoare.txt","r");

  if(fin == NULL)
    {
      printf("Fisierul nu s-a putut deschide!\n");
      exit(EXIT_FAILURE);
    }
  
  while(fgets(linie,1000,fin)!=NULL)
    {
      if(strlen(linie) <= 1) continue;
      adaugaLinie(linie);
    }

  for(i=0;i<nLinii;i++)
    {
      printf("# %s\n", linii[i]);
    }
  //write_sort(linii,"out-sorted.txt");

  write_random(linii, "out-random.txt");

  int x = find_word(linii,"Din");
  printf("%d\n",x);
  eliberare();
  
  return 0;
}
