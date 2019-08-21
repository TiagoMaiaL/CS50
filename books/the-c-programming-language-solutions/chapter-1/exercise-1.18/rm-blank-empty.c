#include <stdio.h>

#define MAX_LINE 1000

int get_clear_line(char s[], int limit);

int main()
{
    int i, length;
    char line[MAX_LINE];

    length = 0;
    for (i = 0; i < MAX_LINE - 1; i++) {
        line[i] = '\0';
    }

    while ((length = get_clear_line(line, MAX_LINE)) >= 0) {
        printf("%s", line);
    }

    return 0;
}

int get_clear_line(char s[], int limit)
{
    int c, i, empty;

    i = 0;
    empty = 1;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c == ' ' && empty) {
            continue;
        } else if (c != '\t') {
            empty = 0;
            s[i] = c;
            ++i;
        }
    }

    if (c == EOF) 
        return -1;

    if (c == '\n' && !empty) {
        while (s[i - 1] == ' ') {
            --i;
        }

        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

