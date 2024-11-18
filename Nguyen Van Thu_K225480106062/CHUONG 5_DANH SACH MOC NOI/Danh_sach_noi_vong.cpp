#include <iostream>
using namespace std;

// Cấu trúc Node
struct Node {
    int data;       // Dữ liệu của Node
    Node* next;     // Con trỏ tới Node tiếp theo
};

// Con trỏ đầu và cuối danh sách
Node* head = NULL;
Node* tail = NULL;

// Hàm hiển thị danh sách
void display() {
    if (head == NULL) {
        cout << "Danh sach trong." << endl;
        return;
    }
    Node* temp = head;
    cout << "Danh sach: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Lặp lại đến khi quay lại Node đầu tiên
    cout << endl;
}

// Tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm Node vào đầu danh sách
void insert_dau(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) { // Nếu danh sách rỗng
        head = tail = newNode;
        tail->next = head; // Kết nối lại thành vòng
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head; // Kết nối lại tail với head
    }
    cout << "Da them vao dau danh sach." << endl;
    display(); // Hiển thị danh sách sau khi thêm
}

// Thêm Node vào cuối danh sách
void insert_cuoi(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) { // Nếu danh sách rỗng
        head = tail = newNode;
        tail->next = head; // Kết nối lại thành vòng
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Kết nối lại tail với head
    }
    cout << "Da them vao cuoi danh sach." << endl;
    display(); // Hiển thị danh sách sau khi thêm
}

// Xóa Node ở đầu danh sách
void delete_dau() {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) { // Nếu chỉ có một phần tử
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head; // Kết nối lại tail với head mới
    }
    delete temp;
    cout << "Da xoa Node o dau danh sach." << endl;
    display(); // Hiển thị danh sách sau khi xóa
}

// Xóa Node ở cuối danh sách
void delete_cuoi() {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) { // Nếu chỉ có một phần tử
        head = tail = NULL;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head; // Kết nối lại Node cuối mới với head
        delete tail;
        tail = temp;
    }
    cout << "Da xoa Node o cuoi danh sach." << endl;
    display(); // Hiển thị danh sách sau khi xóa
}

// Xóa Node có giá trị cụ thể
void delete_value(int value) {
    if (head == NULL) {
        cout << "Danh sach trong, khong the xoa." << endl;
        return;
    }
    if (head->data == value) { // Nếu Node đầu có giá trị cần xóa
        delete_dau();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == value) {
            prev->next = temp->next;
            if (temp == tail) { // Nếu Node cuối có giá trị cần xóa
                tail = prev;
            }
            delete temp;
            cout << "Da xoa Node co gia tri " << value << "." << endl;
            display(); // Hiển thị danh sách sau khi xóa
            return;
        }
    } while (temp != head);
    cout << "Gia tri " << value << " khong ton tai trong danh sach." << endl;
}

// Hàm main với menu lựa chọn
int main() {
    int choice, value;

    do {
        cout << "\n===== MENU DANH SACH MOC NOI VONG =====" << endl;
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
