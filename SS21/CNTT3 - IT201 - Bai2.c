#include <stdio.h>

#define SIZE 4

// Khởi tạo ma trận đồ thị 4x4 với giá trị 0
void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

// Hàm thêm cạnh giữa hai node u và v
void addEdge(int graph[SIZE][SIZE], int u, int v) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        graph[u][v] = 1;
        graph[v][u] = 1;
    } else {
        printf("Loi: Chi so Node khong hop le.\n");
    }
}

// Hàm hiển thị ma trận kề của đồ thị
void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke cua do thi:\n");
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
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);


    printGraph(graph);

    return 0;
}
