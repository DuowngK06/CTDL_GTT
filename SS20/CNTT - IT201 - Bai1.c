#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Ham tao Node moi tu du lieu nhap vao
struct Node* createNode() {
    int value;
    printf("Nhap so nguyen lam du lieu cho Node: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Ham chinh de test
int main() {
    struct Node* node = createNode();

    // In ra thong tin cua Node vua tao
    printf("Node = {\n");
    printf("   data: %d,\n", node->data);
    printf("   left->NULL,\n");
    printf("   right->NULL\n");
    printf("}\n");

    return 0;
}
