#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int scorep1 = 0;
    int scorep2 = 0;

    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    for(int i = 0; i < strlen(p1); i++)
    {
        char a = p1[i];
        if(isalpha(a))
        {
            a = toupper(a);
            int letter = (int)a - 65;
            if(letter == 16)
            {
                scorep1 += 10;
            }
            else
            {
                scorep1 += scores[letter];
            }
        }
    }

    for(int i = 0; i < strlen(p2); i++)
    {
        char a = p2[i];
        if(isalpha(a))
        {
            a = toupper(a);
            int letter = (int)a - 65;
            if(letter == 16)
            {
                scorep2 += 10;
            }
            else
            {
                scorep2 += scores[letter];
            }
        }
    }

    if(scorep1 > scorep2)
    {
        printf("Player 1 Wins!");
    }
    else if(scorep2 > scorep1)
    {
        printf("Player 2 Wins!");
    }
    else
    {
        printf("Tie!");
    }
}
