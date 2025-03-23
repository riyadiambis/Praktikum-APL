#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

int main() {
    const int MAX_KOLEKSI = 10;
    const int Lebar_Kolom = 30;

    struct Merchandise {
        string namaKarakter;
        string judulAnime;
        string genre;
        string deskripsi;
    };

    struct Koleksi {
        Merchandise merch;
        string tanggalDitambahkan;
    };

    Koleksi dataKoleksi[MAX_KOLEKSI];
    int jumlahKoleksi = 8;

    //system("cls");
    cout << "===========================================" << endl;
    cout << "||                                     ||" << endl;
    cout << "||          MANAJEMEN KOLEKSI          ||" << endl;
    cout << "||          MERCHANDISE ANIME          ||" << endl;
    cout << "||                                     ||" << endl;
    cout << "===========================================" << endl;
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();

    // Data Default Merchandise Anime
    dataKoleksi[0] = {{"Luffy", "One Piece", "Action", "Figure Luffy Gear 5"}, "23-03-2025"};
    dataKoleksi[1] = {{"Naruto", "Naruto Shippuden", "Action", "Figure Naruto Sage Mode"}, "08-03-2024"};
    dataKoleksi[2] = {{"Goku", "Dragon Ball", "Action", "Figure Goku Ultra Instinct"}, "12-07-2021"};
    dataKoleksi[3] = {{"Rem", "Re:Zero", "Fantasy", "Bantal dakimakura Rem"}, "27-06-2021"};
    dataKoleksi[4] = {{"Aqua", "Konosuba", "Comedy", "Figure Aqua menangis"}, "15-11-2024"};
    dataKoleksi[5] = {{"Chika Fujiwara", "Kaguya-sama", "Romance", "Poster Chika dansa"}, "14-09-2024"};
    dataKoleksi[6] = {{"Yor Forger", "Spy x Family", "Action", "Figure Yor belati"}, "02-03-2024"};
    dataKoleksi[7] = {{"Tsukasa Yuzaki", "Tonikaku Kawaii", "Romance", "Figure gaun pengantin"}, "20-12-2024"};

    while (true) {
        //system("cls");
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
            //system("cls");
            if (jumlahKoleksi == 0) {
                cout << "Koleksi masih kosong!" << endl;
            } else {
                // Menampilkan tabel
                cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
                cout << "----------------------------------------------------------------------------------------------------------" << endl;
                cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
                cout << "----------------------------------------------------------------------------------------------------------" << endl;

                for (int i = 0; i < jumlahKoleksi; i++) {
                    cout << left; 
                    cout << setw(4) << i + 1 << "| "; 
                    cout << setw(18) << dataKoleksi[i].merch.namaKarakter << "| "; 
                    cout << setw(18) << dataKoleksi[i].merch.judulAnime << "| "; 
                    cout << setw(15) << dataKoleksi[i].merch.genre << "| "; 
                    cout << setw(30) << dataKoleksi[i].merch.deskripsi << "| "; 
                    cout << dataKoleksi[i].tanggalDitambahkan << "| " << endl; 
                }
                cout << "----------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        // Menu Merubah Isi Koleksi Merch
        else if (pilihan == 2) {
            int percobaan = 0;
            bool loginBerhasil = false;

            while (percobaan < 3) {
                //system("cls");
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
                //system("cls");
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
                    //system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Koleksi masih kosong!" << endl;
                    } else {
                        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        
                        for (int i = 0; i < jumlahKoleksi; i++) {
                            cout << left; 
                            cout << setw(4) << i + 1 << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.namaKarakter << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.judulAnime << "| "; 
                            cout << setw(15) << dataKoleksi[i].merch.genre << "| "; 
                            cout << setw(30) << dataKoleksi[i].merch.deskripsi << "| "; 
                            cout << dataKoleksi[i].tanggalDitambahkan << "| " << endl; 
                        }
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                    }
                } else if (pilih_ubah == 2) {
                    //system("cls");
                    if (jumlahKoleksi >= MAX_KOLEKSI) {
                        cout << "Daftar koleksi sudah penuh!" << endl;
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Nama Karakter: ";
                        getline(cin, dataKoleksi[jumlahKoleksi].merch.namaKarakter);
                        cout << "Nama Anime: ";
                        getline(cin, dataKoleksi[jumlahKoleksi].merch.judulAnime);
                        cout << "Genre Anime: ";
                        getline(cin, dataKoleksi[jumlahKoleksi].merch.genre);
                        cout << "Deskripsi: ";
                        getline(cin, dataKoleksi[jumlahKoleksi].merch.deskripsi);
                        cout << "Tanggal (DD-MM-YYYY): ";
                        getline(cin, dataKoleksi[jumlahKoleksi].tanggalDitambahkan);
                        jumlahKoleksi++;
                        cout << "Koleksi berhasil ditambahkan!" << endl;
                    }
                } else if (pilih_ubah == 3) {
                    //system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Daftar koleksi masih kosong!" << endl;
                    } else {
                        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        
                        for (int i = 0; i < jumlahKoleksi; i++) {
                            cout << left; 
                            cout << setw(4) << i + 1 << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.namaKarakter << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.judulAnime << "| "; 
                            cout << setw(15) << dataKoleksi[i].merch.genre << "| "; 
                            cout << setw(30) << dataKoleksi[i].merch.deskripsi << "| "; 
                            cout << dataKoleksi[i].tanggalDitambahkan << "| " << endl; 
                        }
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                        cout << "Masukkan nomor koleksi yang ingin diedit (1-" << jumlahKoleksi << "): ";
                        int nomor;
                        cin >> nomor;

                        if (nomor >= 1 && nomor <= jumlahKoleksi) {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Nama Karakter baru: ";
                            getline(cin, dataKoleksi[nomor - 1].merch.namaKarakter);
                            cout << "Nama Anime baru: ";
                            getline(cin, dataKoleksi[nomor - 1].merch.judulAnime);
                            cout << "Genre Anime baru: ";
                            getline(cin, dataKoleksi[nomor - 1].merch.genre);
                            cout << "Deskripsi baru: ";
                            getline(cin, dataKoleksi[nomor - 1].merch.deskripsi);
                            cout << "Tanggal baru (DD-MM-YYYY): ";
                            getline(cin, dataKoleksi[nomor - 1].tanggalDitambahkan);
                            cout << "Data berhasil diubah!" << endl;
                        } else {
                            cout << "Nomor tidak valid, cek kembali di menu 'Lihat Koleksi'!" << endl;
                        }
                    }
                } else if (pilih_ubah == 4) {
                    //system("cls");
                    if (jumlahKoleksi == 0) {
                        cout << "Koleksi masih kosong!" << endl;
                    } else {
                        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        
                        for (int i = 0; i < jumlahKoleksi; i++) {
                            cout << left; 
                            cout << setw(4) << i + 1 << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.namaKarakter << "| "; 
                            cout << setw(18) << dataKoleksi[i].merch.judulAnime << "| "; 
                            cout << setw(15) << dataKoleksi[i].merch.genre << "| "; 
                            cout << setw(30) << dataKoleksi[i].merch.deskripsi << "| "; 
                            cout << dataKoleksi[i].tanggalDitambahkan << "| " << endl; 
                        }
                        cout << "----------------------------------------------------------------------------------------------------------" << endl;
                        cout << "Masukkan nomor koleksi yang ingin dihapus (1-" << jumlahKoleksi << "): ";
                        int nomor;
                        cin >> nomor;

                        if (nomor >= 1 && nomor <= jumlahKoleksi) {
                            for (int i = nomor - 1; i < jumlahKoleksi - 1; i++) {
                                dataKoleksi[i] = dataKoleksi[i + 1];
                            }
                            jumlahKoleksi--;
                            cout << "Data berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor tidak valid, cek kembali di menu 'Lihat Koleksi'!" << endl;
                        }
                    }
                } else if (pilih_ubah == 5) {
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
                system("pause");
            }
        }
        // Menu Informasi
        else if (pilihan == 3) {
            //system("cls");
            cout << "=== Tantang ===" << endl;
            cout << "Program Manajemen Koleksi Merchandise Anime" << endl;
            cout << "Dibuat oleh: Rahmat Riyadi\n\n" << endl;
            cout << "Program yang bertujuan untuk membantu seorang Wibu dalam memanajemen merchandise\nanime yang mereka miliki. Dengan adanya program ini diharapkan seorang wibu dapat\nmenuliskan koleksi yang mereka simpan sehingga memudahkannya untuk diingat.\n\nProgram ini akan dikembangkan lebih lanjut untuk memudahkan para Wibu...\nKami menantikan dukungan anda!\n" << endl;
            cout << "Instagram : @riyadi_ofisharu" << endl;
            cout << "Github : @riyadiambis" << endl;
            cout << "Versi: 1.0" << endl;
        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        } else {
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