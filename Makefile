CC = gcc
CFLAGS = -Wall -Werror -pedantic

all : string

string : main.o string.o
	$(CC) $(CFLAGS) -o string main.o string.o

main.o : main.c string.h bool.h status.h
	$(CC) $(CFLAGS) -c main.c

string.o : string.c string.h bool.h status.h
	$(CC) $(CFLAGS) -c string.c

clean : 
	rm -f *.o
	rm -f string