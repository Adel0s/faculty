 #include <stdio.h>

int main()
{
    int n, i=0, j=0;
    printf("lungime latura = ");
    scanf("%d",&n);
    printf("\n");

    for(i=1; i<=n; i++)
    {
        printf("*");
    }

     printf("\n");

    for(i=3; i <= n; i++)
    {
        printf("*");
        for(j=1;j<=n-2;j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    for(i=1; i<=n; i++)
    {
        printf("*");
    }
    printf("\n");

    return 0;
}
