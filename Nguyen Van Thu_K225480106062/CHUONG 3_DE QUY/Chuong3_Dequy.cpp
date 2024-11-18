#include <iostream>
using namespace std;

// Hàm đệ quy tính số cặp thỏ ở tháng thứ n (dãy Fibonacci)
int Fibonacci(int n) {
    if (n <= 2) {
        return 1; // Phần neo
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2); // Phần đệ quy
    }
}

// Hàm đệ quy giải bài toán Tháp Hà Nội
void ThapHaNoi(int n, int x, int y) {
    if (n == 1) {
        cout << "Chuyen 1 dia tu coc " << x << " sang coc " << y << endl;
    } else {
        int z = 6 - x - y; // Tính cột trung gian (6 = 1 + 2 + 3)
        ThapHaNoi(n - 1, x, z); // Chuyển n-1 đĩa từ cọc x sang cọc trung gian
        cout << "Chuyen 1 dia tu coc " << x << " sang coc " << y << endl;
        ThapHaNoi(n - 1, z, y); // Chuyển n-1 đĩa từ cọc trung gian sang cọc y
    }
}

int main() {
    int Menu;
    do {
        // Hiển thị menu
        cout << "==================== MENU ====================" << endl;
        cout << "1. Tinh so cap tho o thang thu n (Day Fibonacci)" << endl;
        cout << "2. Giai bai toan Thap Ha Noi" << endl;
        cout << "3. Thoat chuong trinh" << endl;
        cout << "==============================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> Menu;

        switch (Menu) {
            case 1: {
                // Tính số cặp thỏ
                int n;
                cout << "Nhap thang n: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Thang n phai lon hon 0!" << endl;
                } else {
                    cout << "So cap tho o thang thu " << n << " la: " << Fibonacci(n) << endl;
                }
                break;
            }
            case 2: {
                // Giải bài toán Tháp Hà Nội
                int n;
                cout << "Nhap so dia: ";
                cin >> n;
                if (n <= 0) {
                    cout << "So dia phai lon hon 0!" << endl;
                } else {
                    cout << "Cac buoc chuyen dia: " << endl;
                    ThapHaNoi(n, 1, 3); // Gọi hàm Move với cột 1 (A) và cột 3 (C)
                }
                break;
            }
            case 3:
                // Thoát chương trình
                cout << "Thoat chuong trinh. Cam on ban da su dung!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }
    } while (Menu != 3);

    return 0;
}
