

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
stackSizeTest.exe: stackSizeTest.c
	gcc -o stackSizeTest.exe stackSizeTest.c -lpthread
stackSizeTestDebug.exe: stackSizeTest.c
	gcc -o stackSizeTestDebug.exe stackSizeTest.c -lpthread -g -fstack-usage
glibcVersionCheck4.8.exe: glibcVersionCheck.c
	gcc-4.8 -v -o $@ $<
glibcVersionCheck7.exe: glibcVersionCheck.c
	gcc-7 -v -o $@ $<
glibcVersionCheck4.8.s: glibcVersionCheck.c
	gcc-4.8 -v -o $@ $< -S
glibcVersionCheck7.s: glibcVersionCheck.c
	gcc-7 -v -o $@ $< -S
clean:
	rm -f *~
	rm -f *.s
	rm -f *.exe
	rm -f *.su
	rm -f massif*
