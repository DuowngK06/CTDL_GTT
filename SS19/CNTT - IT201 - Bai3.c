#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo một Node mới từ dữ liệu nhập
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

// Duyệt cây theo tiền thứ tự (Preorder): gốc → trái → phải
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Duyệt cây theo hậu thứ tự (Postorder): trái → phải → gốc
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    printf("--- Tao nut goc ---\n");
    Node* root = createNode();

    printf("--- Tao nut con trai ---\n");
    root->left = createNode();

    printf("--- Tao nut con phai ---\n");
    root->right = createNode();

    printf("\nDuyet cay theo hau thu tu: ");
    preorderTraversal(root);
    printf("\n");

    // Giải phóng bộ nhớ
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
