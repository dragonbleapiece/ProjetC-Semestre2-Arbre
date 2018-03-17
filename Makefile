CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=
EXEC=arbre
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

arbre: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: arbre.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)