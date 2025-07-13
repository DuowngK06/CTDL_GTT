#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[100];
    int credit;
} Course;

typedef struct Node {
    Course data;
    struct Node* next;
} Node;

typedef struct DNode {
    Course data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// ====== Hàm xử lý ======
Node* addCourse(Node* head, Course c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = head;
    return newNode;
}

void displayCourses(Node* head) {
    printf("\n--- Danh sách khóa học đang học ---\n");
    while (head) {
        printf("ID: %d | Tên: %s | Tín chỉ: %d\n", head->data.id, head->data.title, head->data.credit);
        head = head->next;
    }
}

Node* deleteCourse(Node* head, int id) {
    Node *curr = head, *prev = NULL;
    while (curr && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return head;
    if (!prev) head = curr->next;
    else prev->next = curr->next;
    free(curr);
    return head;
}

void updateCourse(Node* head, int id, Course newInfo) {
    while (head) {
        if (head->data.id == id) {
            head->data = newInfo;
            return;
        }
        head = head->next;
    }
}

Node* markAsCompleted(Node* head, int id, DNode** completedHead) {
    Node *curr = head, *prev = NULL;
    while (curr && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return head;

    // Chuyển sang danh sách hoàn thành
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->data = curr->data;
    newDNode->prev = NULL;
    newDNode->next = *completedHead;
    if (*completedHead) (*completedHead)->prev = newDNode;
    *completedHead = newDNode;

    // Xóa khỏi danh sách đang học
    if (!prev) head = curr->next;
    else prev->next = curr->next;
    free(curr);
    return head;
}

void sortCoursesByCredits(Node* head) {
    if (!head) return;
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data.credit > ptr1->next->data.credit) {
                Course temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void searchCourseByTitle(Node* head, const char* title) {
    int found = 0;
    while (head) {
        if (strcmp(head->data.title, title) == 0) {
            printf("Tìm thấy: ID=%d | Tín chỉ=%d\n", head->data.id, head->data.credit);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("Không tìm thấy khóa học với tên: %s\n", title);
}

void displayCompletedCourses(DNode* head) {
    printf("\n--- Danh sách khóa học hoàn thành ---\n");
    while (head) {
        printf("ID: %d | Tên: %s | Tín chỉ: %d\n", head->data.id, head->data.title, head->data.credit);
        head = head->next;
    }
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void freeDList(DNode* head) {
    while (head) {
        DNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// ====== Chương trình chính ======
int main() {
    Node* courseList = NULL;
    DNode* completedList = NULL;
    int choice;

    do {
        printf("\n======= COURSE MANAGER =======\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien the danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat thong tin khoa hoc\n");
        printf("5. Đanh dau đa hoan thanh\n");
        printf("6. Sap xep theo so tin chi\n");
        printf("7. Tim kiem khoa hoc theo ten\n");
        printf("8. Hien thi khoa hoc đa hoan thanh\n");
        printf("0. Thoat chuong trinh\n");
        printf("Chọn: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            Course c;
            printf("Nhap ma khoa hoc: "); scanf("%d", &c.id); getchar();
            printf("Nhap ten khoa hoc: "); fgets(c.title, sizeof(c.title), stdin);
            c.title[strcspn(c.title, "\n")] = '\0';
            printf("Nhap so tin chi: "); scanf("%d", &c.credit);
            courseList = addCourse(courseList, c);
        } else if (choice == 2) {
            displayCourses(courseList);
        } else if (choice == 3) {
            int id;
            printf("Nhập ID khóa học cần xóa: "); scanf("%d", &id);
            courseList = deleteCourse(courseList, id);
        } else if (choice == 4) {
            int id;
            Course newInfo;
            printf("Nhập ID khóa học cần cập nhật: "); scanf("%d", &id); getchar();
            printf("Tên mới: "); fgets(newInfo.title, sizeof(newInfo.title), stdin);
            newInfo.title[strcspn(newInfo.title, "\n")] = '\0';
            printf("Tín chỉ mới: "); scanf("%d", &newInfo.credit);
            newInfo.id = id;
            updateCourse(courseList, id, newInfo);
        } else if (choice == 5) {
            int id;
            printf("Nhập ID khóa học hoàn thành: "); scanf("%d", &id);
            courseList = markAsCompleted(courseList, id, &completedList);
        } else if (choice == 6) {
            sortCoursesByCredits(courseList);
            printf("Đã sắp xếp theo tín chỉ.\n");
        } else if (choice == 7) {
            char title[100];
            printf("Nhập tên khóa học cần tìm: "); fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = '\0';
            searchCourseByTitle(courseList, title);
        } else if (choice == 8) {
            displayCompletedCourses(completedList);
        }

    } while (choice != 0);

    freeList(courseList);
    freeDList(completedList);
    printf("Đã thoát chương trình.\n");
    return 0;
}
