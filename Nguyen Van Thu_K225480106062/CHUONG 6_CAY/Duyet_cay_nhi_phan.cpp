#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int value;    // Giá trị của nút
    Node* left;   // Con trái
    Node* right;  // Con phải

    // Hàm khởi tạo để tạo nút mới
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Hàm tạo cây nhị phân từ mảng giá trị
Node* createTreeFromArray(const vector<int>& values) {
    if (values.empty() || values[0] == -1) {
        return nullptr; // Trả về nullptr nếu mảng rỗng hoặc giá trị gốc là -1
    }

    Node* root = new Node(values[0]); // Tạo nút gốc
    queue<Node*> q;  // Dùng hàng đợi để quản lý các nút
    q.push(root);

    int i = 1;
    while (i < values.size()) {
        Node* current = q.front();
        q.pop();

        // Gán con trái
        if (values[i] != -1) {
            current->left = new Node(values[i]);
            q.push(current->left);
        }
        i++;

        // Gán con phải
        if (i < values.size() && values[i] != -1) {
            current->right = new Node(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Hàm Duyệt trước (Preorder)
void Preorder(Node* root) {
    if (root != nullptr) {
        cout << root->value << " ";  // In giá trị của nút hiện tại
        Preorder(root->left);        // Duyệt con trái
        Preorder(root->right);       // Duyệt con phải
    }
}

// Hàm Duyệt giữa (Inorder)
void Inorder(Node* root) {
    if (root != nullptr) {
        Inorder(root->left);        // Duyệt con trái
        cout << root->value << " "; // In giá trị của nút hiện tại
        Inorder(root->right);       // Duyệt con phải
    }
}

// Hàm Duyệt sau (Postorder)
void Postorder(Node* root) {
    if (root != nullptr) {
        Postorder(root->left);      // Duyệt con trái
        Postorder(root->right);     // Duyệt con phải
        cout << root->value << " "; // In giá trị của nút hiện tại
    }
}

// Hàm hiển thị menu và thực hiện các chức năng tương ứng
void menu() {
    Node* root = nullptr;  // Cây ban đầu chưa có giá trị
    vector<int> values;    // Mảng chứa các giá trị để tạo cây
    int choice;
    
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap du lieu cay\n";
        cout << "2. Duyet truoc (Preorder)\n";
        cout << "3. Duyet giua (Inorder)\n";
        cout << "4. Duyet sau (Postorder)\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "Nhap so luong phan tu cua cay: ";
            cin >> n;

            values.resize(n);
            cout << "Nhap cac gia tri cua cay (nhap -1 de bo qua nut rong):\n";
            for (int i = 0; i < n; i++) {
                cout << "Phan tu thu " << i + 1 << ": ";
                cin >> values[i];
            }
            root = createTreeFromArray(values);  // Tạo cây từ mảng giá trị
            break;
        }
        case 2:
            if (root == nullptr) {
                cout << "Cay rong. Vui long nhap du lieu cay truoc.\n";
            } else {
                cout << "Duyet truoc (Preorder): ";
                Preorder(root);
                cout << endl;
            }
            break;
        case 3:
            if (root == nullptr) {
                cout << "Cay rong. Vui long nhap du lieu cay truoc.\n";
            } else {
                cout << "Duyet giua (Inorder): ";
                Inorder(root);
                cout << endl;
            }
            break;
        case 4:
            if (root == nullptr) {
                cout << "Cay rong. Vui long nhap du lieu cay truoc.\n";
            } else {
                cout << "Duyet sau (Postorder): ";
                Postorder(root);
                cout << endl;
            }
            break;
        case 5:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();  // Gọi hàm menu để thực hiện chương trình
    return 0;
}
