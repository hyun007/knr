#include <stdio.h>

/* print Celcius-Fahrenheit table
 * for celcius = -100 to 200 */

int main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = -100;      /* lower limit of temperature table */
    upper = 200;    /* upper limit */
    step = 1;      /* step size */

    celcius = lower;

    //heading (exercise 1-3)
    printf("Celcius | Fahrenheit\n");
    printf("--------|-----------\n");
    while (celcius <= upper) {
        fahr = (9.0/5.0 * celcius) + 32.0;
        printf("   %4.0f |   %6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
