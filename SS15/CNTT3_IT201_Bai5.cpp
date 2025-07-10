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

// Khởi tạo hàng đợi
Queue createQueue(int max_size) {
    Queue q;
    q.array = (int*) malloc(sizeof(int) * max_size);
    q.front = 0;
    q.rear = -1;
    q.max_size = max_size;
    return q;
}

// Kiểm tra hàng đợi đầy
bool isFull(Queue q) {
    return q.rear >= q.max_size - 1;
}

// Kiểm tra hàng đợi rỗng
bool isEmpty(Queue q) {
    return q.rear < q.front;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value) {
    if (isFull(*q)) {
        printf("Queue is full\n\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

// Hiển thị toàn bộ phần tử FIFO
void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
    printf("\n");
}

// In thông tin chi tiết của hàng đợi
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

// Hàm chính minh họa
int main() {
    Queue q = createQueue(5);  // Tạo hàng đợi có sức chứa tối đa 5 phần tử

    printQueue(q);             // In trạng thái ban đầu
    displayQueue(q);           // Hiển thị (dự kiến: "Queue is empty")

    // Nhập và thêm 5 phần tử
    int values[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &values[i]);
        enqueue(&q, values[i]);
        printQueue(q);
        displayQueue(q);
    }

    // Thử thêm phần tử khi đầy
    enqueue(&q, 99);

    return 0;
}
