#include <cs50.h>
#include <stdio.h>

void get_row(int space, int bricks);

int main(void)
{
    int N;
    do
    {
        N = get_int("Height: ");
    }
    while (N < 1);

    for (int i = 0; i < N; i++)
    {
        get_row(N - i - 1, i);
    }
}

void get_row(int space, int bricks)
{
        for (int j = space; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= bricks; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int m = 0; m <= bricks; m++)
        {
            printf("#");
        }
        printf("\n");
}
