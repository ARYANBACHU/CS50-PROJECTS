#include <stdio.h>
#include <cs50.h>

void hello(void)
{
    printf("hello");
}

int main (void)
{
    char c = get_char("Do you agree ");

    if(c == 'y')
    {
        printf("Agree");
    }
    if(c == 'n')
    {
        printf("disagree");
    }
    printf("\n");
    hello();
}

//void hello(void)

