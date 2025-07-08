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
    stack->arr[++stack->top] = value;
}

// Ham lay phan tu ra khoi ngan xep
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Ham giai phong bo nho
void freeStack(Stack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->top = -1;
    stack->maxSize = 0;
}

// Ham in mang
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Ham dao nguoc mang bang ngan xep
void reverseArray(int arr[], int size) {
    Stack stack = createStack(size);

    // Day cac phan tu vao ngan xep
    for (int i = 0; i < size; i++) {
        push(&stack, arr[i]);
    }

    // Lay ra theo thu tu nguoc va gan lai vao mang
    for (int i = 0; i < size; i++) {
        arr[i] = pop(&stack);
    }

    freeStack(&stack);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf(">> ");
        scanf("%d", &arr[i]);
    }

    printf("\nMang ban dau: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
