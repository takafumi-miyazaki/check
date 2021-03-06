#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/*
void *threadFuncDynamicArray (void *arg)
{
  int sizeDynamic = 1000000;
  int numDynamic[sizeDynamic];
  for (int i = 0; i < 100000; i++) {
    numDynamic[i] = i; //dynamicな配列を生成
  }
}
*/

void *threadFuncStaticArray (void *arg)
{
  int numStatic[1000];
  for (int i = 0; i < 1000; i++) {
    numStatic[i] = i;
  }
}

/*
void *threadFuncSmallCalc (void *arg)
{
  int a = 0;
  for (int i = 0; i < 1000000; i++) {
    a += (2 * a + i * 32 ) / 3;
  }
}
*/

int main (int argc, char * argv)
{
  const int NumOfThreads = 100000;
  pthread_t threads[NumOfThreads];
  int errCode = 0;
  
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
