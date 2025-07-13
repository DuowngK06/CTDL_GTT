#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một nút trong hàng đợi
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc hàng đợi gồm front và rear
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
void peekQueue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}
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
int main() {
    Queue q;
    initQueue(&q);

    // TH1: Hàng đợi rỗng
    peekQueue(&q);

    // TH2: Thêm phần tử
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);

    peekQueue(&q);  // Output: 1
    return 0;
}
