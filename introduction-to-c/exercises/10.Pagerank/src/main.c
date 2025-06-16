/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice everything you have learned by
 * developing a pagerank application. The source code is decorated with comments
 * and documentations at every step.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function contains the architecture of a pagerank application.
 * @details You have to declare and define the variables and functions used
 * throughout this program. Every milestone is indicated with a documentation
 * block, accompanied with a statement "exit(-1)" which aborts the program.
 * This allowed you to progress step by step: removing the "exit(-1)" once you
 * implemented the corresponding block of code.
 */
int main(int argc, char* argv[])
{
    /**
     * @brief Use two defines, "SIZE" = 5 and "DUMP_FACTOR" = 0.85.
     * @details SIZE is the number of vertices in the graph (a.k.a: the
     * "graph order"). DUMP_FACTOR is the coefficient controlling the extent to
     * which final ranks are influenced by spreading.
     **/
    exit(-1);

    /**
     * @brief Create a 2D array of SIZE x SIZE integers, named adjacency_matrix.
     * @details If adjacency_matrix[a][b] = 1, it means that page 'a' has a
     * link to page 'b'. Otherwise, it is 0 and means there is no link from
     * page 'a' to page 'b'.
     **/
    exit(-1);

    /**
     * @brief Declare and define the function initialise_adjacency_matrix.
     * @details It receives a 2D array and initialises such that the upper
     * triangle is made of 1s, the rest of 0s.
     * 
     * Example with SIZE = 5
     * 1 1 1 1 1
     * 0 1 1 1 1
     * 0 0 1 1 1
     * 0 0 0 1 1
     * 0 0 0 0 1
     **/
    initialise_adjacency_matrix(adjacency_matrix);

    /**
     * @brief Declare and define the function print_2D_array.
     * @details This function receives a 2D array of SIZE x SIZE elements, and
     * prints it as follows:
     * 
     *                 The right-most
     *                 dimension my_arr[...][X]
     *                 +------------------>
     * The leftmost    | [0][0]  [0][1]  
     * dimension       | [1][0]  [1][1]
     * my_arr[X][...]  | [2][0]  [2][1]
     *                 v
     **/
    print_2D_array(adjacency_matrix);

    /**
     * @brief Create two 1D arrays of SIZE doubles, named "ranks" and
     * "prev_ranks".
     * @details The array "ranks" will contain the final rank of each page,
     * whereas "prev_ranks" will hold ranks from previous iterations that are
     * needed in calculations.
     **/
    exit(-1);

    /**
     * @brief Initialise array of ranks to 1 / SIZE.
     * @details By default, 1 / SIZE is seen as a division of integers and will
     * result in 0. To make sure that the terms are treated as doubles, we will
     * cast them as follows: 1.0 / (double)SIZE.
     **/
    exit(-1);

    /**
     * @brief Declare and define a function that prints an array of SIZE
     * elements, and call it to print the values of the rank array.
     **/
    print_ranks(ranks);

    /**
     * @brief Create a loop for <MAX_ITERATION> iterations.
     **/
    exit(-1);

        //////////////////////
        // BEGIN: MAIN LOOP //
        //////////////////////
        /**
         * @brief Copy the values from array <ranks> to array <prev_ranks>.
         **/
        exit(-1);

        /**
         * @brief Reset the values of array <ranks> to 0.
         **/
        exit(-1);

        /**
         * @brief Create a loop of <SIZE> iterations.
         * @details We will assume that your iterator is named "i", it will
         * represent the source webpage.
         **/

            //////////////////////
            // BEGIN: LOOP I    //
            //////////////////////
            /**
             * @brief Create a loop of <SIZE> iterations.
             * @details We will assume that your iterator is named "j", it will
             * represent the target webpage.
             **/
            exit(-1);

                //////////////////////
                // BEGIN: LOOP J    //
                //////////////////////
                /**
                 * @brief If the webpage "i" has no link to webpage "j", skip
                 * this iteration.
                 **/
                exit(-1);

                /**
                 * @brief Declare and define function count_links_from_page.
                 * @details This function counts the number of links that a
                 * given page has with all other webpages. It receives the 
                 * connectivity matrix, and the source webpage considered. It
                 * returns the number of links obtained.
                 */
                int link_count = count_links_from_page(adjacency_matrix, i);

                /**
                 * @brief If the number of links is strictly greater than 0,
                 * add (1 / link_count)th of the source webpage's previous rank
                 * to the current rank of the target webpage.
                 */
                exit(-1);
            
                //////////////////////
                // END: LOOP J      //
                //////////////////////

            //////////////////////
            // END: LOOP I      //
            //////////////////////

        /**
         * @brief Declare and define the function normalise_ranks.
         * @details This function receives a 1D array of SIZE elements, and 
         * updates the value of every element to:
         * new_value = current_value x DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE.         * 
         **/
        normalise_ranks(ranks);

        /**
         * @brief Calculate the sum of all ranks and prints the value obtained.
         **/
        exit(-1);
        
        /**
         * @brief Print all ranks.
         **/
        print_ranks(ranks);

        //////////////////////
        // END: MAIN LOOP   //
        //////////////////////

    return EXIT_SUCCESS;
}