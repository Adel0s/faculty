#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK 8

double procent(long long nr, long long total)
{
    double proc = nr * 100 / (double)total;
    return proc;
}
void free_all(long long *aparitii, char **cuvinte, long long total)
{
    long long i;
    for(i = 0; i < total; i++)
    {
        free(cuvinte[i]);
    }
    free(cuvinte);
    free(aparitii);
}
void afisare_procente(FILE *in, FILE *out)
{
    char **cuvinte = NULL, cuv[20] = "";
    long long i = 0, size = 0, nrcuv = 0, contor = 0,  *aparitii = NULL;
    while(fscanf(in, "%s", cuv) != EOF)
    {
        contor++;
        for(i = 0; i < nrcuv; i++)
        {
            if(strcmp(cuvinte[i], cuv) == 0)
            {
                aparitii[i]++;
                break;
            }
        }
        if(i == nrcuv)
        {
            if(nrcuv == size)
            {
                size += CHUNK;

                if((cuvinte = (char**)realloc(cuvinte, size * sizeof(char*))) == NULL)
                {
                    printf("Nu exista memorie suficienta\n");
                    exit(-1);
                }

                if((aparitii = (long long *)realloc(aparitii, size * sizeof(long long))) == NULL)
                {
                    printf("Nu exista memorie suficienta\n");
                    exit(-1);
                }
            }
            if((cuvinte[nrcuv] = (char*)malloc((strlen(cuv) + 1) * sizeof(char))) == NULL)
            {
                printf("Nu exista memorie suficienta");
                exit(-1);
            }
            aparitii[nrcuv] = 1;
            strcpy(cuvinte[nrcuv], cuv);
            nrcuv++;
        }
    }

    for(i = 0; i < nrcuv; i++)
    {
        fprintf(out, "%s : %f%%\n", cuvinte[i],  procent(aparitii[i], contor));
    }
    free_all(aparitii, cuvinte, nrcuv);
}
int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Prea putine argumente\n");
        exit(-1);
    }
    FILE *in = NULL, *out = NULL;

    if((in = fopen(argv[1], "r")) == NULL)
    {
        printf("Fisierul nu a putut fi deschis\n");
        exit(-1);
    }
    if((out = fopen(argv[2], "w")) == NULL)
    {
        printf("Fisierul nu a putut fi deschis\n");
        exit(-1);
    }

    afisare_procente(in, out);

    if(fclose(in) != 0)
    {
        printf("Fisierul nu a putut fi inchis cu succes\n");
        exit(-1);
    }
    if(fclose(out) != 0)
    {
        printf("Fisierul nu a putut fi inchis cu succes\n");
        exit(-1);
    }
    return 0;
}
