#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Ham tao Node moi tu du lieu nhap vao tu ban phim
struct Node* createNodeFromInput() {
    int value;
    printf("Nhap so nguyen lam du lieu cho Node: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham tao Node moi tu gia tri co san
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham them Node vao cay theo cap
void insertNode(struct Node* root, int value) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// Ham duyet theo cap (Level Order) - in cay
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

// Ham dem so nut la (nut khong co con)
int countLeaf(struct Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}


int main() {
    // Tao nut goc tu nhap tu ban phim
    struct Node* root = createNodeFromInput();

    // Them cac phan tu vao cay
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);


    printf("\nCay duyet theo cap: ");
    levelOrder(root);

    // Dem so nut la
    int leafCount = countLeaf(root);
    printf("\nSo nut la trong cay: %d\n", leafCount);

    return 0;
