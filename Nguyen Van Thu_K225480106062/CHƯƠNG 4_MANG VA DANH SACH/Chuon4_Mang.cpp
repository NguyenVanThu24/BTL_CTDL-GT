#include <iostream>
using namespace std;
//Ham nhap mang
void Nhapmang(int a[], int n){
	for(int i = 0; i<n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
//Ham xuat mang
void Xuatmang(int a[], int n){
	for(int i = 0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	int a[100]; //mang chua toi da 100 phan tu
	int n;
	cout<<"Nhap so phan tu cua mang: n = ";
	cin>>n;
	cout<<"\nNhap mang: "<<endl;
	//Goi ham Nhapmang
	Nhapmang(a, n);
	cout<<"\nXuat mang: ";
	//Goi ham xuat mang
	Xuatmang(a, n);
	return 0;
}
