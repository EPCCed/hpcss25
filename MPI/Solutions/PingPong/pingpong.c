//
//  Program in which 2 processes repeatedly pass a message back and forth
//
// The same data is sent from A to B, then returned from B to A.
//

#include <stdlib.h>
#include <stdio.h>

#include <mpi.h>

int main(int argc, char* argv[])
{
  int rank, size, numiter,length;
  int start,stop,i,iter;
  int tag1, tag2,floatsize;
  float *sbuffer; 
  double t1, t2, time, totmess;
  MPI_Comm comm;
  MPI_Status status;

  comm  = MPI_COMM_WORLD;
  tag1 = 1;
  tag2 = 2;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(comm, &rank);            
  MPI_Comm_size(comm, &size); 

  // Abort if run on less than 2 processors.
  if(size < 2)
    {
      if(rank == 0)
        {
          printf("The code must be run on at least 2 processors.\n");
        }
      MPI_Finalize();
      exit(1);
    }
  
  if(argc < 2)
    {
      if(rank == 0)
        {
          printf("Usage: pingpong <array length> <number of iterations>\n");
        }
      MPI_Finalize();
      exit(1);
  }

  if(rank > 1)
    {
      printf( "Rank %d not participating\n",rank);
    }

  if (rank == 0)
    {
      length  = atoi(argv[1]);
      numiter = atoi(argv[2]);
      printf("Array length = %d , number of iterations = %d\n",length,numiter);
    }

  MPI_Bcast(&length, 1,MPI_INT,0,comm);
  MPI_Bcast(&numiter,1,MPI_INT,0,comm);

  // Allocate array
  sbuffer = malloc(length*sizeof(float));
 
  // Initialise
  for(i=0;i<length;i++)
    {
      sbuffer[i] = (float) rank + 10.0;
    }

  // Time the parallel execution.
  MPI_Barrier(comm);
  t1 = MPI_Wtime();

  // Swap back and forth for iter times

  for(iter=1;iter<numiter;iter++)
    {
      if(rank == 0)
        {
          // Timings only make sense when no print statements are includes!

          MPI_Ssend(&sbuffer[0],length,MPI_FLOAT,1,tag1,comm);
          MPI_Recv(&sbuffer[0],length,MPI_FLOAT,1,tag2,comm,&status);
        }

      else if(rank == 1)
        {
          MPI_Recv(&sbuffer[0],length,MPI_FLOAT,0,tag1,comm,&status);
          MPI_Ssend(&sbuffer[0],length,MPI_FLOAT,0,tag2,comm);
        }
    }

  t2 = MPI_Wtime();
  time = t2 - t1;
  
  // Floatsize of an MPI_FLOAT on this machine

  MPI_Type_size(MPI_FLOAT, &floatsize);

  if(rank == 0)
    {
      // Each iteration comprises two messages
      // A MiB is 1024*1024 bytes

      totmess = 2.0*floatsize*length/1024.0*numiter/1024.0;
      printf( "Ping-Pong of twice %d bytes, for %d times \n",floatsize*length,numiter);
      printf( "Total computing time is %f [s]\n", time );
      printf( "Total message size is %f [MiB] \n", totmess );
      printf( "Time per message is %g [s]\n",  0.5*time/numiter);
      printf( "Bandwidth is %f [MiB/s]\n",  totmess/time);

      if (time < 1.0)
        {
          printf( "WARNING: The time too short to be trusted: increase number of iterations and/or the array size so time is at least one second!\n");
        }
    }

  free(sbuffer);

  MPI_Finalize();

  return 0;
}
