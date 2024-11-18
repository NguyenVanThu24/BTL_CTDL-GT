#include <iostream>
using namespace std;

// Lớp Stack
class Cstack {
private:
    int *StkArr;  // Mảng chứa các phần tử của stack
    int StkMax;   // Kích thước tối đa của stack
    int StkTop;   // Chỉ số của phần tử trên đỉnh stack

public:
    Cstack(int size) {
        StkArr = new int[size];  // Khởi tạo mảng có kích thước 'size'
        StkMax = size;           // Gán kích thước tối đa cho stack
        StkTop = -1;             // Khởi tạo stack rỗng (đỉnh là -1)
    }

    ~Cstack() {
        delete[] StkArr;        // Giải phóng mảng khi stack bị hủy
    }

    bool isEmpty() {
        return (StkTop == -1);   // Kiểm tra stack có rỗng không
    }

    bool isFull() {
        return (StkTop == StkMax - 1); // Kiểm tra stack có đầy không
    }

    bool Push(int newItem) {
        if (isFull()) {
            cout << "Stack day!" << endl; // Nếu stack đầy
            return false;
        }
        StkTop++;             // Tăng đỉnh stack
        StkArr[StkTop] = newItem;  // Thêm phần tử vào đỉnh stack
        cout << "Them thanh cong!" << endl;
        return true;
    }

    bool Pop(int &outItem) {
        if (isEmpty()) {
            cout << "Stack rong!" << endl; // Nếu stack rỗng
            return false;
        }
        outItem = StkArr[StkTop];  // Lấy phần tử trên đỉnh stack
        StkTop--;                   // Giảm đỉnh stack xuống
        return true;
    }

    bool Peek(int &topItem) {
        if (isEmpty()) {
            cout << "Stack rong!" << endl; // Nếu stack rỗng
            return false;
        }
        topItem = StkArr[StkTop]; // Lấy phần tử trên đỉnh stack mà không xóa
        return true;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl; // Nếu stack rỗng
            return;
        }
        cout << "Cac phan tu trong Stack: ";
        for (int i = 0; i <= StkTop; i++) {
            cout << StkArr[i] << " "; // In ra các phần tử trong stack
        }
        cout << endl;
    }
};

// Lớp Queue
class Queue {
private:
    int *QArray;  // Mảng chứa các phần tử của queue
    int QMax;     // Kích thước tối đa của queue
    int QFront;   // Vị trí đầu queue
    int QRear;    // Vị trí cuối queue
    int QNumItems; // Số phần tử hiện có trong queue

public:
    Queue(int size) {
        QArray = new int[size]; // Khởi tạo mảng chứa các phần tử của queue
        QMax = size;            // Gán kích thước tối đa cho queue
        QFront = QRear = -1;    // Khởi tạo queue rỗng
        QNumItems = 0;          // Số phần tử ban đầu là 0
    }

    ~Queue() {
        delete[] QArray;  // Giải phóng mảng khi queue bị hủy
    }

    bool IsEmpty() {
        return (QNumItems == 0); // Kiểm tra queue có rỗng không
    }

    bool IsFull() {
        return (QNumItems == QMax); // Kiểm tra queue có đầy không
    }

    bool Append(int newItem) {
        if (IsFull()) {
            cout << "Queue day!" << endl; // Nếu queue đầy
            return false;
        }
        if (QNumItems == 0) QFront = 0; // Nếu queue rỗng, khởi tạo QFront
        QRear = (QRear + 1) % QMax;  // Tăng QRear và vòng lại nếu cần
        QArray[QRear] = newItem;     // Thêm phần tử vào cuối queue
        QNumItems++;                 // Tăng số phần tử trong queue
        cout << "Them thanh cong!" << endl;
        return true;
    }

    bool Take(int &itemOut) {
        if (IsEmpty()) {
            cout << "Queue rong!" << endl; // Nếu queue rỗng
            return false;
        }
        itemOut = QArray[QFront];  // Lấy phần tử từ đầu queue
        QFront = (QFront + 1) % QMax; // Tăng QFront và vòng lại nếu cần
        QNumItems--;  // Giảm số phần tử trong queue
        if (QNumItems == 0) QFront = QRear = -1;  // Nếu queue rỗng
        return true;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue rong!" << endl; // Nếu queue rỗng
            return;
        }
        cout << "Cac phan tu trong Queue: ";
        int i = QFront;
        for (int j = 0; j < QNumItems; j++) {
            cout << QArray[i] << " ";  // In các phần tử trong queue
            i = (i + 1) % QMax;        // Vòng lại nếu cần
        }
        cout << endl;
    }
};

// Hàm hiển thị menu Stack
void ShowStackMenu() {
    cout << "\n=== Menu Stack ===" << endl;
    cout << "1. Them phan tu vao Stack" << endl;
    cout << "2. Lay phan tu ra khoi Stack" << endl;
    cout << "3. Xem phan tu dinh Stack" << endl;
    cout << "4. Kiem tra Stack rong" << endl;
    cout << "5. Kiem tra Stack day" << endl;
    cout << "6. Quay lai menu chinh" << endl;
}

// Hàm hiển thị menu Queue
void ShowQueueMenu() {
    cout << "\n=== Menu Queue ===" << endl;
    cout << "1. Them phan tu vao Queue" << endl;
    cout << "2. Lay phan tu ra khoi Queue" << endl;
    cout << "3. Kiem tra Queue rong" << endl;
    cout << "4. Kiem tra Queue day" << endl;
    cout << "5. Quay lai menu chinh" << endl;
}

int main() {
    int choiceMain, choiceStack, choiceQueue;
    Cstack myStack(5); // Khởi tạo Stack với kích thước 5
    Queue myQueue(5);  // Khởi tạo Queue với kích thước 5

    do {
        // Menu chính
        cout << "\n=== Menu chinh ===" << endl;
        cout << "1. Quan ly Stack" << endl;
        cout << "2. Quan ly Queue" << endl;
        cout << "3. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> choiceMain;

        if (choiceMain == 1) {
            do {
                ShowStackMenu(); // Hiển thị menu Stack
                cout << "Chon chuc nang: ";
                cin >> choiceStack;

                int value, topValue;
                switch (choiceStack) {
                case 1:
                    cout << "Nhap gia tri can them: ";
                    cin >> value;
                    myStack.Push(value);
                    myStack.Display();  // Hiển thị stack sau khi thêm phần tử
                    break;

                case 2:
                    if (myStack.Pop(value)) {
                        cout << "Phan tu lay ra: " << value << endl;
                    }
                    break;

                case 3:
                    if (myStack.Peek(topValue)) {
                        cout << "Phan tu dinh Stack: " << topValue << endl;
                    }
                    break;

                case 4:
                    if (myStack.isEmpty()) {
                        cout << "Stack rong!" << endl;
                    } else {
                        cout << "Stack khong rong!" << endl;
                    }
                    break;

                case 5:
                    if (myStack.isFull()) {
                        cout << "Stack day!" << endl;
                    } else {
                        cout << "Stack khong day!" << endl;
                    }
                    break;

                case 6:
                    break; // Quay lại menu chính

                default:
                    cout << "Lua chon khong hop le!" << endl;
                }
            } while (choiceStack != 6); // Lặp lại menu Stack cho đến khi chọn quay lại
        } else if (choiceMain == 2) {
            do {
                ShowQueueMenu(); // Hiển thị menu Queue
                cout << "Chon chuc nang: ";
                cin >> choiceQueue;

                int item;
                switch (choiceQueue) {
                case 1:
                    cout << "Nhap gia tri can them: ";
                    cin >> item;
                    myQueue.Append(item);
                    myQueue.Display();  // Hiển thị queue sau khi thêm phần tử
                    break;

                case 2:
                    if (myQueue.Take(item)) {
                        cout << "Phan tu lay ra: " << item << endl;
                    }
                    break;

                case 3:
                    if (myQueue.IsEmpty()) {
                        cout << "Queue rong!" << endl;
                    } else {
                        cout << "Queue khong rong!" << endl;
                    }
                    break;

                case 4:
                    if (myQueue.IsFull()) {
                        cout << "Queue day!" << endl;
                    } else {
                        cout << "Queue khong day!" << endl;
                    }
                    break;

                case 5:
                    break; // Quay lại menu chính

                default:
                    cout << "Lua chon khong hop le!" << endl;
                }
            } while (choiceQueue != 5); // Lặp lại menu Queue cho đến khi chọn quay lại
        } else if (choiceMain == 3) {
            cout << "Thoat chuong trinh!" << endl;
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choiceMain != 3); // Lặp lại menu chính cho đến khi chọn thoát
}
