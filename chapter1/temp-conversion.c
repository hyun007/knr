#include <stdio.h>

/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;

    //heading (exercise 1-3)
    printf("Fahr |  Celcius\n");
    printf("-----|---------\n");
    while (fahr <= upper) {
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%4.0f |   %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}
