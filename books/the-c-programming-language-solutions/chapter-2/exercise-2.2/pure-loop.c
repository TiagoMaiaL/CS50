// Author: Tiago Maia. 04/09/2019.
// Prompts the user for a line with a loop that 
// doesn't use && or || operators.

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char s[], int lim);

int main(void)
{
    char s[MAX_LINE];
    int i;

    for (i = 0; i < MAX_LINE; ++i)
    {
        s[i] = 0;
    }

    get_line(s, MAX_LINE);

    printf("%s", s);

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;

    while (i < lim - 1)
    {
        c = getchar();

        if (c == '\n')
        {
            s[i] = c;
            break;
        }

        if (c == EOF)
        {
            break;
        }

        s[i] = c;
        ++i;
    }

    s[i + 1] = '\0';
    return i;
}
