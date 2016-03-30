#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
pthread_t tid[2];
void *prime(void*);

int main() 
{
  int i,err;

  long int number[10] = {5011*5009, 1293961, 1293967, 5021*4241, 4723*5009, 
                         5011*5021, 1299173, 1160807, 4241*4723, 1161829};

  for (i = 0; i < 10; i++) {
    err = pthread_create(&tid[i],NULL, prime, &number[i]);
    if (err == 0){
      printf("thread %d created, id=%lu\n",i,tid[i]);
    }
    else
      printf("thread %d creation failed\n",i);
  } 

  for (i = 0; i < 10; i++) 
      pthread_join(tid[i],NULL);

  return(0);
}


void *prime(void *n) {
  int i;
  long int num = *((long int *)n);
  int max = (int) sqrt(num);
  for (i = 2; i <= max; i++) {
    /* usleep(1000); */
    if (num % i == 0) {
      printf("%ld is not prime\n", num);
      return;
    }
  }
  printf("%ld is prime\n", num);
}


