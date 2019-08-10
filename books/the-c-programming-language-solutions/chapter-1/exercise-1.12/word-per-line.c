#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main()
{
    int c, state;

    state = OUT_WORD;

    printf("Please, type some text:\n");
    printf("The text you enter will be printed one word per line.\n");
    printf("-----------------------------------------------------\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN_WORD) {
                state = OUT_WORD;
                putchar('\n');
            }
            putchar('\0');
        } else {
            if (state == OUT_WORD) {
                state = IN_WORD;
            }
            putchar(c);
        }
    }
}

