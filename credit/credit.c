#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number;
    number = get_long("Number: ");
    long copy1 = number;
    long copy2 = number;
    long copy3 = number;
    int add1 = 0;
    int add2 = 0;

    //计算从第二开始隔位乘以2并相加的和
    for (int s = 0; number > 0;)
    {
        number = number / 10;
        s = (number % 10) * 2;
        if (s > 0)
        {
            add1 += s / 10 + s % 10;
        }
        else
        {
            add1 += s;
        }

        number = number / 10;
    }
    // printf("%i",add1);


    //计算从第一位开始隔位相加的和
    for (int n = 0; copy1 > 0;)
    {
        n = copy1 % 10;
        add2 += n;
        copy1 = copy1 / 100;
    }

    int sum = add1 + add2;
    int figure = 0;

    //计算位数
    for (; copy2 > 0; figure++)
    {
        copy2 = copy2 / 10;
    }

    //条件判断银行卡的种类
    if (sum % 10 == 0)
    {
        if (figure == 15 &&
            ((int) (copy3 / pow(10, 13)) == 34 || (int) (copy3 / pow(10, 13)) == 37))
        {
            printf("AMEX\n");
        }
         else if (figure == 16 &&
            (51 <= (int) (copy3 / pow(10, 14)) && (int) (copy3 / pow(10, 14)) <= 55))
        {
            printf("MASTERCARD\n");
        }

        else if ((figure == 13 || figure == 16) && (int) (copy3 / pow(10, figure - 1)) == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
