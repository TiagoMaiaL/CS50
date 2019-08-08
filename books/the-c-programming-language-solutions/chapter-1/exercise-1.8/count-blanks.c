#include <stdio.h>

int main()
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;

    printf("Please, type some text: \n");

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        } else if (c == '\t') {
            ++nt;
        } else if (c == '\n') {
            ++nl;
        }
    }

    printf("Number of whitespaces: %d. \n", nb);
    printf("Number of tabs: %d. \n", nt);
    printf("Number of new lines: %d. \n", nl);
}

