#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isKey(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for(int i = 0; i < 26; i++)
    {
        if(!isalpha(key[i]))
        {
            return false;
        }
        char upper = toupper(key[i]);
        for(int j = 0; j < 26; j++)
        {
            if(upper == alphabet[j])
            {
                alphabet[j] = '@';
                break;
            }
            if(j == 25)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!isKey(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }
        string user = get_string("Plaintext: ");
        printf("ciphertext: ");

        for(int i = 0; i < strlen(user); i++)
        {
            char a = user[i];
            if(isalpha(a))
            {
                if(islower(a))
                {
                    int letter = (int)toupper(a) - 65;
                    printf("%c", tolower(key[letter]));
                }
                if(isupper(a))
                {
                    int letter = (int)a - 65;
                    printf("%c", toupper(key[letter]));
                }
            }
            else
            {
                printf("%c", a);
            }
        }
        printf("\n");
        return 0;
}
