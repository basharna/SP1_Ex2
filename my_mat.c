#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

#define V 10

int dist[V][V]; 

void initDist(int matrix[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == 0 && i != j) {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = matrix[i][j];
            }
        }
    }
}

void floydWarshall() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int shortestPath(int i, int j) {
    return (dist[i][j] == INT_MAX || dist[i][j] == 0) ? -1 : dist[i][j];
}

void printPathExists(int i, int j) {
    if (dist[i][j] != INT_MAX && dist[i][j] != 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void setMatrix(int mat[][V]){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    initDist(mat);
    floydWarshall();
}