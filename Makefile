all: cTestLib.o rk45.o

cTestLib.o: cTestLib.c
	gcc -c -fPIC cTestLib.c -o cTestLib.o
	gcc cTestLib.o -shared -o lib_test.so

rk45.o: rk45.cpp
	g++ rk45.cpp -o rk45.o