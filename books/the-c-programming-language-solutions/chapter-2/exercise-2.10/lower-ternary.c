#include <stdio.h>

int lower(int c);

int main()
{
    printf("%c%c\n", lower('T'), lower('G'));
    return 0;
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

