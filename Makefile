all: cTestLib.so 

cTestLib.so: cTestLib.c
	gcc -shared -o lib_test.so -fPIC cTestLib.c