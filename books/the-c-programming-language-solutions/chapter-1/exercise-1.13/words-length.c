#include <stdio.h>

#define MAX_LENGTH 100
#define IN_WORD 1
#define OUT_WORD 0

int main()
{
    int c, length, max_length, i, state;
    int lengths[MAX_LENGTH];

    max_length = 0;
    state = OUT_WORD;
    for (i = 0; i < MAX_LENGTH - 1; i++) {
        lengths[i] = 0;
    }

    printf("Plase, type the text to be analyzed.\n");

    while ((c = getchar()) != EOF) {
        // Determine if we have a word or not.
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN_WORD) {
                lengths[length]++;

                if (length > max_length)
                    max_length = length;

                state = OUT_WORD;
                length = 0;
            }
        } else {
            if (state == OUT_WORD) {
                state = IN_WORD;
            }
            ++length;
        }
    }

    printf("Histogram with the lengths:\n");
    printf("---------------------------\n");
    printf("  LENGTH  |  FREQUENCE  \n");

    for (i = 0; i < MAX_LENGTH - 1; i++) {
        int l = lengths[i];

        if (l > 0) {
            printf("  %3d      ", i);
            printf("  %3d    \n", l);
        }
    }
}
