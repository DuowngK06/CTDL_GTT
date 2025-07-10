//
// Created by my pc on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;     // Mảng số nguyên chứa các phần tử
    int front;      // Chỉ số của phần tử đầu tiên
    int rear;       // Chỉ số của phần tử cuối cùng
    int max_size;   // Số lượng phần tử tối đa
} Queue;

// Hàm khởi tạo hàng đợi
Queue createQueue(int max_size) {
    Queue q;
    q.array = (int*) malloc(sizeof(int) * max_size); // Cấp phát bộ nhớ động
    q.front = 0;
    q.rear = -1;
    q.max_size = max_size;
    return q;
}

// Hàm in thông tin hàng đợi (test khởi tạo)
void printQueueInfo(Queue q) {
    printf("Front: %d\n", q.front);
    printf("Rear: %d\n", q.rear);
    printf("Max size: %d\n", q.max_size);
    printf("Array contents: [ ");
    for (int i = 0; i <= q.rear; i++) {
        printf("%d ", q.array[i]);
    }
    printf("]\n");
}

int main() {
    Queue myQueue = createQueue(5);  // Tạo hàng đợi tối đa 5 phần tử
    printQueueInfo(myQueue);         // Kiểm tra thông tin ban đầu
    return 0;
}
