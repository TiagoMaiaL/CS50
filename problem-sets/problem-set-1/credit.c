// Author: Tiago Maia, in 30/08/2019.

#include <stdio.h>
#include <math.h>
#include <cs50.h>

typedef enum
{
    none_card_type = 0,
    american_express = 1,
    master_card = 2,
    visa = 3
} card_type;

long get_card_number();
card_type get_card_type(long card_number);
int get_alternate_sum(long card_number);
int get_other_sum(long card_number);
int is_card_valid(long card_number);

int get_digit(int n, long integer);
int get_digits_count(long integer);
int get_digits_sum(long integer);

#define AMEX_LEN 15
#define MASTER_LEN 16
#define VISA_MIN_LEN 13
#define VISA_MAX_LEN 16

// Given a credit card number, returns if the card is valid or not, 
// and if its valid, return its type.
int main()
{
    long card_number = get_card_number();
    int count = get_digits_count(card_number);
    
    if (is_card_valid(card_number))
    {
        switch (get_card_type(card_number))
        {
            case american_express:
                if (count == AMEX_LEN) 
                {
                    printf("AMEX\n");
                    return 0;
                }
                break;
                
            case master_card:
                if (count == MASTER_LEN)
                {
                    printf("MASTERCARD\n");
                    return 0;
                }
                break;
            case visa:
                if (count >= VISA_MIN_LEN && count <= VISA_MAX_LEN)
                {
                    printf("VISA\n");
                    return 0;
                }
                
                break;
                
            case none_card_type:
                break;
        }
    }
    
    printf("INVALID\n");
    
    return 0;
}

// Asks the user for his credit card number.
long get_card_number()
{
    return get_long("Number: ");
}

// Given a card number, returns its type (e.g american express, visa, etc.).
card_type get_card_type(long card_number)
{
    int count, last, last_but_one;
    
    count = get_digits_count(card_number);
    last = get_digit(count, card_number);
    last_but_one = get_digit(count - 1, card_number);

    if (last == 3 && (last_but_one == 4 || last_but_one == 7))
    {
        return american_express;
    } 
    else if (last == 4)
    {
        return visa;
    }
    else if (last == 5 && (last_but_one >= 1 && last_but_one <= 5))
    {
        return master_card;
    }
    else 
    {
        return none_card_type;
    }
}

// Given a credit card number, returns if its valid or not.
int is_card_valid(long card_number)
{
    int alternate_sum, other_sum, total_sum;

    alternate_sum = get_alternate_sum(card_number);
    other_sum = get_other_sum(card_number);
    total_sum = alternate_sum + other_sum;

    return total_sum % 10 == 0;
}

// Given a credit card number, returns the sum of the alternate digits, multiplied by two,
// in the process of validation.
int get_alternate_sum(long card_number)
{
    int step, i, count, sum;

    step = 2;
    count = get_digits_count(card_number);
    sum = 0;
    
    for (i = 2; i <= count; i += step)
    {
        int digit = get_digit(i, card_number);
        sum += get_digits_sum(digit * 2);
    }

    return sum;
}

// Given a credit card number, returns the sum of the digits not to be multiplied by two,
// in the process of validation.
int get_other_sum(long card_number)
{
    int step, i, count, sum;

    step = 2;
    count = get_digits_count(card_number);
    sum = 0;

    for (i = 1; i <= count; i += step)
    {
        sum += get_digit(i, card_number);
    }

    return sum;
}

// Given an index i and an integer, returns the digit in i,
// counting from end to beginning, starting at index 1.
int get_digit(int i, long integer)
{
    long search_integer = integer;
    long place;
    int exponent;

    for (exponent = 1; exponent < i; ++exponent)
    {
        place = (long) pow(10, exponent);
        search_integer = integer / place;
    }

    return search_integer % 10;
}

// Given an integer, returns its length in digits.
int get_digits_count(long integer)
{
    long place;
    int exponent, count;

    place = 0;
    exponent = 1;
    count = 1;

    while (place <= integer)
    {
        place = (long) pow(10, exponent);
        ++exponent;
        ++count;
    }
    
    if (count > 1)
    {
        count -= 1;   
    }

    return count;
}

// Given an integer, returns the sum of its digits.
int get_digits_sum(long integer)
{
    int count, i, digit, sum;

    count = get_digits_count(integer);
    sum = 0;

    for (i = 1; i <= count; ++i)
    {
        digit = get_digit(i, integer);
        sum += digit;
    }

    return sum;
}

