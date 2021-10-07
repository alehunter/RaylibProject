raylib: raylib.o
	cc raylib.o -o raylib -l raylib
raylib.o: raylib.c 
	cc -c raylib.c 