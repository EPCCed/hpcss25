/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice arrays.
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
    // Create an array, statically, of 10 integers.

    /* 
     * Initialise all array elements to their index:
     * Value of first element set to 0.
     * Value of second element set to 1.
     * ...
     * Value of tenth element set to 9.
     */

    /* 
     * Calculate the sum of all elements in that array by passing this array to
     * a function that will performan the calculation. Store the result in the
     * variable "total".
     */
    int total = 0;
    printf("Total = %d.\n", total);

    // Allocate an array of integers, dynamically, containing <total> elements.

    // Repeat the sum calculation you did earlier.
    total = 0;
    printf("Total = %d.\n", total);

    // Free the array you just dynamically allocated.

    // Allocate a 2D array of 5 x 3 elements.
    
    /* Write a function that receives an array of 5 x 3 elements, and returns
     * the sum of all elements.
     */

    return EXIT_SUCCESS;
}