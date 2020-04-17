CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=kmp

all: $(EXEC)

kmp: kmp.o main.o
	$(CC) -o kmp kmp.o main.o $(LDFLAGS)

kmp.o: fonctions.cc
	$(CC) -o kmp.o -c fonctions.cc $(CFLAGS)

main.o: main.cc fonctions.h
	$(CC) -o main.o -c main.cc $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
