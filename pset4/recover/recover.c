#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Couldn't read the file.\n");
        return 1;
    }

    printf("Pointer: %p\n", file);
    char *buffer = malloc(512));
    fread(buffer, 512, 1, file);



}
