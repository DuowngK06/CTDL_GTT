#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc ngan xep
typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

// Ham khoi tao ngan xep voi so phan tu toi da
Stack createStack(int maxSize) {
    Stack stack;
    stack.arr = (int *)malloc(maxSize * sizeof(int)); // Cap phat bo nho cho mang
    stack.top = -1;                                   // Ngan xep rong ban dau
    stack.maxSize = maxSize;
    return stack;
}

// Ham hien thi thong tin ngan xep
void printStackInfo(Stack stack) {
    printf("Thong tin ngan xep:\n");
    printf("- Suc chua toi da: %d phan tu\n", stack.maxSize);
    printf("- Chi so top hien tai: %d\n", stack.top);
    if (stack.top == -1) {
        printf("- Ngan xep dang rong.\n");
    }
}

// Ham giai phong bo nho cua ngan xep
void freeStack(Stack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    stack->top = -1;
    stack->maxSize = 0;
}

int main() {
    Stack myStack = createStack(5);
    printStackInfo(myStack);
    freeStack(&myStack);
    return 0;
}
