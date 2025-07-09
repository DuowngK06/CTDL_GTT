#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

// Ham khoi tao ngan xep
Stack createStack(int maxSize) {
    Stack stack;
    stack.data = (int *)malloc(maxSize * sizeof(int));
    stack.top = -1;
    stack.maxSize = maxSize;
    return stack;
}

// Ham kiem tra ngan xep rong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Ham push (them phan tu vao ngan xep)
void push(Stack *stack, int value) {
    if (stack->top == stack->maxSize - 1) {
        printf("Ngan xep day, khong the them.\n");
        return;
    }
    stack->top++;
    for (int i = stack->top; i > 0; i--) {
        stack->data[i] = stack->data[i - 1];
    }
    stack->data[0] = value;
}

// Ham duyet toan bo phan tu trong ngan xep
void traverseStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep trong\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

// Ham giai phong bo nho
void freeStack(Stack *stack) {
    free(stack->data);
}

// Ham main
int main() {
    Stack myStack = createStack(5);

    // Them truoc mot so gia tri co san nhu bai 1
    push(&myStack, 5);
    push(&myStack, 4);
    push(&myStack, 3);
    push(&myStack, 2);
    push(&myStack, 1);

    // In ra toan bo phan tu co trong ngan xep
    printf("Cac phan tu trong ngan xep:\n");
    traverseStack(&myStack);

    // Giai phong bo nho
    freeStack(&myStack);
    return 0;
}
