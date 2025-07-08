//
// Created by my pc on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc ngan xep
typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

// Ham khoi tao ngan xep
Stack createStack(int maxSize) {
    Stack stack;
    stack.arr = (int *)malloc(maxSize * sizeof(int));
    stack.top = -1;
    stack.maxSize = maxSize;
    return stack;
}

// Ham them phan tu vao ngan xep
void push(Stack *stack, int value) {
    if (stack->top >= stack->maxSize - 1) {
        printf("Ngan xep day. Khong the them %d\n", value);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

// Ham xem toan bo phan tu trong ngan xep theo thu tu LIFO
void viewStack(Stack stack) {
    if (stack.top == -1) {
        printf("Ngan xep dang rong.\n");
        return;
    }
    printf("Cac phan tu trong ngan xep (LIFO):\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.arr[i]);
    }
}

// Ham hien thi thong tin ngan xep
void printStack(Stack stack) {
    printf("stack = {\n");
    printf("    elements: [");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d", stack.arr[i]);
        if (i < stack.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", stack.top);
    printf("    cap: %d\n", stack.maxSize);
    printf("}\n");
}

// Ham giai phong bo nho
void freeStack(Stack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->top = -1;
    stack->maxSize = 0;
}

int main() {
    Stack myStack = createStack(5);

    // Them 5 phan tu
    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        push(&myStack, values[i]);
    }

    printStack(myStack);
    printf("\n");
    viewStack(myStack);

    freeStack(&myStack);
    return 0;
}
