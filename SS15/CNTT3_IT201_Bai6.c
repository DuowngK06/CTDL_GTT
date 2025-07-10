#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int max_size;
} Queue;

// Khởi tạo hàng đợi
Queue createQueue(int max_size) {
    Queue q;
    q.array = (int*) malloc(sizeof(int) * max_size);
    q.front = 0;
    q.rear = -1;
    q.max_size = max_size;
    return q;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue *q, int value) {
    q->rear++;
    q->array[q->rear] = value;
}

// Kiểm tra nếu dãy tăng đều 1 đơn vị
bool isIncreasingByOne(Queue q) {
    for (int i = q.front; i < q.rear; i++) {
        if (q.array[i + 1] - q.array[i] != 1) {
            return false;
        }
    }
    return true;
}

// Hàm chính
int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    Queue q = createQueue(n);

    printf("Nhap %d so nguyen duong:\n", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&q, value);
    }

    // Kiểm tra và in kết quả
    if (isIncreasingByOne(q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    free(q.array);
    return 0;
}
