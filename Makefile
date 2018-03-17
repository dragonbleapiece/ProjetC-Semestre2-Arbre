CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=
EXEC=Lexique
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

Lexique: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: arbre.struct.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
