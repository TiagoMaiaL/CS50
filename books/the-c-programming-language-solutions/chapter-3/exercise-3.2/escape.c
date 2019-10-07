// Write a function escape (s, t) that converts characters like
// newline and tab into visible escape sequences like \n and \t 
// as it copies the string t to s.
// Author: Tiago Maia

#include <stdio.h>

#define MAX_LINE 1000
#define IN_SEQUENCE 1
#define OUT_SEQUENCE 0

void escape(char destination[], char origin[]);
void reverse_escaped(char destination[], char origin[]);

int main(void)
{
    char t[MAX_LINE] = "Finally, from so little sleeping and so much reading,\n"
                       "his brain dried up and he went completely out of his mind.\n"
                       "\t - Miguel de Servantes";
    char s[MAX_LINE];

    escape(s, t);
    printf("Escaped: \n");
    printf("%s", s);

    reverse_escaped(t, s);
    printf("\nReversed: \n");
    printf("%s", t);
    
    return 0;
}

// Given an empty string destination, and a string origin, copies origin 
// into destination by replacing newlines and tabs into visible 
// escape sequences.
void escape(char destination[], char origin[])
{
    char c;
    int i, j;

    i = j = 0;

    while ((c = origin[i]) != '\0')
    {
        char cp;

        switch (c)
        {
            case '\t':
                destination[j++] = '\\';
                destination[j] = 't';
                break;

            case '\n':
                destination[j++] = '\\';
                destination[j] = 'n';
                break;

            default:
                destination[j] = c;
        }

        i++;
        j++;
    }
}

// Given an empty string destination, and a string origin, copies origin 
// into destination by replacing escaped sequences into the equivalent chars.
void reverse_escaped(char destination[], char origin[])
{
    int state, i, j, c;

    state = OUT_SEQUENCE;
    i = j = 0;

    while ((c = origin[i]) != '\0')
    {
        if (c == '\\')
        {
            state = IN_SEQUENCE;
            i++;
            continue;
        }

        if (state == IN_SEQUENCE)
        {
            switch (c)
            {
                case 't':
                    destination[j] = '\t';
                case 'n':
                    destination[j] = '\n';
            }

            state = OUT_SEQUENCE;
        }
        else
        {
            destination[j] = c;
        }

        i++;
        j++;
    }

    destination[j] = '\0';
}

