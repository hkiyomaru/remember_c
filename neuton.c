#include <stdio.h>
#include <math.h>

#define MAX_ITERATION 100
#define EPSILON 1e-6
#define ELEMENT_NUM(array) sizeof(array) / sizeof(array[0])


double func(double x, double *coefs, int degree)
{
    double y = 0.0;
    double tmp;

    for (int i=0; i<degree; i++) {
        tmp = coefs[degree - i - 1];
        for (int j=0; j<i; j++) {
            tmp *= x;
        }
        y += tmp;
    }

    return y;
}


double func_prime(double x, double *coefs, int degree)
{
    double y_prime = 0.0;
    double tmp;

    for (int i=1; i<degree; i++) {
        tmp = (i + 1) * coefs[degree - i - 1];
        for (int j=0; j<i-1; j++) {
            tmp *= x;
        }
        y_prime += tmp;
    }

    return y_prime;
}


double update(double x, double *coefs, int degree)
{
    return x - func(x, coefs, degree) / func_prime(x, coefs, degree);
}


void parse_args(double *array, int argc, char *argv[])
{
    for (int i=1; i<argc; i++) {
        sscanf(argv[i], "%lf", &array[i-1]);
    }
}

int main(int argc, char *argv[])
{
    double x = 0.0;  // initial value
    double next_x = 0.0;
    double coefs[argc-1];

    parse_args(coefs, argc, argv);

    for (int i=0; i<MAX_ITERATION; i++) {
        next_x = update(x, coefs, ELEMENT_NUM(coefs));
        if (fabs(x - next_x) < EPSILON) {
            x = next_x;
            break;
        } else {
            x = next_x;
        }
    }

    printf("x: %f\n", x);

    return 0;
}
