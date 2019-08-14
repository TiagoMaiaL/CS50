#include <stdio.h>

#define MAX_LINE 1000
#define MIN_LINE 80

int get_line(char line[], int limit);

int main()
{
    int len;
    char line[MAX_LINE];

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > MIN_LINE) {
            printf("%s", line);
        }
    }

    return 0;
}

int get_line(char line[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}
