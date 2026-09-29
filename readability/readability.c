#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int words = 1;
    int letters = 0;
    int sentences = 0;

    for(int i = 0; i < strlen(text); i++)
    {
        char a = text[i];
        if(isalpha(a))
        {
            letters++;
        }
        if(a == '!' || a == '?' || a == '.')
        {
            sentences++;
        }
        if(a == ' ')
        {
            words++;
        }
    }

    double l = ((double)letters/words) * 100;
    double s = ((double)sentences/words) * 100;
    double index = (0.0588 * l) - (0.296 * s) - 15.8;
    int ind = (int) (index + 0.5);

    if(ind >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(ind < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", ind);
    }

}
