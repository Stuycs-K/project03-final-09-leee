.PHONY: clean run compile
run: prog
	@./prog
clean:
	rm -f *.o prog

compile prog: main.o node.o library.o
	@gcc -o prog main.o node.o library.o

main.o: main.c node.h library.h
	@gcc -c main.c

node.o: node.c node.h
	@gcc -c node.c

library.o: library.c library.h
	@gcc -c library.c
