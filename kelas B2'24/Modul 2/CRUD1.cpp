<<<<<<< HEAD
#include<iostream>
using namespace std;

#define MAX_BUAH 100 // Ukuran maksimum array buah

int main(){
    int panjang = 0; // Jumlah elemen saat ini
    string buah[MAX_BUAH]; // Array dengan ukuran tetap
    int pilihan, index;
    do {
        system("clear");
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
        // Tampilkan buah
        break;
        case 2:
        // Tambah buah
        break;
        case 3:
        // Ubah buah
        break;
        case 4:
        // Hapus buah
        break;
        case 5:
        cout << "Program selesai" << endl;
        break;
        default:
        cout << "Pilihan tidak valid" << endl;
        break;
    }
    } while (pilihan != 5);
    return 0;
=======
#include<iostream>
using namespace std;

#define MAX_BUAH 100 // Ukuran maksimum array buah

int main(){
    int panjang = 0; // Jumlah elemen saat ini
    string buah[MAX_BUAH]; // Array dengan ukuran tetap
    int pilihan, index;
    do {
        system("clear");
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
        // Tampilkan buah
        break;
        case 2:
        // Tambah buah
        break;
        case 3:
        // Ubah buah
        break;
        case 4:
        // Hapus buah
        break;
        case 5:
        cout << "Program selesai" << endl;
        break;
        default:
        cout << "Pilihan tidak valid" << endl;
        break;
    }
    } while (pilihan != 5);
    return 0;
>>>>>>> ec2900c (tambah kelas)
}