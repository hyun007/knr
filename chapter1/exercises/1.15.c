#include <stdio.h>

float celcius(int);

/* exercise 1-15 modify the temperature program to use a function for conversion
 * print Fahrenheit-Celcius table for fahr = 0, 20, ..., 300 */
int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;

    //heading (exercise 1-3)
    printf("Fahr |  Celcius\n");
    printf("-----|---------\n");
    while (fahr <= upper) {
        printf("%4.0f |   %6.1f\n", fahr, celcius(fahr));
        fahr = fahr + step;
    }
}

float celcius(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
