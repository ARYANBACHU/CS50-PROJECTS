#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int count = 0;
    bool truth = false;
    long card = get_long("Number: ");
    long backup = card;
    int type = 0;
    while(backup != 0)
    {
        backup = backup / 10;
        count++;
    }
    long two = card / (pow(10, count - 2));
    long one = card / (pow(10, count - 1));
    if((count == 13 || count == 16) && one == 4)
    {
        truth = true;
        type = 1;
    }
    else if(count == 15 && (two == 34 || two == 37))
    {
        truth = true;
        type = 2;
    }
    else if(count == 16 && (two == 51 || two == 52 || two == 53|| two == 54 || two == 55))
    {
        truth = true;
        type = 3;
    }
    else
    {
        printf("INVALID\n");
    }

    if(truth == true)
    {
        //backup = card;
        int sum = 0;
        int sum2 = 0;
        for(int i = 1; i <= count; i++)
        {
            if(i%2 == 0)
            {
                int num = ((card%10)*2);
                if(num >= 10)
                {
                    sum = sum + num%10;
                    num = num/10;
                    sum = sum + num;
                }
                else
                {
                    sum = sum + num;
                }
            }
            else
            {
                sum2 = sum2 + (card%10);
            }
            card = card/10;
        }

        if((sum + sum2)%10 == 0)
        {
            if(type == 1)
            {
                printf("VISA\n");
            }
            if(type == 2)
            {
                printf("AMEX\n");
            }
            if(type == 3)
            {
                printf("MASTERCARD\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }


}
