#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tìm kiếm tuần tự (Sequential Search)
int SequentialSearch(const vector<int>& arr, int X) {
    int n = arr.size();
    // Thêm một phần tử phụ bằng X vào cuối mảng để xử lý khi không tìm thấy
    vector<int> tempArr = arr;
    tempArr.push_back(X);
    
    int i = 0;
    while (tempArr[i] != X) {
        i++;
    }
    return (i == n) ? 0 : i + 1; // Trả về 0 nếu không tìm thấy, ngược lại trả về chỉ số
}

// Hàm tìm kiếm nhị phân (Binary Search)
int BinarySearch(const vector<int>& arr, int X) {
    int inf = 0, sup = arr.size() - 1;
    
    while (inf <= sup) {
        int median = (inf + sup) / 2;
        if (arr[median] == X) {
            return median + 1; // Trả về chỉ số + 1 (theo yêu cầu đề bài)
        } else if (arr[median] < X) {
            inf = median + 1;
        } else {
            sup = median - 1;
        }
    }
    return 0; // Không tìm thấy
}

// Hàm hiển thị menu
void displayMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Tim kiem tuan tu (Sequential Search)\n";
    cout << "2. Tim kiem nhi phan (Binary Search)\n";
    cout << "3. Thoat\n";
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    int n, X, choice;

    cout << "Nhap so luong phan tu mang: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Sắp xếp mảng để đảm bảo tìm kiếm nhị phân hoạt động
    sort(arr.begin(), arr.end());

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:{
        	cout << "Nhap gia tri X can tim: ";
            cin >> X;
            int resultSequential = SequentialSearch(arr, X);
            if (resultSequential == 0) {
                cout << "Khong tim thay gia tri " << X << " trong mang (Tim kiem tuan tu).\n";
            } else {
                cout << "Tim thay gia tri " << X << " tai chi so " << resultSequential << " (Tim kiem tuan tu).\n";
            }
			break;
		}
            
        case 2:{
        	cout << "Nhap gia tri X can tim: ";
            cin >> X;
            int resultBinary = BinarySearch(arr, X);
            if (resultBinary == 0) {
                cout << "Khong tim thay gia tri " << X << " trong mang (Tim kiem nhi phan).\n";
            } else {
                cout << "Tim thay gia tri " << X << " tai chi so " << resultBinary << " (Tim kiem nhi phan).\n";
            }
			break;
		}

        case 3:{
        	cout << "Thoat chuong trinh.\n";
			break;
		}

        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
