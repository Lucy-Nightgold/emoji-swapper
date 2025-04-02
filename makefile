CC = gcc
CFLAGS = -std=c18 -Wpedantic -Wall -Wextra -Wconversion -Werror
LDFLAGS = -lm

all:emoji-swapper

emoji-swapper: main.o emoji.o
	$(CC) -o emoji-swapper main.o emoji.o $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

emoji.o: emoji.c emoji.h
	$(CC) -c emoji.c $(CFLAGS)

clean:
	$(RM) -f *.o emoji-swapper