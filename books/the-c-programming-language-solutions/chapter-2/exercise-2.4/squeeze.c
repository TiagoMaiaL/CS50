// Author: Tiago Maia. 04/09/2019

#include <stdio.h>

void squeeze(char s[], char f[]);
void squeeze_char(char s[], char c);

int main(void)
{
    char s[] = "abcefghaizopq";
    char f[] = "abciouz";

    squeeze(s, f);

    printf("Squeezed: %s\n", s);

    return 0;
}

// Given a string s and a string f, removes every 
// char in s that is found in f.
void squeeze(char s[], char f[])
{
    int i;
    char c;

    for (i = 0; (c = f[i]) != '\0'; ++i)
    {
        squeeze_char(s, c);
    }
}

// Given a string s and a char c, removes every occurrence
// of c in s.
void squeeze_char(char s[], char c)
{
    int j, k;

    for (j = k = 0; s[j] != '\0'; ++j)
    {
        if (s[j] != c)
        {
            s[k++] = s[j];
        }
    }

    s[k] = '\0';
}

