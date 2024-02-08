CC = gcc
CFLAGS = -g -Wall

all: connections my_KnapSack

my_KnapSack: my_KnapSack.o
	${CC} ${CFLAGS} my_KnapSack.o -o my_KnapSack

connections: my_graph.o my_mat.o
	${CC} ${CFLAGS} my_graph.o my_mat.o -o connections

main.o: my_graph.c my_mat.h
	${CC} -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	${CC} -c my_mat.c

my_KnapSack.o: my_KnapSack.c
	${CC} -c my_KnapSack.c

clean:
	rm -f *.o *.a *.so connections my_KnapSack