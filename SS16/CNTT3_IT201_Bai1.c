#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}


void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Queue* q = createQueue();
    if (q->front == NULL && q->rear == NULL) {
        printf("Hang doi duoc khoi tao thanh cong.\n");
    } else {
        printf("Khoi tao that bai.\n");
    }


    printQueue(q);

    return 0;
}