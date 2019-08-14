#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("\nLine length: %d\n", max);
        printf("%s", longest);
    }

    return 0;
}

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

