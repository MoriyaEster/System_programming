CC = gcc
FLAG = -Wall -g

all: graph

graph.c:
	$(CC) $(FLAG) -o graph graph.c

.PHONY: all clean


clean: 
	rm -f *.o graph