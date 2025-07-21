#include <stdio.h>
#include <stdlib.h>

// Cau truc Node nhu cac bai truoc
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Ham tao Node moi
Node* createNode() {
    int value;
    printf("Nhap so nguyen cho node: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Cau truc Queue dung cho BFS
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Ham tao hang doi
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Ham them vao queue
void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
    } else {
        q->rear->next = newQueueNode;
        q->rear = newQueueNode;
    }
}

// Ham lay ra tu queue
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;

    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return treeNode;
}

// Kiem tra queue co rong khong
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Ham tim kiem bang BFS
int searchBFS(Node* root, int target) {
    if (root == NULL) return 0;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == target) {
            // Giai phong queue truoc khi return
            free(q);
            return 1;
        }
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }

    free(q);
    return 0;
}
