#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    FILE *output_file = NULL;

    int file_count = 0;

    char filename[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", file_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create file.\n");
                fclose(input_file);
                return 1;
            }

            file_count++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(input_file);

    return 0;
}
