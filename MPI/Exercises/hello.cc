#include "mpi.h"
#include <iostream>

using namespace std;

int main()
{
  MPI_Init(NULL, NULL);

  cout << "Hello World!" << endl;

  MPI_Finalize();
}
