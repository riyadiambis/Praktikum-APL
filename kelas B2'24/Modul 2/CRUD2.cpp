<<<<<<< HEAD
#include<iostream>
using namespace std;

int main(){
    string nama[100];
    int jumlahData = 0;
    int pilihan;
    
    do {
        // Tampilan Menu
        cout << "=== MENU CRUD ===" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan = ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                // Input Data
                cout << "Masukkan nama: ";
                cin >> nama[jumlahData];
                jumlahData++;
                cout << "Data berhasil ditambahkan!" << endl;
                break;

            case 2:
                // Tampilkan Data
                if(jumlahData > 0) {
                    cout << "\nDaftar Nama:" << endl;
                    for(int i = 0; i < jumlahData; i++) {
                        cout << i+1 << ". " << nama[i] << endl;
                    }
                } else {
                    cout << "Belum ada data!" << endl;
                }
                break;

            case 3:
                // Hapus Data
                if(jumlahData > 0) {
                    int index;
                    cout << "Masukkan nomor data yang akan dihapus: ";
                    cin >> index;
                    if(index > 0 && index <= jumlahData) {
                        for(int i = index-1; i < jumlahData-1; i++) {
                            nama[i] = nama[i+1];
                        }
                        jumlahData--;
                        cout << "Data berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor data tidak valid!" << endl;
                    }
                } else {
                    cout << "Belum ada data!" << endl;
                }
                break;

            case 4:
                cout << "Program selesai!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while(pilihan != 4);

    return 0;
=======
#include<iostream>
using namespace std;

int main(){
    string nama[100];
    int jumlahData = 0;
    int pilihan;
    
    do {
        // Tampilan Menu
        cout << "=== MENU CRUD ===" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan = ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                // Input Data
                cout << "Masukkan nama: ";
                cin >> nama[jumlahData];
                jumlahData++;
                cout << "Data berhasil ditambahkan!" << endl;
                break;

            case 2:
                // Tampilkan Data
                if(jumlahData > 0) {
                    cout << "\nDaftar Nama:" << endl;
                    for(int i = 0; i < jumlahData; i++) {
                        cout << i+1 << ". " << nama[i] << endl;
                    }
                } else {
                    cout << "Belum ada data!" << endl;
                }
                break;

            case 3:
                // Hapus Data
                if(jumlahData > 0) {
                    int index;
                    cout << "Masukkan nomor data yang akan dihapus: ";
                    cin >> index;
                    if(index > 0 && index <= jumlahData) {
                        for(int i = index-1; i < jumlahData-1; i++) {
                            nama[i] = nama[i+1];
                        }
                        jumlahData--;
                        cout << "Data berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor data tidak valid!" << endl;
                    }
                } else {
                    cout << "Belum ada data!" << endl;
                }
                break;

            case 4:
                cout << "Program selesai!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while(pilihan != 4);

    return 0;
>>>>>>> ec2900c (tambah kelas)
}