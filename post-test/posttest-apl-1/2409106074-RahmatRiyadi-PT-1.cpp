#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main(){
    string username, password;
    int percobaan = 0;
    bool berhasil = false;
    bool lanjut = true;
    
    cout << "====================================================\n";
    cout << setw(40) << "APLIKASI KONVERSI SERBAGUNA" << endl;
    cout << "====================================================\n";
    cout << setw(45) << "Anda memiliki kesempatan login sebanyak 3 kali" << endl;
    cout << "----------------------------------------------------\n\n";
    
    while(percobaan < 3 && !berhasil){
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;
        
        if(username == "rahmatriyadi" && password == "2409106074"){
            cout << setw(30) << "Login berhasil!" << endl;
            cout << "----------------------------------------------------\n";
            berhasil = true;
            cin.ignore();
            cin.get();
        } else {
            percobaan++;
            cout << "Login gagal! (Percobaan ke-" << percobaan << ")" << endl;
            if(percobaan == 3){
                cout << "\n\n\nAnda telah mencoba 3 kali. Program dihentikan!" << endl;
                cout << "----------------------------------------------------\n";
                cin.ignore();
                cin.get();
            }
            cout << endl;
        }
    }
    
    while(lanjut && berhasil){
        system("cls");
        cout << "====================================================\n";
        cout << setw(30) << "MENU UTAMA" << endl;
        cout << "====================================================\n";
        int pilihan;
        cout << "1. Konversi Mata Uang\n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. Konversi Data Digital\n";  
        cout << "5. Logout\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan){
        case 1:
            {
                bool kembali = false;
                while(!kembali){
                    system("cls");
                    cout << "----------------------------------------------------\n";
                    cout << setw(30) << "Menu Konversi Mata Uang" << endl;
                    cout << "----------------------------------------------------\n";
                    int plh1;
                    float IDR, USD, EUR;
                    float k_IDR_USD, k_IDR_EUR, k_USD_IDR, k_USD_EUR, k_EUR_IDR, k_EUR_USD;
                    cout << "\nSilahkan pilih mata uang yang ingin dikonversi!\n\n";
                    cout << "1. Rupiah ke Dolar AS\n";
                    cout << "2. Rupiah ke Euro\n";
                    cout << "3. Dolar AS ke Rupiah\n";
                    cout << "4. Dolar AS ke Euro\n";
                    cout << "5. Euro ke Rupiah\n";
                    cout << "6. Euro ke Dolar AS\n";
                    cout << "7. Kembali\n";
                    cout << "Pilih menu (1-7): ";
                    cin >> plh1;

                    switch (plh1){
                        case 1:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Rupiah ke Dolar AS" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Rupiah ke Dolar AS saat ini : 0.000061 \n";
                            cout << "Masukkan nominal Rupiah = ";
                            cin >> IDR;
                            k_IDR_USD = 0.000061 * IDR;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << IDR << " Rupiah ke Dolar AS adalah " << k_IDR_USD << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Rupiah ke Euro" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Rupiah ke Euro saat ini : 0.000056 \n";
                            cout << "Masukkan nominal Rupiah = ";
                            cin >> IDR;
                            k_IDR_EUR = 0.000056 * IDR;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << IDR << " Rupiah ke Euro adalah " << k_IDR_EUR << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Dolar AS ke Rupiah" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Dolar AS ke Rupiah saat ini : 16295.00 \n";
                            cout << "Masukkan nominal Dolar AS = ";
                            cin >> USD;
                            k_USD_IDR = 16295.00 * USD;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << USD << " Dolar AS ke Rupiah adalah " << k_USD_IDR << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Dolar AS ke Euro" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Dolar AS ke Euro saat ini : 0.92 \n";
                            cout << "Masukkan nominal Dolar AS = ";
                            cin >> USD;
                            k_USD_EUR = 0.92 * USD;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << USD << " Dolar AS ke Euro adalah " << k_USD_EUR << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Euro ke Rupiah" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Euro ke Rupiah saat ini : 17654.00 \n";
                            cout << "Masukkan nominal Euro = ";
                            cin >> EUR;
                            k_EUR_IDR = 17654.00 * EUR;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << EUR << " Euro ke Rupiah adalah " << k_EUR_IDR << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Euro ke Dolar AS" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Nilai 1 Euro ke Dolar AS saat ini : 1.08 \n";
                            cout << "Masukkan nominal Euro = ";
                            cin >> EUR;
                            k_EUR_USD = 1.08 * EUR;
                            cout << fixed << setprecision(2);
                            cout << "Hasil konversi " << EUR << " Euro ke Dolar AS adalah " << k_EUR_USD << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 7:
                            kembali = true;
                            break;
                        default:
                            cout << "\nPilihan tidak valid!";
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                    }
                }
            }
            break;

        case 2:
            {
                bool kembali = false;
                while(!kembali){
                    system("cls");
                    cout << "----------------------------------------------------\n";
                    cout << setw(30) << "Menu Konversi Jarak" << endl;
                    cout << "----------------------------------------------------\n";
                    int plh2;
                    float km, m, cm;
                    cout << "1. Kilometer ke Meter\n";
                    cout << "2. Kilometer ke Centimeter\n";
                    cout << "3. Meter ke Kilometer\n";
                    cout << "4. Meter ke Centimeter\n";
                    cout << "5. Centimeter ke Kilometer\n";
                    cout << "6. Centimeter ke Meter\n";
                    cout << "7. Kembali\n";
                    cout << "Pilih menu (1-7): ";
                    cin >> plh2;

                    switch (plh2){
                        case 1:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Kilometer ke Meter" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Kilometer = ";
                            cin >> km;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << km * 1000 << " meter" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Kilometer ke Centimeter" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Kilometer = ";
                            cin >> km;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << km * 100000 << " centimeter" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Meter ke Kilometer" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Meter = ";
                            cin >> m;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << m / 1000 << " kilometer" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Meter ke Centimeter" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Meter = ";
                            cin >> m;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << m * 100 << " centimeter" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Centimeter ke Kilometer" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Centimeter = ";
                            cin >> cm;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << cm / 100000 << " kilometer" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Centimeter ke Meter" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan jarak dalam Centimeter = ";
                            cin >> cm;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(7);
=======
                            cout << fixed << setprecision(2);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << cm / 100 << " meter" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 7:
                            kembali = true;
                            break;
                        default:
                            cout << "\nPilihan tidak valid!";
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                    }
                }
            }
            break;

        case 3:
            {
                bool kembali = false;
                while(!kembali){
                    system("cls");
                    cout << "----------------------------------------------------\n";
                    cout << setw(30) << "Menu Konversi Waktu" << endl;
                    cout << "----------------------------------------------------\n";
                    int plh3;
                    float jam, menit, detik;
                    cout << "1. Jam ke Menit\n";
                    cout << "2. Jam ke Detik\n";
                    cout << "3. Menit ke Jam\n";
                    cout << "4. Menit ke Detik\n";
                    cout << "5. Detik ke Jam\n";
                    cout << "6. Detik ke Menit\n";
                    cout << "7. Kembali\n";
                    cout << "Pilih menu (1-7): ";
                    cin >> plh3;

                    switch (plh3){
                        case 1:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Jam ke Menit" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Jam = ";
                            cin >> jam;
                            cout << "Hasil konversi: " << jam * 60 << " menit" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Jam ke Detik" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Jam = ";
                            cin >> jam;
                            cout << "Hasil konversi: " << jam * 3600 << " detik" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Menit ke Jam" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Menit = ";
                            cin >> menit;
                            cout << "Hasil konversi: " << menit / 60 << " jam" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Menit ke Detik" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Menit = ";
                            cin >> menit;
                            cout << "Hasil konversi: " << menit * 60 << " detik" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Detik ke Jam" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Detik = ";
                            cin >> detik;
                            cout << "Hasil konversi: " << detik / 3600 << " jam" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Detik ke Menit" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan waktu dalam Detik = ";
                            cin >> detik;
                            cout << "Hasil konversi: " << detik / 60 << " menit" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 7:
                            kembali = true;
                            break;
                        default:
                            cout << "\nPilihan tidak valid!";
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                    }
                }
            }
            break;

        case 4:
            {
                bool kembali = false;
                while(!kembali){
                    system("cls");
                    cout << "----------------------------------------------------\n";
                    cout << setw(30) << "Menu Konversi Data Digital" << endl;
                    cout << "----------------------------------------------------\n";
                    int plh4;
                    float bit, byte, kb, mb, gb, tb;
                    cout << "1. Bit ke Byte\n";
                    cout << "2. Byte ke Bit\n";
                    cout << "3. Byte ke Kilobyte\n";
                    cout << "4. Kilobyte ke Byte\n";
                    cout << "5. Kilobyte ke Megabyte\n";
                    cout << "6. Megabyte ke Kilobyte\n";
                    cout << "7. Megabyte ke Gigabyte\n";
                    cout << "8. Gigabyte ke Megabyte\n";
                    cout << "9. Kembali\n";
                    cout << "Pilih menu (1-11): ";
                    cin >> plh4;
                    switch (plh4){
                        case 1:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Bit ke Byte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Bit = ";
                            cin >> bit;
                            cout << "Hasil konversi: " << bit / 8 << " Byte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Byte ke Bit" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Byte = ";
                            cin >> byte;
                            cout << "Hasil konversi: " << byte * 8 << " Bit" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Byte ke Kilobyte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Byte = ";
                            cin >> byte;
                            cout << "Hasil konversi: " << byte / 1024 << " Kilobyte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Kilobyte ke Byte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Kilobyte = ";
                            cin >> kb;
                            cout << "Hasil konversi: " << kb * 1024 << " Byte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 5:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Kilobyte ke Megabyte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Kilobyte = ";
                            cin >> kb;
<<<<<<< HEAD:post-test/posttest-apl-1/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << fixed << setprecision(6);
=======
                            cout << fixed << setprecision(9);
>>>>>>> 99634e7 (ubah):post-test/2409106074-RahmatRiyadi-PT-1.cpp
                            cout << "Hasil konversi: " << kb / 1024 << " Megabyte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Megabyte ke Kilobyte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Megabyte = ";
                            cin >> mb;
                            cout << "Hasil konversi: " << mb * 1024 << " Kilobyte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 7:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Megabyte ke Gigabyte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Megabyte = ";
                            cin >> mb;
                            cout << fixed << setprecision(6);
                            cout << "Hasil konversi: " << mb / 1024 << " Gigabyte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 8:
                            system("cls");
                            cout << "----------------------------------------------------\n";
                            cout << setw(30) << "Konversi Gigabyte ke Megabyte" << endl;
                            cout << "----------------------------------------------------\n";
                            cout << "Masukkan nilai dalam Gigabyte = ";
                            cin >> gb;
                            cout << "Hasil konversi: " << gb * 1024 << " Megabyte" << endl;
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 9:
                            kembali = true;
                            break;
                        default:
                            cout << "\nPilihan tidak valid!";
                            cout << "\nTekan Enter untuk kembali ke menu...";
                            cin.ignore();
                            cin.get();
                            break;
                    }
                }
            }
            break;

        case 5:
            lanjut = false;
            cout << "Terima kasih telah menggunakan program ini!\n";
            cin.ignore();
            cin.get();
            break;
        default:
            cout << "\nPilihan tidak valid!";
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
            break;
        }
    }
    
    return 0;
}