/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice loops.
 * @details This program contains a loop to built, using both 'while' and 'for'
 * versions.
 * If you end up in a situation where your loop executes indefinitely, issue
 * CTRL + C.
 * (Note: even for Mac users, press CTRL + C, not CMD + C).
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{
    // Execute the following statements 10 times, using a 'while' loop.
    printf("[While loop] I should be printed 10 times.\n");

    // Execute the following statements 10 times, using a 'for' loop.
    printf("[For loop] I should be printed 10 times.\n");

    // Execute the following statements 10 times, using a 'while' loop.
    printf("[For loop] I should be printed 10 times, I will skip the 6th iteration.\n");

    /*
     * For some reason, you have a loop that repeats indefinitely until it
     * receives some sort of signal. In our case, a variable will be incremeted
     * at every iteration. When this variables reaches value 5, the loop must
     * stop.
     * Right now, the loop integrates "a < 5" as part of its condition. Remove
     * this check from the while condition so that the loop loops forever, then
     * trigger its abortion using the 'break' keyword when variable 'a' has
     * value 5.
     */
    
    int a = 0;
    while(true && a < 5)
    {
        printf("Value of variable 'a' = %d.\n", a);
        a++;
    }

    return EXIT_SUCCESS;
}