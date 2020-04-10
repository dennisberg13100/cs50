#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Oppen the file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Couldn't read the file.\n");
        return 1;
    }

    //printf("Pointer: %p\n", file);


    int picCount = 0; // Count the number of the pictures
    bool firstFound = false;
    bool eof = false; // Check if the file ended
    int seekCount = 0;
    int imgSeekCount = 0;

    // Save place to alocate the pictures
    int b_size = 512 * sizeof(char);
    BYTE *buffer = malloc(b_size);
    if (buffer == NULL) //checking if we don't run out of memory
    {
        return 1;
    }
    int freadSize;
    char filename[7];
    FILE *img;

    while (fread(buffer, sizeof(char), b_size, file) > 0)
    {
        // Go to the next 512 BYTES from de raw file
        fseek(file, seekCount, SEEK_SET);

        // Check the begin of a jpg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            firstFound = true;
            sprintf(filename, "%03i.jpg", picCount);
            picCount++;
            img = fopen(filename, "w");
            // reset the img file seek count
            imgSeekCount = 0;

        }

        if (firstFound == true)
        {
            // Next 512 BYTES from the picture
            fseek(img, imgSeekCount, SEEK_SET);
            imgSeekCount = imgSeekCount + b_size;
            fwrite(buffer, sizeof(char), b_size, img);
        }

        seekCount = seekCount + b_size;

    }


    fclose(file);
    fclose(img);
    free(buffer);

    return 0;
}