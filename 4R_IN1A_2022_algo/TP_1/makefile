all: test

test: tp1.o test.o
	gcc -o test tp1.o test.o

test.o: test.c tp1.h
	gcc -o test.o -c test.c -Wall -ansi -pedantic

tp1.o: tp1.c
	gcc -o tp1.o -c tp1.c -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrpropre: clean
	rm -rf hello

