#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc để lưu trữ cạnh
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// So sánh cạnh theo trọng số
bool compareEdge(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Tìm cha của một nút trong Union-Find
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

// Hợp hai tập hợp trong Union-Find
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    // Danh sách các cạnh (u, v, weight)
    vector<Edge> edges = {
        Edge(1, 2, 20),
        Edge(1, 3, 12),
        Edge(1, 4, 10),
        Edge(2, 4, 5),
        Edge(3, 4, 45),
        Edge(2, 3, 52)
    };

    int n = 4; // Số đỉnh
    sort(edges.begin(), edges.end(), compareEdge); // Sắp xếp cạnh theo trọng số

    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;

    vector<Edge> mst; // Lưu trữ cây khung nhỏ nhất
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
        }
    }

    // In cây khung nhỏ nhất
    cout << "Cay khung nho nhat:" << endl;
    for (const auto& edge : mst) {
        cout << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")" << endl;
    }
    cout << "Tong trong so: " << totalWeight << endl;

    return 0;
}
