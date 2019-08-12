#include <stdio.h>

#define FIRST_CHAR ' '
#define LAST_CHAR '~'
#define CHARS_RANGE LAST_CHAR - FIRST_CHAR

int main()
{
    int c, i;
    int counts[CHARS_RANGE];

    for (i = 0; i < CHARS_RANGE; i++) {
        counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= FIRST_CHAR && c <= LAST_CHAR) {
            i = c - FIRST_CHAR;
            counts[i] = counts[i] + 1;
        }
    }

    printf("  CHAR  |  FREQUENCE  \n");

    for (i = 0; i < CHARS_RANGE; i++) {
        c = FIRST_CHAR + i;
        int count = counts[i];

        printf("  %4c  ", c);
        printf("   %d\n", count);
    }
}

