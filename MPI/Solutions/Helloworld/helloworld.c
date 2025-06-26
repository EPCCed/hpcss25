//
// Prints 'Hello World' from rank 0 and 
// prints what process it is out of the total number of processes
//

#include <stdio.h>
#include <stdlib.h>

#include <mpi.h>

int main(void)
{
  int rank, size, ierr, namelen;
  char nodename[MPI_MAX_PROCESSOR_NAME];

  MPI_Comm comm;
  
  
  comm  = MPI_COMM_WORLD;

  printf("Hello from MPI program *before* call to MPI_Init!\n");

  MPI_Init(NULL,NULL);
  MPI_Comm_rank(comm, &rank);            
  MPI_Comm_size(comm, &size); 

  // Only processor 0 prints 
  if(rank == 0)
    {
      printf("Hello World from rank 0!\n"); 
    }

  // Each process prints out its rank
  printf("I am rank %d out of %d\n", rank, size);

  // Find out the node name

  MPI_Get_processor_name(nodename, &namelen);

  printf("Rank %d is on node <%s>\n", rank, nodename);

  MPI_Finalize();

  return 0;
}
