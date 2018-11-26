
#include <mpi.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int main (int argc, char ** argv[]) {

  int myid; // rank id
  int numprocs; // the number of the process
  int i; // index of process
  int k; // initial value of prime
  int j; //check if prime exists
  int primemin = 1; 
  int primesum; 
  int primemax = 50000; //constant of largest val to check
  int totalcount;
  //time interval variables
  struct timeval runtime1;
  struct timeval runtime2;
  //MPI function called by each process
  MPI_Init(&argc,&argv);
  //return number of processes 
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  //returns numbers of ranks 0,.., p-1
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);
   
  MPI_Bcast(&primemin, 1, MPI_INT, 0, MPI_COMM_WORLD);
  //start count of time
  gettimeofday(&runtime1, 0);
