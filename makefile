CC = gcc
CFLAGS = -g -Wall

all: my_graph my_Knapsack

my_Knapsack: my_Knapsack.o
	${CC} ${CFLAGS} my_Knapsack.o -o my_Knapsack

my_graph: my_graph.o my_mat.o
	${CC} ${CFLAGS} my_graph.o my_mat.o -o my_graph

main.o: my_graph.c my_mat.h
	${CC} -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	${CC} -c my_mat.c

my_Knapsack.o: my_Knapsack.c
	${CC} -c my_Knapsack.c

clean:
	rm -f *.o *.a *.so my_graph my_Knapsack