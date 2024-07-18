#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int remainder;
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    do
    {
        remainder = get_int("change owed: ");
    }
    while(remainder < 0);

    int cent = 0;
    
    while(remainder > 0)
    {
        if(remainder >= QUARTER)
        {
            cent += remainder/QUARTER;
            remainder = remainder%QUARTER;
        }
        else if(remainder >= DIME)
        {
            cent += remainder/DIME;
            remainder = remainder%DIME;
        }
        else if(remainder >=NICKEL)
        {
            cent += remainder/NICKEL;
            remainder = remainder%NICKEL;
        }
        else
        {
            cent += remainder;
            remainder = 0;
        }
    }
    printf("%i\n",cent);
}

