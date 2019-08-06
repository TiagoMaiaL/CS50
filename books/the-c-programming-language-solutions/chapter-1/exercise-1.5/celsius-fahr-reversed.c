#include <stdio.h>
  
int main()
{
    printf("  Celsius  |  Fahrenheit  \n");
    printf("--------------------------\n");

    int celsius;

    for (celsius = 0; celsius <= 300; celsius += 20) {
        float fahr = celsius * 9.0/5.0 + 32.0;
        printf("%6.0d %13.1f \n", celsius, fahr);
    }
}
