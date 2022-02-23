#include <stdio.h>
#include <stdlib.h>
#define CHUNK 8
#define ARRAY_CHUNK 4

char *getline(FILE *f)
{
    char ch = 0, *line = NULL;
    int size = 0, i = 0;
    while((ch = fgetc(f)) != EOF)
    {
        if(i == size)
        {
            size += CHUNK;
            line = realloc(line, size * sizeof(char));
        }
        if(ch == '\n')
        {
            line[i] = '\0';
            break;
        }
        line[i++] = ch;
    }
    return line;
}

char **getlines(FILE *f)
{
    int size = 0, i = 0;
    char *line = NULL, **lines = NULL;
    while((line = getline(f)) != NULL)
    {
        if(i == size)
        {
            size += ARRAY_CHUNK;
            lines = realloc(lines, size * sizeof(char*));
        }
        lines[i++] = line;
        if(i == size)
        {
            size++;
            lines = realloc(lines, size * sizeof(char*));
        }
        lines[i] = NULL;
    }
    return lines;
}

void print_lines(char **lines)
{
    int i = 0;
    while(lines[i] != NULL)
    {
        printf("%s\n", lines[i++]);
    }
}

void free_lines(char **lines)
{
    int i = 0;
    while(lines[i] != NULL)
    {
        free(lines[i++]);
    }
    free(lines);
}

int main()
{
    FILE *f;
    if((f = fopen("text.txt", "r")) == NULL)
    {
        puts("Fisierul nu a fost deschis cu succes");
        exit(EXIT_FAILURE);
    }

    char **lines = getlines(f);
    print_lines(lines);
    free_lines(lines);
    fclose(f);
    return 0;
}
