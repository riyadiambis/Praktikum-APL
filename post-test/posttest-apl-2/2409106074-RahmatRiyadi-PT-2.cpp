#include<iostream>
#include<limits>
using namespace std;

int main() {
    const int MAX_KOLEKSI = 10;
    const int Panjang_Data = 3;
    const int Lebar_Kolom = 25; 
    //[nama karakter, judul anime, genre]
    string dataKoleksi[MAX_KOLEKSI][Panjang_Data];
    string deskripsi[MAX_KOLEKSI];
    int jumlahKoleksi = 8;

    system("cls");
    cout << "===========================================" << endl;
    cout << "||                                     ||" << endl;
    cout << "||          MANAJEMEN KOLEKSI          ||" << endl;
    cout << "||          MERCHANDISE ANIME          ||" << endl;
    cout << "||                                     ||" << endl;
    cout << "===========================================" << endl;
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();

    // Data Default Merchandise Anime
    dataKoleksi[0][0] = "Luffy"; 
    dataKoleksi[0][1] = "One Piece";
    dataKoleksi[0][2] = "Action";
    deskripsi[0] = "Figure Luffy Gear 5";

    dataKoleksi[1][0] = "Naruto";
    dataKoleksi[1][1] = "Naruto Shippuden";
    dataKoleksi[1][2] = "Action";
    deskripsi[1] = "Figure Naruto Sage Mode";

    dataKoleksi[2][0] = "Goku";
    dataKoleksi[2][1] = "Dragon Ball";
    dataKoleksi[2][2] = "Action";
    deskripsi[2] = "Figure Goku Ultra Instinct";

    dataKoleksi[3][0] = "Rem"; 
    dataKoleksi[3][1] = "Re:Zero";
    dataKoleksi[3][2] = "Fantasy";
    deskripsi[3] = "Bantal dakimakura Rem";

    dataKoleksi[4][0] = "Aqua"; 
    dataKoleksi[4][1] = "Konosuba";
    dataKoleksi[4][2] = "Comedy";
    deskripsi[4] = "Figure Aqua menangis";

    dataKoleksi[5][0] = "Chika Fujiwara"; 
    dataKoleksi[5][1] = "Kaguya-sama";
    dataKoleksi[5][2] = "Romance";
    deskripsi[5] = "Poster Chika dansa";

    dataKoleksi[6][0] = "Yor Forger"; 
    dataKoleksi[6][1] = "Spy x Family";
    dataKoleksi[6][2] = "Action";
    deskripsi[6] = "Figure Yor belati";

    dataKoleksi[7][0] = "Tsukasa Yuzaki"; 
    dataKoleksi[7][1] = "Tonikaku Kawaii";
    dataKoleksi[7][2] = "Romance";
    deskripsi[7] = "Figure gaun pengantin";


    while (true) {
        system("cls");
        cout << "=== MENU UTAMA PROGRAM ===" << endl;
        cout << "1. Lihat Koleksi" << endl;
        cout << "2. Perubahan Koleksi" << endl;
        cout << "3. Tentang Program" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";

        int pilihan;
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!" << endl;
            system("pause");
            continue;
        }

        // Menu Melihat Koleksi
        if (pilihan == 1) {
            system("cls");
            if (jumlahKoleksi == 0) {
                cout << "Koleksi masih kosong!" << endl;
            } else {
            cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            cout << "No  | Nama Karakter            | Anime                    | Genre                    | Deskripsi" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < jumlahKoleksi; i++) {
                cout << i + 1 << "   | ";
                cout << dataKoleksi[i][0] << string(Lebar_Kolom - dataKoleksi[i][0].length(), ' ') << "| ";
                cout << dataKoleksi[i][1] << string(Lebar_Kolom - dataKoleksi[i][1].length(), ' ') << "| ";
                cout << dataKoleksi[i][2] << string(Lebar_Kolom - dataKoleksi[i][2].length(), ' ') << "| ";
                cout << deskripsi[i] << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
        // Menu Merubah Isi Koleksi Merch
        else if (pilihan == 2) {
            int percobaan = 0;
            bool loginBerhasil = false;
            
            while (percobaan < 3) {
                system("cls");
                cout << "=== Verifikasi Akses ===" << endl;
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (username == "rahmatriyadi" && password == "2409106074") {
                    loginBerhasil = true;
                    break;
                } else {
                    percobaan++;
                    cout << "Login gagal! Sisa percobaan: " << 3 - percobaan << endl;
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                }
            }

            if (!loginBerhasil) {
                cout << "Anda telah melebihi batas percobaan login!" << endl;
                system("pause");
                return 0;
            }

            // Menu untuk pengguna melakukan CRUD
            while (true) {
                system("cls");
                cout << "=== Menu Perubahan Koleksi ===" << endl;
                cout << "1. Lihat Koleksi" << endl;
                cout << "2. Tambah Koleksi" << endl;
                cout << "3. Edit Koleksi" << endl;
                cout << "4. Hapus Koleksi" << endl;
                cout << "5. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu (1-5): ";

                int pilih_ubah;
                cin >> pilih_ubah;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid!" << endl;
                    system("pause");
                    continue;
                }

                if (pilih_ubah == 1) {
                    system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Koleksi masih kosong!" << endl;
                    } else {
                        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
                        cout << "No  | Nama Karakter            | Anime                    | Genre                    | Deskripsi" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
                        
                        for (int i = 0; i < jumlahKoleksi; i++) {
                            cout << i + 1 << "   | ";
                            cout << dataKoleksi[i][0] << string(Lebar_Kolom - dataKoleksi[i][0].length(), ' ') << "| ";
                            cout << dataKoleksi[i][1] << string(Lebar_Kolom - dataKoleksi[i][1].length(), ' ') << "| ";
                            cout << dataKoleksi[i][2] << string(Lebar_Kolom - dataKoleksi[i][2].length(), ' ') << "| ";
                            cout << deskripsi[i] << endl;
                        }
                        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
                    }
                }
                
                else if (pilih_ubah == 2) {
                    system("cls");
                    if (jumlahKoleksi >= MAX_KOLEKSI) {
                        cout << "Daftar koleksi sudah penuh!" << endl;
                    } else {
                        cin.ignore();
                        cout << "Nama Karakter: ";
                        getline(cin, dataKoleksi[jumlahKoleksi][0]);
                        cout << "Nama Anime: ";
                        getline(cin, dataKoleksi[jumlahKoleksi][1]);
                        cout << "Genre Anime: ";
                        getline(cin, dataKoleksi[jumlahKoleksi][2]);
                        cout << "Deskripsi: ";
                        getline(cin, deskripsi[jumlahKoleksi]);
                        jumlahKoleksi++;
                        cout << "Koleksi berhasil ditambahkan!" << endl;
                    }
                }
                else if (pilih_ubah == 3) {
                    system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Daftar koleksi masih kosong!" << endl;
                    } else {
                        cout << "Masukkan nomor koleksi yang ingin diedit (1-" << jumlahKoleksi << "): ";
                        int nomor;
                        cin >> nomor;
                        
                        if (nomor >= 1 && nomor <= jumlahKoleksi) {
                            cin.ignore();
                            cout << "Nama Karakter baru: ";
                            getline(cin, dataKoleksi[nomor-1][0]);
                            cout << "Nama Anime baru: ";
                            getline(cin, dataKoleksi[nomor-1][1]);
                            cout << "Genre Anime baru: ";
                            getline(cin, dataKoleksi[nomor-1][2]);
                            cout << "Deskripsi baru: ";
                            getline(cin, deskripsi[nomor-1]);
                            cout << "Data berhasil diubah!" << endl;
                        } else {
                            cout << "Nomor tidak valid, cek kembali di menu 'Lihat Koleksi'!" << endl;
                        }
                    }
                }
                else if (pilih_ubah == 4) {
                    system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Koleksi masih kosong!" << endl;
                    } else {
                        cout << "Masukkan nomor koleksi yang ingin dihapus (1-" << jumlahKoleksi << "): ";
                        int nomor;
                        cin >> nomor;
                        
                        if (nomor >= 1 && nomor <= jumlahKoleksi) {
                            for (int i = nomor-1; i < jumlahKoleksi-1; i++) {
                                dataKoleksi[i][0] = dataKoleksi[i+1][0];
                                dataKoleksi[i][1] = dataKoleksi[i+1][1];
                                dataKoleksi[i][2] = dataKoleksi[i+1][2];
                                deskripsi[i] = deskripsi[i+1];
                            }
                            jumlahKoleksi--;
                            cout << "Data berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor tidak valid, cek kembali di menu 'Lihat Koleksi'!" << endl;
                        }
                    }
                }
                else if (pilih_ubah == 5) {
                    break;
                }
                else {
                    cout << "Pilihan tidak valid!" << endl;
                }
                system("pause");
            }
        }
        // Menu Informasi
        else if (pilihan == 3) {
            system("cls");
            cout << "=== About ===" << endl;
            cout << "Program Manajemen Koleksi Merchandise Anime" << endl;
            cout << "Dibuat oleh: Rahmat Riyadi\n\n" << endl;
            cout << "Program yang bertujuan untuk membantu seorang Wibu dalam memanajemen merchandise\nanime yang mereka miliki. Dengan adanya program ini diharapkan seorang wibu dapat\nmenuliskan koleksi yang mereka simpan sehingga memudahkannya untuk diingat.\n\nProgram ini akan dikembangkan lebih lanjut untuk memudahkan para Wibu...\nKami menantikan dukungan anda!\n" << endl;
            cout << "Instagram : @riyadi_ofisharu" << endl;
            cout << "Github : @riyadiambis" << endl;
            cout << "Versi: 1.0" << endl;
        }
        else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    return 0;
}