#include <stdio.h>
#include "integral.h"

double a = 0.;
double b = 0.;
int n = 100000000;

int main()
{
    // printf("Input a: ");
    // scanf("%le", &a);
    // printf("Input b: ");
    // scanf("%le", &b);
    // printf("Input n: ");
    // scanf("%d", &n);

    double total = 0.;
    total = integrate(a, b, n);

    printf("Integral from %lf to %lf = %.18lf\n", a, b, total);

    return 0;
}