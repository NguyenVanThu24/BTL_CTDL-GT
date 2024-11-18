#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một nút trong danh sách
struct Node {
    int data;       // Giá trị của nút
    Node* next;     // Con trỏ tới nút kế tiếp
};

// Con trỏ tới danh sách liên kết
Node* L = NULL;

// Tạo một nút mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Xóa một nút ở cuối danh sách
void delete_cuoi() {
    if (L == NULL) {
        cout << "Danh sach trong\n";
    } else if (L->next == NULL) {  // Nếu chỉ có một phần tử
        delete L;
        L = NULL;
    } else {
        Node* temp = L;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next; // Tìm nút cuối
        }
        prev->next = NULL;
        delete temp; // Xóa nút cuối
    }
    cout << "Danh sach sau khi xoa cuoi: ";
    void display();
}

// Xóa một nút ở đầu danh sách
void delete_dau() {
    if (L == NULL) {
        cout << "Danh sach trong\n";
    } else {
        Node* temp = L;
        L = L->next;
        delete temp;
    }
    cout << "Danh sach sau khi xoa dau: ";
    void display();
}

// Thêm một nút vào cuối danh sách
void insert_cuoi(int value) {
    Node* newNode = createNode(value);
    if (L == NULL) {
        L = newNode;
    } else {
        Node* temp = L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Danh sach sau khi them cuoi: ";
    void display();
}

// Thêm một nút vào đầu danh sách
void insert_dau(int value) {
    Node* newNode = createNode(value);
    if (L == NULL) {
        L = newNode;
    } else {
        newNode->next = L;
        L = newNode;
    }
    cout << "Danh sach sau khi them dau: ";
    void display();
}

// Xóa nút đầu tiên có giá trị x trong danh sách
void delete_value(int value) {
    if (L == NULL) {
        cout << "Danh sach trong\n";
        return;
    }

    if (L->data == value) {  // Xóa nút có giá trị đầu danh sách
        Node* temp = L;
        L = L->next;
        delete temp;
        cout << "Danh sach sau khi xoa gia tri " << value << ": ";
        void display();
        return;
    }

    Node* temp = L;
    Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Gia tri " << value << " khong ton tai trong danh sach\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Danh sach sau khi xoa gia tri " << value << ": ";
    void display();
}

// Hiển thị danh sách
void display() {
    if (L == NULL) {
        cout << "Danh sach trong\n";
        return;
    }
    Node* temp = L;
    cout << "Danh sach: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menu điều khiển
void showMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Them vao dau danh sach" << endl;
    cout << "2. Them vao cuoi danh sach" << endl;
    cout << "3. Xoa o dau danh sach" << endl;
    cout << "4. Xoa o cuoi danh sach" << endl;
    cout << "5. Xoa gia tri trong danh sach" << endl;
    cout << "6. Thoat" << endl;
}

int main() {
    int choice, value;

    do {
        showMenu();
        cout << "Nhap lua chon: ";
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
            cout << "Thoat chuong trinh!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 6);

    return 0;
}
