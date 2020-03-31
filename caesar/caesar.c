#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //is there just one key
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]);  i < n ;  i++) // is it a valid key
    {
        if (isdigit(argv[1][i]))
        {

        }
        else
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string msg = get_string("Type your secret message:");

    printf("plaintext: %s\n ciphertext: ", msg);

    for (int i = 0, n = strlen(msg); i < n ; i++)
    {
        if (islower(msg[i])) // cript lower characters
        {
            int lower = (int)msg[i] - 97;
            int c = (lower + key) % 26;
            c = c + 97;
            char code = (char)c;

            printf("%c", code);
        }
        else if (isupper(msg[i])) // cript upper characters
        {
            int upper = (int)msg[i] - 65;
            int c = (upper + key) % 26;
            c = c + 65;
            char code = (char)c;

            printf("%c", code);
        }
        else // print other character normaly
        {
            printf("%c", msg[i]);
        }
    }
    printf("\n");



}