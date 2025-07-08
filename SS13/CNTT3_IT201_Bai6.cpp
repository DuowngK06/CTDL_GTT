//
// Created by my pc on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Dinh nghia cau truc ngan xep ky tu
typedef struct {
    char *arr;
    int top;
    int maxSize;
} CharStack;

// Ham khoi tao ngan xep ky tu
CharStack createCharStack(int maxSize) {
    CharStack stack;
    stack.arr = (char *)malloc(maxSize * sizeof(char));
    stack.top = -1;
    stack.maxSize = maxSize;
    return stack;
}

// Ham them ky tu vao ngan xep
void pushChar(CharStack *stack, char c) {
    if (stack->top >= stack->maxSize - 1) return;
    stack->arr[++stack->top] = c;
}

// Ham lay ky tu ra khoi ngan xep
char popChar(CharStack *stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[stack->top--];
}

// Ham giai phong bo nho
void freeCharStack(CharStack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->top = -1;
    stack->maxSize = 0;
}

// Ham kiem tra chuoi doi xung
bool isPalindrome(char *str) {
    int len = strlen(str);
    CharStack stack = createCharStack(len);

    // Day tung ky tu vao ngan xep
    for (int i = 0; i < len; i++) {
        pushChar(&stack, str[i]);
    }

    // So sanh tung ky tu voi phan tu lay ra tu ngan xep
    for (int i = 0; i < len; i++) {
        char fromStack = popChar(&stack);
        if (str[i] != fromStack) {
            freeCharStack(&stack);
            return false;
        }
    }

    freeCharStack(&stack);
    return true;
}

int main() {
    char input[1000];

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    // Loai bo ky tu newline '\n' neu co
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (isPalindrome(input)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
