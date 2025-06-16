/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice conditional statements.
 * @details This program has a series of statements. Some of these statements
 * are meant to be executed only if a certain condition is met.
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
    printf("[Should print] Variable 'a' is 123!\n");
    printf("[Should not print] Variable 'a' is not 123!\n");

    double b = 5.0;
    printf("[Should not print] Variable 'b' is strictly lesser than 5.0.\n");
    printf("[Should not print] Variable 'b' is strictly greater than 5.0.\n");
    printf("[Should print] Variable 'b' is equal to 5.0.\n");

    double c = 3.0;
    printf("[Should print] Variable 'a' is 123 and variable 'c' is stricly greater than 2.0.\n");
    printf("[Should print] Variable 'a' is 456 or variable 'c' is strictly lesser than 4.0.\n");

    return EXIT_SUCCESS;
}