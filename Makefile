CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c mundo/mundo.c territorio/territorio.c jogo/jogo.c
OBJ = main.o mundo/mundo.o territorio/territorio.o jogo/jogo.o
DEPS = mundo/mundo.h territorio/territorio.h jogo/jogo.h
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c main.c

mundo/mundo.o: mundo/mundo.c mundo/mundo.h territorio/territorio.h
	$(CC) $(CFLAGS) -c mundo/mundo.c -o mundo/mundo.o

territorio/territorio.o: territorio/territorio.c territorio/territorio.h
	$(CC) $(CFLAGS) -c territorio/territorio.c -o territorio/territorio.o

jogo/jogo.o: jogo/jogo.c jogo/jogo.h mundo/mundo.h territorio/territorio.h
	$(CC) $(CFLAGS) -c jogo/jogo.c -o jogo/jogo.o

clean:
	rm -f $(OBJ) $(TARGET)