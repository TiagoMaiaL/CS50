// Author: Tiago Maia. 03/09/2019.
// Determines the ranges of char, short, int and long variables, both signed and unsigned.

#include <stdio.h>

void print_unsigned_char_range();
void print_signed_char_range();

void print_unsigned_short_range();
void print_signed_short_range();

void print_unsigned_int_range();
void print_signed_int_range();

#define HIGH_STEP 1000000000000
#define MEDIUM_STEP 1000000
#define SMALL_STEP 1000
#define STEP 1

void print_unsigned_long_range();
void print_signed_long_range();

int main(void)
{
    printf("Chars\n");
    printf("--------------------\n");
    print_unsigned_char_range();
    print_signed_char_range();

    printf("\nShort\n");
    printf("--------------------\n");
    print_unsigned_short_range();
    print_signed_short_range();

    printf("\nInteger\n");
    printf("--------------------\n");
    print_unsigned_int_range();
    print_signed_int_range();

    printf("\nLong\n");
    printf("--------------------\n");
    print_unsigned_long_range();
    print_signed_long_range();
}

// Prints the unsigned range of values supported by char variables.
void print_unsigned_char_range()
{
    unsigned char unsigned_char, unsigned_max;

    unsigned_max = 0;
    unsigned_char = 1;

    while (unsigned_char > unsigned_max)
    {
        unsigned_max = unsigned_char;
        ++unsigned_char;
    }

    printf("Unsigned char range: %d to %d\n", 0, unsigned_max);
}

// Prints the signed range of values supported by char variables.
void print_signed_char_range()
{
    signed char signed_char, signed_max, signed_min;

    signed_char = 1;
    signed_max = 0;

    while (signed_char > signed_max)
    {
        signed_max = signed_char;
        ++signed_char;
    }

    signed_char = -1;
    signed_min = 0;

    while (signed_char < signed_min)
    {
        signed_min = signed_char;
        --signed_char;
    }

    printf("Signed char range: %d to %d\n", signed_min, signed_max);
}

// Prints the unsigned range of values supported by short variables.
void print_unsigned_short_range()
{
    unsigned short u_short, max;

    u_short = 1;
    max = 0;

    while (u_short > max)
    {
        max = u_short;
        ++u_short;
    }

    printf("Unsigned short range: %d to %d\n", 0, max);
}

// Prints the signed range of values supported by short variables.
void print_signed_short_range()
{
    signed short s_short, min, max;

    s_short = 1;
    max = 0;

    while (s_short > max)
    {
        max = s_short;
        ++s_short;
    }

    s_short = -1;
    min = 0;

    while (s_short < min)
    {
        min = s_short;
        --s_short;
    }

    printf("Signed short range: %d to %d\n", min, max);
}

// Prints the unsigned range of values supported by integer variables.
void print_unsigned_int_range()
{
    unsigned int u_integer, max, step;

    step = MEDIUM_STEP;
    max = 0;
    u_integer = 1;

    while (u_integer > max || step != STEP)
    {
        if (u_integer < max)
        {
            if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            u_integer = max + 1;
            continue;
        }

        max = u_integer;
        u_integer += step;
    }

    printf("Unsigned int range: %u to %u\n", 0, max);
}

// Prints the signed range of values supported by integer variables.
void print_signed_int_range()
{
    signed int s_integer, min, max, step;

    step = MEDIUM_STEP;
    max = 0;
    s_integer = 1;

    while (s_integer > max || step != STEP)
    {
        if (s_integer < max)
        {
            if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            s_integer = max + 1;
            continue;
        }

        max = s_integer;
        s_integer += step;
    }

    step = MEDIUM_STEP;
    min = 0;
    s_integer = -1;

    while (s_integer < min || step != STEP)
    {
        if (s_integer > min)
        {
            if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            s_integer = min - 1;
            continue;
        }

        min = s_integer;
        s_integer -= step;
    }

    printf("Signed int range: %d to %d\n", min, max);
}

// Prints the unsigned range of values supported by long variables.
void print_unsigned_long_range()
{
    unsigned long u_long, max, step;

    step = HIGH_STEP;
    max = 0;
    u_long = 1;

    while (u_long > max || step != STEP)
    {
        if (u_long < max)
        {
            if (step == HIGH_STEP)
            {
                step = MEDIUM_STEP;
            }
            else if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            u_long = max + 1;
            continue;
        }

        max = u_long;
        u_long += step;
    }

    printf("Unsigned long range: %d to %lu\n", 0, max);
}

// Prints the signed range of values supported by long variables.
void print_signed_long_range()
{
    signed long s_long, max, min, step;

    step = HIGH_STEP;
    max = 0;
    s_long = 1;

    while (s_long > max || step != STEP)
    {
        if (s_long < max)
        {
            if (step == HIGH_STEP)
            {
                step = MEDIUM_STEP;
            }
            else if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            s_long = max + 1;
            continue;
        }

        max = s_long;
        s_long += step;
    }

    step = HIGH_STEP;
    min = 0;
    s_long = -1;

    while (s_long < min || step != STEP)
    {
        if (s_long > min)
        {
            if (step == HIGH_STEP)
            {
                step = MEDIUM_STEP;
            }
            else if (step == MEDIUM_STEP)
            {
                step = SMALL_STEP;
            }
            else if (step == SMALL_STEP)
            {
                step = STEP;
            }

            s_long = min - 1;
            continue;
        }

        min = s_long;
        s_long -= step;
    }

    printf("Signed long range: %ld to %ld\n", min, max);
}

