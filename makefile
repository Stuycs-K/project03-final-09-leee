.PHONY: clean run compile
run: prog
	@./prog
clean:
	rm -f *.o prog

compile prog: main.o node.o library.o playlist.o
	@gcc -o prog main.o node.o library.o playlist.o

main.o: main.c node.h library.h playlist.h
	@gcc -c main.c

playlist.o: playlist.c playlist.h
	@gcc -c playlist.c

node.o: node.c node.h
	@gcc -c node.c

library.o: library.c library.h
	@gcc -c library.c
