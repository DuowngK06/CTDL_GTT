#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cau truc hang doi
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

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        // Hang doi rong
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("Hang doi: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (q->front != NULL)
        printf("Front: %d\n", q->front->data);
    else
        printf("Front: NULL\n");

    if (q->rear != NULL)
        printf("Rear: %d\n", q->rear->data);
    else
        printf("Rear: NULL\n");
}


int main() {
    // Khoi tao hang doi
    Queue* q = createQueue();


    enqueue(q, 3);
    printf("Sau khi them 3 vao hang doi rong:\n");
    printQueue(q);


    Queue* q2 = createQueue();
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 5);

    printf("\nTruoc khi them 3:\n");
    printQueue(q2);


    enqueue(q2, 3);
    printf("Sau khi them 3:\n");
    printQueue(q2);

    return 0;
}

