all: cTestLib.o cRK4.o

cTestLib.o: cTestLib.c
	gcc -c -fPIC cTestLib.c -o cTestLib.o
	gcc cTestLib.o -shared -o lib_test.so
	
cRK4.o: rk4.c
	gcc -c -fPIC rk4.c -o rk4.o
	gcc rk4.o -shared -o lib_rk4.so
