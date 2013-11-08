all: prog

prog: bst.o compare.o main.o
	gcc -g -Wall -std=c99 -o prog bst.o compare.o main.o -Werror

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c -Werror
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c -Werror

main.o: main.c
	gcc -g -Wall -std=c99 -c main.c -Werror


clean:	
	rm bst.o
	rm compare.o
	rm prog
	rm main.o
