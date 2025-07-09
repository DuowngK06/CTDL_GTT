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

// Ham kiem tra ngan xep day
int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

// Ham kiem tra ngan xep rong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Ham push (them phan tu vao ngan xep)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day, khong the them.\n");
        return;
    }
    stack->top++;
    for (int i = stack->top; i > 0; i--) {
        stack->data[i] = stack->data[i - 1];
    }
    stack->data[0] = value;
}

// Ham in ngan xep
void printStack(Stack *stack) {
    printf("stack = {\n   ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->data[i]);
        if (i != stack->top) printf("->");
    }
    printf("->NULL\n}\n");
}

// Ham giai phong bo nho
void freeStack(Stack *stack) {
    free(stack->data);
}

int main() {
    int maxSize;
    printf("Nhap so phan tu toi da cua ngan xep: ");
    scanf("%d", &maxSize);

    Stack myStack = createStack(maxSize);

    int value;
    char tiepTuc;
    do {
        printf("Nhap gia tri muon them vao ngan xep: ");
        scanf("%d", &value);
        push(&myStack, value);
        printStack(&myStack);
        printf("Ban muon tiep tuc? (y/n): ");
        scanf(" %c", &tiepTuc);
    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    freeStack(&myStack);
    return 0;
}
