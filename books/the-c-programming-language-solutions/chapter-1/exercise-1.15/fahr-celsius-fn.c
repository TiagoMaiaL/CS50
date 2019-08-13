#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void print_conversion_table();
int get_celsius(int);

int main()
{
    print_conversion_table();
}

void print_conversion_table()
{
    int fahr = LOWER;

    while (fahr <= UPPER) {
        int celsius = get_celsius(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr += STEP;
    }
}

int get_celsius(int fahr)
{
    return 5 * (fahr - 32) / 9;
}

