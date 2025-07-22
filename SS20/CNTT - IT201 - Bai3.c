#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Ham tao Node moi
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham them phan tu vao cay theo cap (Level Order Insert)
void insertNode(struct Node* root, int value) {
    if (root == NULL) return;

    // Dung queue thu cong de duyet level
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        // Neu trai trong thi them o day
        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            queue[rear++] = current->left;
        }

        // Neu phai trong thi them o day
        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// Ham duyet theo cap de kiem tra ket qua
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Ham chinh test
int main() {
    struct Node* root = createNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);

    printf("Cay sau khi them cac phan tu:\n");
    levelOrder(root);

    return 0;
}
