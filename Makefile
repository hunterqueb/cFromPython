all: cTestLib.so cRK4.so functions.so

cTestLib.so: cTestLib.c
	gcc -c -fPIC cTestLib.c -o cTestLib.o
	gcc cTestLib.o -shared -o lib_test.so
	
cRK4.so: rk4.c
	gcc -c -fPIC rk4.c -o rk4.o
	gcc rk4.o -shared -o lib_rk4.so

functions.so: functions.c
	gcc -c -fPIC functions.c -o functions.o
	gcc functions.o -shared -o lib_functions.so