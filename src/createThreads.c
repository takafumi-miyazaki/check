#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *threadFunc (void *arg)
{
  int a = 0;
  for (int i = 0; i < 100; i++) {
    a += (2 * a + i * 32 ) / 3;
  }
}

int main (int argc, char * argv)
{
  const int NumOfThreads = 252;
  pthread_t threads[NumOfThreads];
  int errCode = 0;
  
  for (int i = 0; i < NumOfThreads; i ++) {
    if ((errCode = pthread_create(&threads[i], NULL, threadFunc, NULL)) != 0) {
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
