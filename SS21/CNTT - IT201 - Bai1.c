#include <stdio.h>

#define SIZE 3


void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}


void addEdge(int graph[SIZE][SIZE], int u, int v) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        graph[u][v] = 1;
        graph[v][u] = 1;  // Đồ thị vô hướng
    } else {
        printf("Lỗi: node không hợp lệ.\n");
    }
}

// Hàm in ra ma trận kề
void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE];

    initGraph(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}
