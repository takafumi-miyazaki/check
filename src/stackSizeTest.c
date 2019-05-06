#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE 10000000

void *threadFuncStaticArray (void *arg)
{
  const int NumOfArray = SIZE;
  int numStatic[NumOfArray];
  for (int i = 0; i < NumOfArray; i++) {
    numStatic[i] = i;
  }
}

int main (int argc, char * argv)
{
  int NumOfThreads = 1;
  pthread_t thread[NumOfThreads];
  pthread_attr_t attr;
  int errCode = 0;
  
  pthread_attr_init(&attr);
  for (int i = 0; i < NumOfThreads; i++) { 
    if (errCode = pthread_attr_setstacksize(&attr, SIZE*sizeof(int)+100000) != 0) {
      printf("Error: Failed to set stack size\n");
      exit(1);
      switch (errCode) {
      case EINVAL: printf("Error: ENIVAL\n");
	break;
      default: printf("Error: OTHER\n");
      }
      exit(1);
    }
  }
  
  for (int i = 0; i < NumOfThreads; i ++) {
    if ((errCode = pthread_create(&threads[i], NULL, threadFuncStaticArray, NULL)) != 0) {
      printf("Error: Failed to create thread # = %d\n", i);
      switch (errCode) {
      case EAGAIN: printf("Error: EAGAIN\n");
	break;
      default: printf("Error: OTHER\n");
      }
      exit(1);
    }
  }
  for (int i = 0; i < NumOfThreads; i ++) {
    if (pthread_join(threads[i], NULL) != 0) {
      printf("Error: Failed to join thread # = %d\n", i);
      exit(1);
    }
  }
  
  return 0;
}
