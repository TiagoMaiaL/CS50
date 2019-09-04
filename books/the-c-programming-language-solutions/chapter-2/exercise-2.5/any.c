// Author: Tiago Maia. 04/09/2019.
// Implementation of the any(s1, s2) function.

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "Testing";
    char s2[] = "i";

    printf("%d\n", any(s1, s2));

    return 0;
}

// Given a string s1, and a string s2, returns the first index in s1
// that has any char in s2.
int any(char s1[], char s2[])
{
    int i, j, c, found;

    found = -1;

    for (i = 0; (c = s2[i]) != '\0'; ++i)
    {
        for (j = 0; s1[j] != '\0'; ++j)
        {
            if (s1[j] == c)
            {
                return j;
            }
        }
    }

    return found;
}

