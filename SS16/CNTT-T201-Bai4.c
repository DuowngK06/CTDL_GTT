#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc hàng đợi
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Hàm khởi tạo hàng đợi rỗng
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Hàm thêm phần tử vào cuối hàng đợi
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Hàm lấy phần tử đầu hàng đợi
int getFrontValue(Queue* q) {
    if (q->front == NULL) {
        printf("empty queue\n");
        return -1;
    } else {
        return q->front->data;
    }
}

int main() {
    Queue q;
    initQueue(&q);


    getFrontValue(&q);


    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);

    int value = getFrontValue(&q);
    printf("%d\n", value);

    return 0;
}
