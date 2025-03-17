#include<iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    int umur;
    float ipk;
};

int main(){
    // string nama;
    // cout << "Nama kamu siapa: ";
    // // cin >> nama;
    // getline(cin, nama);
    // cout << "Halo, " << nama << endl;
    // return 0;

    // cout << "ukuran int : " << sizeof(int) << endl;
    // cout << "ukuran float : " << sizeof(float) << endl;
    // cout << "ukuran chart : " << sizeof(char) << endl;
    // cout << "ukuran double : " << sizeof(double) << endl;
    // cout << "ukuran long : " << sizeof(long) << endl;

    // bool sudahMakan = true;
    // string status = sudahMakan ? "Sudah donk Bang" : "Belum Bang";
    // cout << status << endl;

    // int nilai;
    // cout << "Masukkan nilai : ";
    // cin >> nilai;

    // switch (nilai){
    //     case 80:
    //     cout << "A" << endl;
    //     case 70:
    //     cout << "B" << endl;
    //     case 60:
    //     cout << "C" << endl;
    // }


    // int a, b; 
 
    // cout << "Masukkan nilai a: "; 
    // cin >> a; 
    // cout << "Masukkan nilai b: "; 
    // cin >> b; 
 
    // // Dan 
    // cout << "Apakah a lebih besar dari 0 dan b lebih kecil dari 10? " << 
    // (a > 0 && b < 10) << endl; 
 
    // // Atau 
    // cout << "Apakah a lebih besar dari 0 atau b lebih kecil dari 10? " << 
    // (a > 0 || b < 10) << endl; 
 
    // // Tidak 
    // cout << "Apakah a lebih besar dari 0? " << !a << endl; 

    int arr[] = {1, 2, 3, 4, 5}; 
    for (int x : arr){ 
    cout << x << endl; 
    };
}