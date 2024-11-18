#include <iostream>
using namespace std;

int main() {
    // Khởi tạo mảng với dãy số đã cho
    int arr[] = {15, 5, 2, 9, 38, 5};
    int n = sizeof(arr) / sizeof(arr[0]);  // Kích thước của mảng
    int value_to_find = 5;  // Giá trị cần tìm
    bool found = false;     // Biến kiểm tra xem có tìm thấy không

    // Duyệt qua từng phần tử của mảng
    cout << "Cac vi tri co gia tri bang 5: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == value_to_find) {
            cout << i << " ";  // In ra vị trí của phần tử bằng 5
            found = true;      // Đánh dấu là đã tìm thấy
        }
    }

    // Nếu không tìm thấy giá trị nào bằng 5
    if (!found) {
        cout << "Khong co phan tu nao co gia tri bang 5.";
    }
    
    cout << endl;
    return 0;
}
