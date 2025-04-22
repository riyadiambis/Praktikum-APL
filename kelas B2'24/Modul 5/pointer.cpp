#include<iostream>
using namespace std;

int main(){
    // int a=10;
    // cout << a;

    //operator * dan &
    // * --> menginisialisasi variabel pointer dan mengakses value
    // & --> mengakses akses memori

    int a = 10;
    int *b = &a;
    
    cout << "nilai dari a: " << a << endl;
    cout << "alamat dari a: " << b << endl;
    cout << &a << endl;

    return 0;
}