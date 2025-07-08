//
// Created by my pc on 08/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
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

// Ham lay phan tu ra khoi ngan xep
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
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

    // Lay tung phan tu ra khoi ngan xep
    while (1) {
        int popped = pop(&myStack);
        if (popped == -1) break;
        printf("\nPhan tu lay ra: %d\n", popped);
        printStack(myStack);
    }

    freeStack(&myStack);
    return 0;
}


