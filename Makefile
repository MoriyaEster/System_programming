CC = gcc
FLAG = -Wall -g

all: edges

edges.c:
	$(CC) $(FLAG) -o edges edges.c

.PHONY: all clean


clean: 
	rm -f *.o edges