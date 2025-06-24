/*  Function to sharpen an image by convolving with a filter function. The
 *  filter is a combination of a Gaussian (to remove noise) and a Laplacian
 *  (to detect the edges). Input and output is via Portable Grey Map (PGM)
 *  files - note that the input file must have a specific header format.
 *
 *  In this version of the program the image processing is parallelised 
 *  using OpenMP threads. The master thread reads in the fuzzy image and
 *  stores it in shared memory. Further threads are launched, the convolution
 *  computation is distributed over all threads (including the master thread),
 *  and the result stored in shared memory. Finally the master thread adds the 
 *  convolution result to the fuzzy image and writes the resulting sharp image
 *  to file.
 *  
 *  David Henty, EPCC, September 2009
 *  Arno Proeme, EPCC, March 2013 (minor modifications)
 *  Dominic Sloan-Murphy, EPCC, June 2014 (improved consistency with other versions)
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "utilities.h"
#include "sharpen.h"

void dosharpen(char *infile, int nx, int ny)
{
  int d = 8;  
  /* Sets the linear range of the sharpen filter as measured from any given pixel:
     only pixels within a (2d+1)*(2d+1) square centered on the pixel are used to 
     compute its new value. */

  double  norm = (2*d-1)*(2*d-1);
  double scale = 2.0;
  
  int nthreads, threadid;
  int xpix, ypix, pixcount;
  
  int i, j, k, l, dtmp;
  double tstart, tstop, time;
  
  int fuzzy[nx][ny];                   /* Will store the fuzzy input image when it is first read in from file                        */
  double fuzzyPadded[nx+2*d][ny+2*d];  /* Will store the fuzzy input image plus additional border padding                            */
  double convolution[nx][ny];          /* Will store the convolution of the filter with the fuzzy image                              */
  double sharp[nx][ny];                /* Will store the sharpened image obtained by adding the  convolution to the fuzzy image      */
  double sharpCropped[nx-2*d][ny-2*d]; /* Will store the sharpened image cropped to remove a border layer distorted by the algorithm */
  
  char *outfile = "sharpened.pgm";
  
  /* Initialise image arrays */
  for (i=0; i < nx; i++)
    {
      for (j=0; j < ny; j++)
        {
          fuzzy[i][j] = 0;
          sharp[i][j] = 0.0;
          convolution[i][j] = 0.0;
        }
    }
  
  printf("Using a filter of size %d x %d\n", 2*d+1, 2*d+1);
  printf("\n");

  printf("Reading image file: %s\n", infile);
  fflush(stdout);
       
  pgmread(infile, fuzzy, nx, ny, &xpix, &ypix);
  printf("... done\n\n");
  fflush(stdout);
  
  if (xpix == 0 || ypix == 0 || nx != xpix || ny != ypix)
    {
      printf("Error reading %s\n", infile);
      fflush(stdout);
      exit(-1);
    }
  
  /* Initialise image array */
  for (i=0; i < nx+2*d; i++)
    {
      for (j=0; j < ny+2*d; j++)
        {
          fuzzyPadded[i][j] = 0.0;
        }
    }
  
  /* Transfer fuzzy image into padded array */
  for (i=0; i < nx; i++)
    { 
      for (j=0; j < ny; j++)
        {
          fuzzyPadded[i+d][j+d] = fuzzy[i][j];
        }
    }
  
  printf("Starting calculation ...\n");

  /* Print out thread location. */
#pragma omp parallel
{
  printlocation();
}  

  tstart = omp_get_wtime();

  /* Start of parallel region where filter is applied to fuzzy image */
#pragma omp parallel private(i, j, k, l, dtmp, pixcount, threadid)
{
  nthreads  = omp_get_num_threads();
  threadid = omp_get_thread_num();
  
  pixcount = 0;
  
  for (i=0; i < nx; i++)
    {
      for (j=0; j < ny; j++)
        {
          dtmp = 2 + ((d-1)*(i+j))/(nx+ny);

          /* Computation of convolution allocated to threads using simple cyclic distribution
             i.e. consecutively numbered threads take turns computing convolution for consecutive pixels */
          if (pixcount%nthreads  == threadid)
            {
              for (k=-dtmp; k <= dtmp; k++)
                {
                  for (l= -dtmp; l <= dtmp; l++)
                    {
                      convolution[i][j] = convolution[i][j] + filter(dtmp,k,l)*fuzzyPadded[i+dtmp+k][j+dtmp+l];
                    }
                }
            }
          pixcount += 1;
        }
    }
}
  /* End of parallel region and convolution computation */
  
  tstop = omp_get_wtime();
  time = tstop - tstart;
  
  printf("... finished\n");
  printf("\n");
  fflush(stdout);
  
  /* Add rescaled convolution to fuzzy image to obtain sharp image */
  for (i=0 ; i < nx; i++)
    {
      for (j=0; j < ny; j++)
        {
          sharp[i][j] = fuzzyPadded[i+d][j+d] - scale/norm * convolution[i][j];
        }
    }
  
  printf("Writing output file: %s\n", outfile);
  printf("\n");
  
  /* Only save the core of the sharpened image to remove edge effects */
  for (i=d ; i < nx-d; i++)
    {
      for (j=d; j < ny-d; j++)
        {
          sharpCropped[i-d][j-d] = sharp[i][j];
        }
    }
  
  pgmwrite(outfile, sharpCropped, nx-2*d, ny-2*d);
  
  printf("... done\n");
  printf("\n");
  printf("Calculation time was %f seconds\n", time);
  fflush(stdout);
}
