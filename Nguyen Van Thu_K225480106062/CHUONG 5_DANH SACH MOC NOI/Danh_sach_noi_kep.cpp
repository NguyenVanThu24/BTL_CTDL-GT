#include <iostream>
using namespace std;

// Khai bao cau truc Node
struct Node {
    int data;       // Gia tri cua Node
    Node* next;     // Con tro toi Node tiep theo
    Node* prev;     // Con tro toi Node truoc do
};

// Khai bao con tro dau va cuoi cua danh sach
Node* head = NULL;
Node* tail = NULL;

// Ham tao mot Node moi
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Ham hien thi danh sach
void display() {
    if (head == NULL) {
        cout << "Danh sach trong." << endl;
        return;
    }
    Node* temp = head;
    cout << "Danh sach: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Them mot Node vao dau danh sach
void insert_dau(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) { // Neu danh sach trong
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "Da them vao dau danh sach." << endl;
    display(); // Hien thi danh sach sau khi them
}

// Them mot Node vao cuoi danh sach
void insert_cuoi(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) { // Neu danh sach trong
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cout << "Da them vao cuoi danh sach." << endl;
    display(); // Hien thi danh sach sau khi them
}

// Xoa Node o dau danh sach
void delete_dau() {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) { // Neu chi co mot phan tu
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    cout << "Da xoa Node o dau danh sach." << endl;
    display(); // Hien thi danh sach sau khi xoa
}

// Xoa Node o cuoi danh sach
void delete_cuoi() {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    Node* temp = tail;
    if (head == tail) { // Neu chi co mot phan tu
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
    cout << "Da xoa Node o cuoi danh sach." << endl;
    display(); // Hien thi danh sach sau khi xoa
}

// Xoa Node co gia tri cho truoc
void delete_value(int value) {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Gia tri " << value << " khong ton tai trong danh sach." << endl;
        return;
    }
    if (temp == head) { // Xoa dau
        delete_dau();
        return;
    }
    if (temp == tail) { // Xoa cuoi
        delete_cuoi();
        return;
    }
    // Xoa o giua
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "Da xoa Node co gia tri " << value << "." << endl;
    display(); // Hien thi danh sach sau khi xoa
}

// Ham main voi menu lua chon
int main() {
    int choice, value;

    do {
        cout << "\n===== MENU DANH SACH MOC NOI KEP =====" << endl;
        cout << "1. Them vao dau danh sach" << endl;
        cout << "2. Them vao cuoi danh sach" << endl;
        cout << "3. Xoa Node o dau danh sach" << endl;
        cout << "4. Xoa Node o cuoi danh sach" << endl;
        cout << "5. Xoa Node co gia tri x" << endl;
        cout << "6. Hien thi danh sach" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can them vao dau: ";
            cin >> value;
            insert_dau(value);
            break;
        case 2:
            cout << "Nhap gia tri can them vao cuoi: ";
            cin >> value;
            insert_cuoi(value);
            break;
        case 3:
            delete_dau();
            break;
        case 4:
            delete_cuoi();
            break;
        case 5:
            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            delete_value(value);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
        }
    } while (choice != 7);

    return 0;
}
