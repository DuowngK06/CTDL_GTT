#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
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
    if (newNode == NULL) {
        printf("Loi cap phat bo nho.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Duyet tien thu tu: goc -> trai -> phai
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Duyet trung thu tu: trai -> goc -> phai
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Duyet hau thu tu: trai -> phai -> goc
void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Tim kiem gia tri trong cay bang DFS
int searchDFS(Node* root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;
    return searchDFS(root->left, target) || searchDFS(root->right, target);
}

int main() {
    // Tao cay nhi phan co 3 node
    printf("--- Tao nut goc ---\n");
    Node* root = createNode();

    printf("--- Tao nut con trai ---\n");
    root->left = createNode();

    printf("--- Tao nut con phai ---\n");
    root->right = createNode();

    // Duyet cay
    printf("\nDuyet tien thu tu: ");
    preorderTraversal(root);

    printf("\nDuyet trung thu tu: ");
    inorderTraversal(root);

    printf("\nDuyet hau thu tu: ");
    postorderTraversal(root);

    // Tim kiem
    int target;
    printf("\n\nNhap gia tri can tim: ");
    scanf("%d", &target);

    if (searchDFS(root, target)) {
        printf("Tim thay %d trong cay.\n", target);
    } else {
        printf("Khong tim thay %d trong cay.\n", target);
    }

    // Giai phong bo nho
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
