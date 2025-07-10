//
// Created by my pc on 10/07/2025.
//
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
int isFull(Queue q) {
    return q.rear >= q.max_size - 1;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue q) {
    return q.rear < q.front;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value) {
    if (isFull(*q)) {
        printf("full\n\n");
        return;
    }
    q->rear += 1;
    q->array[q->rear] = value;
}

// Hiển thị toàn bộ phần tử trong hàng đợi
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

// In thông tin chi tiết hàng đợi
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

// Hàm chính minh hoạ hoạt động
int main() {
    Queue q = createQueue(5);  // Tạo hàng đợi có sức chứa 5 phần tử

    printQueue(q);             // In trạng thái ban đầu
    displayQueue(q);           // Dự kiến: "Queue is empty"

    // Thêm các phần tử
    int values[] = {1, 2, 5};
    for (int i = 0; i < 3; i++) {
        enqueue(&q, values[i]);
        printQueue(q);
        displayQueue(q);
    }

    // Thêm thêm 2 phần tử nữa
    enqueue(&q, 3);
    enqueue(&q, 9);
    printQueue(q);
    displayQueue(q);

    // Hàng đợi đầy rồi, thử thêm 1 phần tử nữa
    enqueue(&q, 99);  // Dự kiến: "Queue is full"
    return 0;
}
