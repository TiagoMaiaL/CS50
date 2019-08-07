#include <stdio.h>

int main()
{
    int c;

    printf("Please, type something and press enter: \n");

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("c is a newline (\\n) char. ");
        } else if (c == '\t') {
            printf("c is a tab (\\t) char. ");
        } else if (c == ' ') {
            printf("c is a whitespace char. ");
        } else {
            printf("c is the (%c) char. ", c);
        }
        
        printf("And the result of the expression c != EOF is: %d. \n", c != EOF);
    }

    printf("Now c is EOF. And the result of the expression c != EOF is: %d. \n", c != EOF);
}

