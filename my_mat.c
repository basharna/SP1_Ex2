#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

#define V 10

int dist[V][V]; 

void initDist(int matrix[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = matrix[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int shortestPath(int i, int j) {
    return dist[i][j];
}

void setMatrix(int mat[][V]){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    initDist(mat);
}