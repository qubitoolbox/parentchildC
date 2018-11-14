CC = c99
bmptool: main.o
	$(CC) -o bmptool main.c
bmplib.o: bmplib.c bmplib.h
	gcc -o bmplib.c bmplib.h
clean:
	rm -f bmptool main.o bmplib.o

