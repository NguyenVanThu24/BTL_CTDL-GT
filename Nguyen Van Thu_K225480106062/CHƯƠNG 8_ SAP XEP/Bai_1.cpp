#include <iostream>
using namespace std;

// Hàm thực hiện sắp xếp nổi bọt (bubble sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi nếu phần tử trước lớn hơn phần tử sau
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm tìm kiếm phần tử có giá trị bằng 5
int searchElement(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;  // Trả về vị trí của phần tử nếu tìm thấy
    }
    return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
    int n;
    
    // Nhập số phần tử của mảng
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    
    int arr[n];  // Khai báo mảng với kích thước n
    
    // Nhập các phần tử của mảng
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sắp xếp mảng
    bubbleSort(arr, n);
    
    // In mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Tìm kiếm phần tử có giá trị bằng 5
    int x = 5;
    int result = searchElement(arr, n, x);
    
    if (result != -1) {
        cout << "Phan tu " << x << " duoc tim thay tai vi tri: " << result << endl;
    } else {
        cout << "Phan tu " << x << " khong co trong mang." << endl;
    }

    return 0;
}
