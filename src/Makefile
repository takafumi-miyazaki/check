

all:

createThread.exe: createThreads.c
	gcc -o createThreads.exe createThreads.c -lpthread
createThreadDebug.exe: createThreads.c
	gcc -o createThreadsDebug.exe createThreads.c -lpthread -g -fstack-usage -Wstack-usage=1028000
resource.exe: resource.c
	gcc -o resource.exe resource.c
resourceDebug.exe: resource.c
	gcc -o resourceDebug.exe resource.c -g -fstack-usage
manpthreadcreate.exe: manpthreadcreate.c
	gcc -o manpthreadcreate.exe manpthreadcreate.c -lpthread
manpthreadcreateDebug.exe: manpthreadcreate.c
	gcc -o manpthreadcreateDebug.exe manpthreadcreate.c -lpthread -g -fstack-usage
clean:
	rm -f *~
	rm -f *.exe
	rm -f *.su
	rm -f massif*
