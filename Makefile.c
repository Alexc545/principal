CC=gcc
CFLAGS=-Wall -Wextra

all: main

main : main.c Performance.c Recherche.c
	$(CC) $(CFLAGS) -o main main.c Performance.c Recherche.c Performance.h Recherche.h
	
clean:
	rm -f main
