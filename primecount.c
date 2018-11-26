
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
  
    //Loops to find numbers of primes
  for (k = 2; k <= primemax; k = k++)
  {
    for (j = 2; j < k; j++)
    {
      if ((k%j)==0)
      {
        break;
      }
    }
    if (k==j)
    {
      printf("Node %d found prime number %d \n", myid, k);
      fflush(stdout);
      primesum = k;
      totalcount = totalcount + 1;
    }  
  }
  
  MPI_Reduce(&primemax, &primesum, 1, MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);
  MPI_Finalize();
  //returns total running time
  gettimeofday(&runtime2, 0);
  printf ("Elapsed time %fs\n", (runtime2.tv_sec-runtime1.tv_sec)+(runtime2.tv_usec-runtime1.tv_usec)*1e-6);
  fflush(stdout);
  printf("Total count of primes is %d \n", totalcount);
  return 0;
}
