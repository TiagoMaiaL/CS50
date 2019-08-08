#include <stdio.h>

int main()
{
    int c;

    printf("Please type some text to be copied and printed: \n");
    printf("Any typed tabs, backspaces, or backslashes will be properly visible. \n\n");

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar(' ');
            putchar('\\');
            putchar('t');
            putchar(' ');

        } else if (c == '\b') {
            putchar('\\');
            putchar('b');

        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');

        } else {
            putchar(c);
        }
    }
}

