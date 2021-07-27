all: main.o funcs.o
	gcc -o main $^

clean:
	rm -f *.o main

main.o: main.c
	gcc -pedantic -Wall -Iinclude -c -o main.o main.c

funcs.o: funcs.c
	gcc -pedantic -Wall -Iinclude -c -o funcs.o funcs.c

