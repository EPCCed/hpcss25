/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice functions.
 * @details This program calls a function to multiply integers. However, this
 * function is not defined yet, you must define it. Similarly for a factorial
 * function that you must define.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{
    int a = 123;
    int b = 456;
    int c;

    c = multiply_ints(a, b);
    printf("The product of %d and %d is %d.\n", a, b, c);

    /*
     * For reference, factorial(n) = 1 x 2 x ... x (n-1) x n
     */
    int d = 5;
    int factorial = calculate_factorial_of(d);
    printf("The factorial of %d is %d.\n", d, factorial);

    return EXIT_SUCCESS;
}