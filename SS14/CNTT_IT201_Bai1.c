//
// Created by my pc on 09/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa Node của danh sách liên kết (đơn)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm khởi tạo Stack (ban dầu sẽ là NULL)
Node* initialStack(){
    return NULL;
}

// Thêm phần tử vào đầu Stack
Node* push (int value, Node* top){
    // Cần sử dụng cấp phát bộ nhớ
    Node* newNode = (Node*) malloc(sizeof (Node));

    // Kiểm tra xem bộ nhớ còn đủ để cấp phát không?
    if (newNode == NULL){
        printf("Khong du bo nho de cap phat!");
        exit(1);
    }

    newNode->data = value;
    newNode->next = top;

    // newNode trở thành top mới
    return newNode;
}

// Kiểm tra xe Stack có bị rỗng không
int isEmpty(Node* top){
    return top == NULL;
}

// In ra toàn bộ Stack
void printStack(Node* top){
    printf("Cac phan tu co trong Stack hien tai la: \n");

    if (isEmpty(top)){
        printf("Ngan sep bi rong!");
        return;
    }

    // Duyệt danh sách
    Node* temp = top;

    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp-> next;
    }

    printf("NULL");
}

// Hàm giải phóng bộ nhớ
void freeStack(Node* top){
    Node* temp;

    while (top != NULL){
        temp = top;
        top = top->next;
        free(temp); // Giải phóng từng Node
    }
}

int main(){
    Node* stack = initialStack();

    stack = push(10, stack);
    stack = push(20, stack);
    stack = push(30, stack);
    stack = push(40, stack);

    // Gọi hàm in ra các phần tử
    printStack(stack);

    freeStack(stack);

    return 0;
}
