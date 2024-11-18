#include <iostream>
using namespace std;

// Hàm heapify (đưa một nút về đúng vị trí trong Max-Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;         // Giả sử nút hiện tại là lớn nhất
    int left = 2 * i + 1;    // Chỉ số nút con trái
    int right = 2 * i + 2;   // Chỉ số nút con phải

    // Kiểm tra nếu nút con trái lớn hơn nút hiện tại
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Kiểm tra nếu nút con phải lớn hơn nút lớn nhất hiện tại
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Nếu nút hiện tại không phải lớn nhất, hoán đổi và đệ quy
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm Heap Sort
void heapSort(int arr[], int n) {
    // Bước 1: Xây dựng Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Bước 2: Lấy từng phần tử từ Heap và sắp xếp
    for (int i = n - 1; i > 0; i--) {
        // Đưa phần tử lớn nhất (ở gốc) về cuối mảng
        swap(arr[0], arr[i]);

        // Giảm kích thước Heap và điều chỉnh lại đống
        heapify(arr, i, 0);
    }
}

// Hàm chính
int main() {
    int arr[] = {15, 90, 31, 27, 4, 59, 27}; // Dữ liệu mảng đầu vào
    int n = sizeof(arr) / sizeof(arr[0]);    // Độ dài của mảng

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Gọi hàm Heap Sort để sắp xếp mảng
    heapSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
