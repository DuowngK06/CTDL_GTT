#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

// Cấu trúc cuộc gọi
typedef struct {
    char phone[20];
    char time[30];
} Call;

// Stack
typedef struct {
    Call data[MAX];
    int top;
} Stack;

// Queue
typedef struct {
    Call data[MAX];
    int front, rear;
} Queue;
// ================= STACK =================
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Call c) {
    if (!isStackFull(s))
        s->data[++s->top] = c;
}

Call pop(Stack *s) {
    if (!isStackEmpty(s))
        return s->data[s->top--];
    Call empty = {"", ""};
    return empty;
}

Call peek(Stack *s) {
    if (!isStackEmpty(s))
        return s->data[s->top];
    Call empty = {"", ""};
    return empty;
}

// ================= QUEUE =================
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, Call c) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q))
            q->front = q->rear = 0;
        else
            q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = c;
    }
}
void getCurrentTime(char *buffer) {
    time_t t;
    time(&t);
    strcpy(buffer, ctime(&t));
    buffer[strlen(buffer)-1] = '\0'; // bỏ ký tự \n
}
void callNewNumber(Stack *back, Stack *forward, Queue *history) {
    Call c;
    printf("Nhap so dien thoai: ");
    scanf("%s", c.phone);
    getCurrentTime(c.time);

    push(back, c);
    initStack(forward); // reset forward stack
    enqueue(history, c);

    printf("Goi %s luc %s\n", c.phone, c.time);
}

void backCall(Stack *back, Stack *forward) {
    if (back->top >= 1) {
        Call last = pop(back);
        push(forward, last);
        Call current = peek(back);
        printf("Da quay lai so: %s\n", current.phone);
    } else {
        printf("Khong co cuoc goi nao truoc do.\n");
    }
}

void redial(Stack *back, Stack *forward) {
    if (!isStackEmpty(forward)) {
        Call c = pop(forward);
        push(back, c);
        printf("Goi lai so: %s\n", c.phone);
    } else {
        printf("Khong co so nao de goi lai.\n");
    }
}

void showHistory(Queue *history) {
    if (isQueueEmpty(history)) {
        printf("Khong co lich su cuoc goi.\n");
        return;
    }

    printf("Lich su cuoc goi:\n");
    int i = history->front;
    do {
        printf("- %s luc %s\n", history->data[i].phone, history->data[i].time);
        if (i == history->rear) break;
        i = (i + 1) % MAX;
    } while (1);
}
int main() {
    Stack callBackStack, callForwardStack;
    Queue callHistoryQueue;
    initStack(&callBackStack);
    initStack(&callForwardStack);
    initQueue(&callHistoryQueue);

    char choice[10];

    while (1) {
        printf("\n=== MENU ===\n");
        printf("CALL / BACK / REDIAL / HISTORY / EXIT\n");
        printf("Nhap lua chon: ");
        scanf("%s", choice);

        if (strcmp(choice, "CALL") == 0) {
            callNewNumber(&callBackStack, &callForwardStack, &callHistoryQueue);
        } else if (strcmp(choice, "BACK") == 0) {
            backCall(&callBackStack, &callForwardStack);
        } else if (strcmp(choice, "REDIAL") == 0) {
            redial(&callBackStack, &callForwardStack);
        } else if (strcmp(choice, "HISTORY") == 0) {
            showHistory(&callHistoryQueue);
        } else if (strcmp(choice, "EXIT") == 0) {
            break;
        } else {
            printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
