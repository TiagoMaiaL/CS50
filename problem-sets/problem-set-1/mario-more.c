// Author: Tiago Maia. 01/09/2019.
// Prints a full pyramid of hashes with a gap in between, 
// similar to the ones in mario bros.

#include <stdio.h>
#include <cs50.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

#define BRICK '#'
#define PADDING ' '
#define GAP "  "

int get_height();
void print_full_pyramid(int height);
void print_bricks(int bricks_count, int left_padding_count);

int main(void)
{
    print_full_pyramid(get_height());
}

// Asks the user for the height of the pyramid.
int get_height()
{
    int height;
    
    while (!((height = get_int("Height: ")) >= MIN_HEIGHT && height <= MAX_HEIGHT));
    
    return height;
}

// Given a height, prints a mario pyramid 'height' hashes tall.
void print_full_pyramid(int height)
{
    for (int curr = MIN_HEIGHT; curr <= height; ++curr)
    {
        int bricks_count, padding_count;

        bricks_count = curr;
        padding_count = height - bricks_count;
        
        print_bricks(bricks_count, padding_count);
        printf("%s", GAP);
        print_bricks(bricks_count, 0);

        putchar('\n');
    }
}

// Given a count of bricks, and the left_padding count, prints a line with the amount of 
// padding chars in the left, followed by the passed number of brick chars.
void print_bricks(int bricks_count, int left_padding_count)
{
    while (left_padding_count > 0)
    {
        putchar(PADDING);
        --left_padding_count;
    }

    while (bricks_count > 0)
    {
        putchar(BRICK);
        --bricks_count;
    }
}

