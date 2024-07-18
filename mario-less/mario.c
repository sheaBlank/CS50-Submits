#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int N;
    do
    {
        N = get_int("Height: ");
    }
    while(N < 1);

    for (int i = 0;i < N;i++)
    {
        for(int j = N - i - 1;j > 0;j--)
        {
            printf(" ");
        }
        for(int k = 0;k <= i;k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

