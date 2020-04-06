#include <stdio.h>

void swap( int *a, int *b );// * is a pointer to

int main(void)
{
    int x = 1;
    int y = 2;

    printf("Int x = %i and int y = %i\n", x, y);
    swap(&x, &y); // & is a poiter from
    printf("Int x = %i and int y = %i\n", x, y);
}

void swap( int *a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
