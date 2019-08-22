#include <stdio.h>

#define MAX_LINE 1000

void reverse(char s[]);
int get_line(char s[], int limit);

int main()
{
    int l;
    char s[MAX_LINE];

    while ((l = get_line(s, MAX_LINE)) > 0) {
        reverse(s);
        printf("%s", s);
    }

    return 0;
}

int get_line(char s[], int linit)
{
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void reverse(char s[])
{
    int i, j, c;

    i = j = 0;

    // Determine the length of s.
    for (; (c = s[j]) != '\n' && c != '\0'; ++j);

    // J is the last index in the string s.
    j -= 1;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        ++i;
        --j;
    }
}

