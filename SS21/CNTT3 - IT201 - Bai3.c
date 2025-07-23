#include <stdio.h>

#define SIZE 3

// Khởi tạo ma trận kề đồ thị có hướng
void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

// Hàm thêm cạnh có hướng từ node u đến node v
void addEdge(int graph[SIZE][SIZE], int u, int v) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        graph[u][v] = 1;  // Chỉ cập nhật 1 chiều
    } else {
        printf("Lỗi: node không hop le.\n");
    }
}

// Hàm hiển thị ma trận kề để kiểm tra
void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke cua do thi co huong:\n");
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

    printGraph(graph);         /

    return 0;
}
