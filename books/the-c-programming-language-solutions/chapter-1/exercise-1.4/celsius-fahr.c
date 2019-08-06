#include <stdio.h>

int main()
{
    float celsius, fahr;
    int step, min, max;

    step = 20;
    min = 0;
    max = 300;

    celsius = min;

    printf("  Celsius  |  Fahrenheit  \n");
    printf("--------------------------\n");

    while (celsius <= max) {
        fahr = celsius * 9.0/5.0 + 32.0;
        
        printf("%6.0f %13.1f \n", celsius, fahr);
        
        celsius += step;
    }
}
