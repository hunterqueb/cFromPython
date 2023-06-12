all: cTestLib.o

cTestLib.o: cTestLib.c
	gcc -c -fPIC cTestLib.c -o cTestLib.o
	gcc cTestLib.o -shared -o lib_test.so
