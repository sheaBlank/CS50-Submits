#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scoreboard(string player);

int main(void)
{
    // 获取玩家答案
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // 获取分数
    int score1 = scoreboard(player1);
    int score2 = scoreboard(player2);

    // 比较大小
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    //printf("%i,%i\n",score1,score2);
}

int scoreboard(string player)
{
    int score = 0;

    // 计算答案位数
    int length = strlen(player);

    // 计分规则
    string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int number[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // loop计算分数
    for (int j = 0, i = 0; j < length; j++)
    {
        i = 0;
        player[j] = toupper(player[j]);
        if (isupper(player[j]))
        {
            for (int match = 1; match != 0 && i <= 26; i++)
            {
                if (letter[i] == player[j])
                {
                    match = 0;
                    score += number[i];
                    break;
                }
                else
                {
                    match = 1;
                    score += 0;
                }
            }
        }
    }
    return score;
}
