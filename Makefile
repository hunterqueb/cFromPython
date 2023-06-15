all: cTestLib.o rk4.o functions.o

cTestLib.o: cTestLib.c
	gcc -c -fPIC cTestLib.c -o cTestLib.o
	gcc cTestLib.o -shared -o lib_test.so
	
rk4.o: rk4.c
	gcc -c -fPIC rk4.c -o rk4.o
	gcc rk4.o -shared -o lib_rk4.so

functions.o: functions.c
	gcc -c -fPIC functions.c -o functions.o
	gcc functions.o -shared -o lib_functions.so