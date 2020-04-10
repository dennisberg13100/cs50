#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Oppen the file
    FILE *file = fopen(argv[1], "r");
    FILE *copy = fopen("copy.txt", "w");

    if (file == NULL){
        printf("Couldn't read the file.\n");
        return 1;
    }

    printf("Pointer: %p\n", file);

    // Count the number of the pictures
    int picCount = 0;

    // Save place to alocate the pictures
    char *buffer = malloc(512 * sizeof(char));

    char ch;
    while((ch = fgetc(file)) != EOF)
    {
        // Display the BYTE in hexadecimal
        printf("0x%02x ", ch);
        // Save each caracter in a new file called copy.text
        fputc(ch, copy);
    }



    printf("\n");

    //code

    fclose(file);
    free(buffer);



}
