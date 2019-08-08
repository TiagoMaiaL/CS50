#include <stdio.h>

#define IN  1
#define OUT 0
#define EMPTY_CHAR '\0'

int main()
{
    int c, state;

    state = OUT;

    printf("Plase, type some text to be copied and printed: \n");
    printf("Note that any repeating sequence of whitespaces will be replaced by a single one. \n");

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == OUT) {
                state = IN;
            } else {
                c = EMPTY_CHAR;
            }
        } else {
            state = OUT;
        }

        putchar(c);
    }
}

