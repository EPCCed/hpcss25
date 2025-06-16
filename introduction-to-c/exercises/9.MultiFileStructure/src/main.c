/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice a multi-file structure.
 * @details This exercise gets you to move a function outside of the file, 
 * write the corresponding declaration in a header file, moving the definition
 * to a source file and update the compilation command accordingly.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

int add_numbers(int a, int b)
{
    return a + b;
}

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{    
    /* Provide the declaration of function add_numbers in a header file, and
     * move the definition of add_numbers outside of the file main.c, to the
     * new source file you will create. Then, update the compilation command
     * accordingly and execute the program.
     */
    int sum = add_numbers(123, 456);
    printf("The sum of 123 and 456 is %d.\n", sum);

    return EXIT_SUCCESS;
}