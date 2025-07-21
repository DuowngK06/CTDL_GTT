#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo Node mới
Node* createNode() {
    int value;
    printf("Nhập số nguyên cho node: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Duyệt tiền thứ tự: Gốc → Trái → Phải
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Duyệt trung thứ tự: Trái → Gốc → Phải
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Duyệt hậu thứ tự: Trái → Phải → Gốc
void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Tạo 3 node: gốc, trái, phải
    printf("--- Tao nut goc ---\n");
    Node* root = createNode();

    printf("--- Tao nut con trai ---\n");
    root->left = createNode();

    printf("--- Tao nut con phai ---\n");
    root->right = createNode();

    // Hiển thị kết quả duyệt
    printf("\nDuyet cay theo tien thu tu: ");
    preorderTraversal(root);

    printf("\nDuyet cay theo trung thu tu: ");
    inorderTraversal(root);

    printf("\nDuyet cay theo hau thu tu: ");
    postorderTraversal(root);
    printf("\n");

    // Giải phóng bộ nhớ
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
