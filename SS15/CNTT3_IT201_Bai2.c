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

// Hàm khởi tạo hàng đợi rỗng
Queue createQueue(int max_size) {
    Queue q;
    q.array = (int*) malloc(sizeof(int) * max_size);
    q.front = 0;
    q.rear = -1;
    q.max_size = max_size;
    return q;
}

// Hàm kiểm tra hàng đợi đầy
int isFull(Queue q) {
    return q.rear >= q.max_size - 1;
}

// Hàm thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value) {
    if (isFull(*q)) {
        printf(" full\n");
        return;
    }
    q->rear += 1;
    q->array[q->rear] = value;
}

// In trạng thái hàng đợi
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
    Queue q = createQueue(5);  // Tạo hàng đợi với sức chứa 5 phần tử
    printQueue(q);             // Trạng thái ban đầu

    // Thêm 5 phần tử bất kỳ vào hàng đợi
    int values[] = {3, 1, 2, 5, 3};  // Bạn có thể thay đổi các giá trị này
    for (int i = 0; i < 5; i++) {
        enqueue(&q, values[i]);
        printQueue(q);
    }

    // Thử thêm 1 phần tử nữa sẽ báo "Queue is full"
    enqueue(&q, 99);  // Thêm phần tử khi hàng đợi đã đầy
    return 0;
}
