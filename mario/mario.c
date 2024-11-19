#include <stdio.h>
#include <cs50.h>

int main()
{
    int n;

    n = get_int("what int for i ");

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >=i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int j = 0; j < 2; j++)
        {
            printf("  ");
        }
        for (int j = 0; j<=i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return(0);
}
