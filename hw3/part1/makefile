default: prog

linkedList.o: linkedList.c linkedList.h 
	gcc -Wall -Werror -std=c99 -c linkedList.c

prog: linkedList.o
	gcc -Werror -Wall -std=c99 -o prog linkedList.o linkedListMain.c 
		
clean:
	rm linkedList.o

cleanall: clean
	rm prog

