#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_TITLE 100


typedef struct Course {
    int id;
    char title[MAX_LENGTH_TITLE];
    int credit;
} Course;


typedef struct SinglyNode{
    Course course;
    struct SinglyNode* next;
} SinglyNode;


typedef struct DoubleNode{
    Course course;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;


SinglyNode* createNode(Course course){

    SinglyNode* newNode = (SinglyNode*) malloc(sizeof (SinglyNode));
    newNode->course = course; // Gán lại dữ liêu cho Node
    newNode->next = NULL;

    return newNode;
}


DoubleNode* createDoubleNode(Course course){

    DoubleNode* newNode  = (DoubleNode*) malloc(sizeof (DoubleNode));
    newNode->course = course;
    newNode->prev = newNode->next =  NULL;

    return newNode;
}


SinglyNode* createCourse(SinglyNode* head){
    Course course;


    printf("Nhap id: ");
    scanf("%d", &course.id);
    getchar();

    printf("Nhap ten mon an: ");
    fgets(course.title, MAX_LENGTH_TITLE, stdin);
   course.title[strcspn(course.title, "\n")] = 0;

    printf("Nhap gia tien: ");
    scanf("%d", &course.credit);

    SinglyNode* newNode = createNode(course);
    newNode->next = head;

    return newNode;
}

void displayCourse(SinglyNode* head){
    SinglyNode* temp = head;

    printf("Danh sach mon an: \n");

    while (temp != NULL){
        printf("Id: %d | Title: %s | Credit: %d \n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next;
    }
}


void updateCourse(SinglyNode* head){

    int idUpdate;

    printf("Nhap id can cap nhat: ");
    scanf("%d", &idUpdate);

    SinglyNode* temp = head;

    while (temp && temp->course.id != idUpdate){
        temp = temp->next;
    }


    if (!temp){

        printf("Mon an khong ton tai");
        return;
    }
    getchar();

    printf("Nhap ten mon an moi: ");
    fgets(temp->course.title, MAX_LENGTH_TITLE, stdin);
    temp->course.title[strcspn(temp->course.title, "\n")] = 0;

    printf("Nhao gia moi: ");
    scanf("%d", &temp->course.credit);

    printf("Cap nhat mon an thanh cong");
    printf("\n");
}

void markCompletedCourse(SinglyNode* head, DoubleNode* dHead ){
}

void freeMemory(SinglyNode* head, DoubleNode* dHead){

    SinglyNode* temp = head;
    while (temp != NULL){

        SinglyNode* curentNode = temp;
        temp = temp->next;
        free(curentNode);
    }


    DoubleNode * dTemp = dHead;
    while (dTemp != NULL){

        DoubleNode* curentDNode = dTemp;
        dTemp = dTemp->next;
        free(curentDNode);
    }
}

// Hàm hiển thị menu
void showMenu(){
    printf("=====  RESTAURANT =====\n");
    printf("1. Them mon an\n");
    printf("2. Hien thi danh sach mon dang ban\n");
    printf("3. Cap nhat thong tin mon an\n");
    printf("4. Danh dau ngung ban\n");
    printf("5. Hien thi danh sach mon an ngung ban\n");
    printf("6. Tim kiem theo ten mon\n");
    printf("7. Sap xep mon an theo gia tang dan\n");
    printf("8. Thoat chuong trinh\n");
    printf("\n");
}

int main(){
    int choice;
    SinglyNode* head = NULL;
    DoubleNode* dHead = NULL;

    do {

        showMenu();

        printf("Vui long nhap lua chon:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 head = createCourse(head);
                break;
            case 2:
                displayCourse(head);
                break;
            case 3: {
                updateCourse(head);
             break;
            case 4:

                break;
            case 5:
                markCompletedCourse(head, dHead);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Lua chon khong hop le");
                break;
        }


    } while (choice != 8);


    freeMemory(head, dHead);

    return 0;
}