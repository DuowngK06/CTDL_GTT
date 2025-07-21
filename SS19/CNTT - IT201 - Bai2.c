#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo một node mới từ dữ liệu người dùng nhập
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

// Hàm duyệt cây theo thứ tự tiền thứ tự (Preorder)
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);          // Duyệt nút gốc
    preorderTraversal(root->left);      // Duyệt cây trái
    preorderTraversal(root->right);     // Duyệt cây phải
}

int main() {
    printf("--- Tao nut goc ---\n");
    Node* root = createNode();

    printf("--- Tao nut con trai ---\n");
    root->left = createNode();

    printf("--- Tao nut con phai ---\n");
    root->right = createNode();

    printf("\nDuyet cay theo thu tu tien thu tu: ");
    preorderTraversal(root);
    printf("\n");

    // Giải phóng bộ nhớ sau khi sử dụng (tùy chọn nếu mở rộng chương trình)
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
