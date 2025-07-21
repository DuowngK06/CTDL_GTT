#include <iostream>
using namespace std;

// Khai báo cấu trúc Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo một node mới với dữ liệu do người dùng nhập
Node* createNode() {
    int value;
    cout << "Nhap so nguyen cho Node: ";
    cin >> value;

    // Cấp phát và khởi tạo Node mới
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
