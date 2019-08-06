#include <stdio.h>

int main() {
    float fahr, celsius;
    int step, min, max;

    min = 0;
    step = 20;
    max = 300;

    fahr = min;

    printf("  Fahrenheit  |  Celsius  \n");
    printf("--------------------------\n");

    while (fahr <= max) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);

        printf("  %3.0f         ", fahr);
        printf("  %6.1f \n", celsius);

        fahr += step;
    }
}
