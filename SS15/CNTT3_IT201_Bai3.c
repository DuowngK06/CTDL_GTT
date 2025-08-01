//
// Created by my pc on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int max_size;
} Queue;

// Khởi tạo hàng đợi rỗng
Queue createQueue(int max_size) {
    Queue q;
    q.array = (int*) malloc(sizeof(int) * max_size);
    q.front = 0;
    q.rear = -1;
    q.max_size = max_size;
    return q;
}

// Kiểm tra hàng đợi có đầy không
int isFull(Queue q) {
    return q.rear >= q.max_size - 1;
}

// Kiểm tra hàng đợi có rỗng không
int isEmpty(Queue q) {
    return q.rear < q.front;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value) {
    if (isFull(*q)) {
        printf("full\n");
        return;
    }
    q->rear += 1;
    q->array[q->rear] = value;
}

// In thông tin hàng đợi
void printQueue(Queue q) {
    printf("Queue = {\n");
    printf("  array = [");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i < q.rear) printf(", ");
    }
    printf("],\n");
    printf("  front = %d,\n", q.front);
    printf("  rear = %d,\n", q.rear);
    printf("  capacity = %d\n", q.max_size);
    printf("}\n\n");
}

int main() {
    // Tạo hàng đợi với sức chứa 5 phần tử
    Queue q = createQueue(5);
    printQueue(q);
    printf("isEmpty: %s\n\n", isEmpty(q) ? "true" : "false");

    // Thêm các phần tử vào hàng đợi
    int values[] = {3, 1, 2, 5, 3};
    for (int i = 0; i < 5; i++) {
        enqueue(&q, values[i]);
        printQueue(q);
        printf("isEmpty: %s\n\n", isEmpty(q) ? "true" : "false");
    }

    // Thử thêm 1 phần tử khi hàng đợi đã đầy
    enqueue(&q, 99);  // Dự kiến sẽ báo "Queue is full"

    return 0;
}
