program hello

  use mpi_f08

  implicit none

  integer :: ierr

  call MPI_Init()

  write(*,*) 'Hello World!'

  call MPI_Finalize()

end program hello
