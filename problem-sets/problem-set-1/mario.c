// Author: Tiago Maia. 01/09/2019.
// Prints a right-aligned pyramid of hashes, 
// similar to the one in mario bros.

#include <stdio.h>
#include <cs50.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

#define BRICK '#'
#define PADDING ' '

int get_height();
void print_pyramid(int height);

int main(void)
{
    print_pyramid(get_height());
}

// Asks the user for the height of the pyramid.
int get_height()
{
    int height;
    
    while (!((height = get_int("Height: ")) >= MIN_HEIGHT && height <= MAX_HEIGHT));
    
    return height;
}

// Given a height, prints a mario pyramid 'height' hashes tall.
void print_pyramid(int height)
{
    for (int curr = MIN_HEIGHT; curr <= height; ++curr)
    {
        int hashes_count, padding_count;

        hashes_count = curr;
        padding_count = height - hashes_count;

        while (padding_count > 0)
        {
            putchar(PADDING);
            --padding_count;
        }

        while (hashes_count > 0)
        {
            putchar(BRICK);
            --hashes_count;
        }

        putchar('\n');
    }
}

