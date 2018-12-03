/*
 * I affirm originality of this program
 * Osman D Morales
 * This program creates 10 threads and
 * increments a shared variable 6 times.
 *
 * */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 10
//shared value
int shval = SIZE;
pthread_mutex_t mutex;

struct mystruct
{
  int increment;
};

void* acces(void* arg)
{
  struct mystruct* k = (struct mystruct*)arg;
  pthread_mutex_lock(&mutex);

  int i ;
  int thread_id = (int)pthread_self();
  //increment variable 6 times 
  for (i = 0; i < 6; i++)
    shval = shval+thread_id;

  printf ("\n Thread %d has finished incrementing %d id\n", shval, thread_id);

  pthread_mutex_unlock(&mutex);

  return 0;

}

int main(void)
{
  
  struct mystruct* v = (struct mystruct*)malloc(sizeof(struct mystruct));
  //create thread array
  pthread_t t0[SIZE];
  int i = 0;
  int val;
  int x;
  //perform ten iterations
  while (i<SIZE)
  {
    pthread_create(&(t0[i]), NULL, acces, (void*)v);
    
    i++;
  }

 for (x = 0; x < SIZE; x++)
 {
   pthread_join(t0[x], NULL);

 }
  //free memory 
  free(v);
  printf("\n Value shared is %li \n", shval);
  
  pthread_mutex_destroy(&mutex);
  return 0;
}
