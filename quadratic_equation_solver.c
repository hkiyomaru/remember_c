/**
 * @filename quadratic_equation_solver.c
 * @brief Solve a quadratic equation defined by command-line arguments.
 * @author Hirokazu Kiyomaru
 * @date October 3, 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int solve_quadratic_equation(double *xs, double *coefs)
{
    double squared_d = (coefs[1] * coefs[1]) - (4 * coefs[0] * coefs[2]);
    if (squared_d < 0) {
        return 1;
    }

    double d = sqrt(squared_d);

    xs[0] = (-coefs[1] + d) / (2 * coefs[0]);
    xs[1] = (-coefs[1] - d) / (2 * coefs[0]);

    return 0;
}


int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Invalid number of arguemnts supplied.\n");
        return EXIT_FAILURE;
    }

    double xs[2];
    double coefs[3];

    sscanf(argv[1], "%lf", &coefs[0]);
    sscanf(argv[2], "%lf", &coefs[1]);
    sscanf(argv[3], "%lf", &coefs[2]);

    printf("(%lf)x^2 + (%lf)x + (%lf) = 0\n", coefs[0], coefs[1], coefs[2]);

    if (solve_quadratic_equation(xs, coefs) == 0) {
        printf("x1: %lf\n", xs[0]);
        printf("x2: %lf\n", xs[1]);
    } else {
        printf("The equation does not have real solutions.\n");
    }

    return EXIT_SUCCESS;
}
