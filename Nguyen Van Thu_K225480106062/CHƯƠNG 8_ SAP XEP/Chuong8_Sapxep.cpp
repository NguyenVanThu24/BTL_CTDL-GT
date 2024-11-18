#include <iostream>
#include <vector>
using namespace std;

// Hàm nhập mảng
void inputArray(vector<int>& arr) {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    arr.resize(n);
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Hàm xuất mảng
void outputArray(const vector<int>& arr) {
    cout << "Cac phan tu cua mang la: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Hàm Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int jmin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[jmin]) {
                jmin = j;
            }
        }
        if (jmin != i) {
            swap(arr[i], arr[jmin]);
        }
    }
    cout << "Mang da duoc sap xep (Selection Sort)." << endl;
}

// Hàm Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    cout << "Mang da duoc sap xep (Bubble Sort)." << endl;
}

// Hàm Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
    cout << "Mang da duoc sap xep (Insertion Sort)." << endl;
}

// Hàm Heapify cho Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    cout << "Mang da duoc sap xep (Heap Sort)." << endl;
}

// Hàm Partition cho Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm gọi Quick Sort
void quickSortCaller(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
    cout << "Mang da duoc sap xep (Quick Sort)." << endl;
}

// Hàm Merge cho Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Hàm gọi Merge Sort
void mergeSortCaller(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Mang da duoc sap xep (Merge Sort)." << endl;
}

// Menu chương trình
void menu() {
    vector<int> arr;
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Nhap mang\n";
        cout << "2. Xuat mang\n";
        cout << "3. Sap xep mang (Selection Sort)\n";
        cout << "4. Sap xep mang (Bubble Sort)\n";
        cout << "5. Sap xep mang (Insertion Sort)\n";
        cout << "6. Sap xep mang (Heap Sort)\n";
        cout << "7. Sap xep mang (Quick Sort)\n";
        cout << "8. Sap xep mang (Merge Sort)\n";
        cout << "9. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputArray(arr);
                break;
            case 2:
                outputArray(arr);
                break;
            case 3:
                selectionSort(arr);
                break;
            case 4:
                bubbleSort(arr);
                break;
            case 5:
                insertionSort(arr);
                break;
            case 6:
                heapSort(arr);
                break;
            case 7:
                quickSortCaller(arr);
                break;
            case 8:
                mergeSortCaller(arr);
                break;
            case 9:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
        }
    } while (choice != 9);
}

// Hàm chính
int main() {
    menu();
    return 0;
}
