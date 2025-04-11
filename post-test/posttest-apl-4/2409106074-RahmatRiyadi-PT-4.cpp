#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

// Struktur Data Program
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

// Fungsi Dasar
void tungguEnter() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void bersihkanLayar() {
    system("cls");
}

void tampilkanData(Koleksi koleksi) {
    cout << left;
    cout << setw(18) << koleksi.merch.namaKarakter << "| ";
    cout << setw(18) << koleksi.merch.judulAnime << "| ";
    cout << setw(15) << koleksi.merch.genre << "| ";
    cout << setw(30) << koleksi.merch.deskripsi << "| ";
    cout << koleksi.tanggalDitambahkan << "| " << endl;
}

void tampilkanData(Koleksi koleksi, int nomor) {
    cout << left;
    cout << setw(4) << nomor << "| ";
    tampilkanData(koleksi);
}

// Fungsi Pengurutan
void urutkanKoleksi(Koleksi dataKoleksi[], int jumlahKoleksi) {
    for (int i = 0; i < jumlahKoleksi - 1; i++) {
        for (int j = 0; j < jumlahKoleksi - i - 1; j++) {
            if (dataKoleksi[j].merch.namaKarakter > dataKoleksi[j+1].merch.namaKarakter) {
                Koleksi temp = dataKoleksi[j];
                dataKoleksi[j] = dataKoleksi[j+1];
                dataKoleksi[j+1] = temp;
            }
        }
    }
}

int validasiInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (input >= min && input <= max) {
            return input;
        }
        cout << "Input tidak valid! Masukkan angka " << min << "-" << max << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

bool validasiTanggal(string tanggal) {
    if (tanggal.length() != 10 || tanggal[2] != '-' || tanggal[5] != '-') {
        cout << "Format tanggal harus DD-MM-YYYY!" << endl;
        return false;
    }
    int hari = stoi(tanggal.substr(0, 2));
    int bulan = stoi(tanggal.substr(3, 2));
    int tahun = stoi(tanggal.substr(6, 4));
    if (tahun < 1900 || tahun > 2025) {
        cout << "Tahun harus antara 1900-2025!" << endl;
        return false;
    }
    if (bulan < 1 || bulan > 12) {
        cout << "Bulan harus antara 1-12!" << endl;
        return false;
    }
    bool valid = true;
    if (hari < 1 || hari > 31) {
        valid = false;
    } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
        if (hari > 30) valid = false;
    } else if (bulan == 2) {
        if (hari > 29) valid = false;
    }
    if (!valid) {
        cout << "Tanggal tidak valid untuk bulan tersebut!" << endl;
        return false;
    }
    return true;
}

void tampilkanHeader() {
    bersihkanLayar();
    cout << "===========================================" << endl;
    cout << "||                                     ||" << endl;
    cout << "||          MANAJEMEN KOLEKSI          ||" << endl;
    cout << "||          MERCHANDISE ANIME          ||" << endl;
    cout << "||                                     ||" << endl;
    cout << "===========================================" << endl;
    tungguEnter();
}

// Fungsi Menu Utama dan CRUD
void tampilkanMenu() {
    bersihkanLayar();
    cout << "=== MENU UTAMA PROGRAM ===" << endl;
    cout << "1. Lihat Semua Koleksi" << endl;
    cout << "2. Urutkan (A-Z)" << endl;
    cout << "3. Perubahan Koleksi" << endl;
    cout << "4. Tentang Program" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu (0-4): ";
}

void tampilkanMenuCRUD() {
    bersihkanLayar();
    cout << "=== Menu Perubahan Koleksi ===" << endl;
    cout << "1. Lihat Semua Koleksi" << endl;
    cout << "2. Urutkan (A-Z)" << endl;
    cout << "3. Tambah Koleksi" << endl;
    cout << "4. Edit Koleksi" << endl;
    cout << "5. Hapus Koleksi" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Pilih menu (0-5): ";
}

void lihatKoleksi(Koleksi dataKoleksi[], int jumlahKoleksi) {
    bersihkanLayar();
    if (jumlahKoleksi == 0) {
        cout << "Koleksi masih kosong!" << endl;
    } else {
        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < jumlahKoleksi; i++) {
            tampilkanData(dataKoleksi[i], i + 1);
        }
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    }
}

bool loginAdmin(int& percobaan) {
    bool loginBerhasil = false;

    while (percobaan < 3) {
        bersihkanLayar();
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
            if (percobaan < 3) {
                tungguEnter();
            }
        }
    }

    if (!loginBerhasil) {
        cout << "Anda telah melebihi batas percobaan login!" << endl;
        exit(0); 
    }

    return loginBerhasil;
}

// Fungsi Operasi CRUD
void tambahKoleksi(Koleksi dataKoleksi[], int& jumlahKoleksi, const int MAX_KOLEKSI) {
    bersihkanLayar();
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
        
        string tanggal;
        bool tanggalValid = false;
        do {
            cout << "Tanggal (DD-MM-YYYY): ";
            getline(cin, tanggal);
            tanggalValid = validasiTanggal(tanggal);
            if (!tanggalValid) {
                cout << "Silakan coba lagi." << endl;
            }
        } while (!tanggalValid);
        
        dataKoleksi[jumlahKoleksi].tanggalDitambahkan = tanggal;
        jumlahKoleksi++;
        cout << "Koleksi berhasil ditambahkan!" << endl;
    }
}

void editKoleksi(Koleksi dataKoleksi[], int jumlahKoleksi) {
    bersihkanLayar();
    if (jumlahKoleksi == 0) {
        cout << "Daftar koleksi masih kosong!" << endl;
    } else {
        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahKoleksi; i++) {
            tampilkanData(dataKoleksi[i], i + 1);
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
            
            string tanggal;
            bool tanggalValid = false;
            do {
                cout << "Tanggal baru (DD-MM-YYYY): ";
                getline(cin, tanggal);
                tanggalValid = validasiTanggal(tanggal);
                if (!tanggalValid) {
                    cout << "Silakan coba lagi." << endl;
                }
            } while (!tanggalValid);
            dataKoleksi[nomor - 1].tanggalDitambahkan = tanggal;
            
            cout << "Data berhasil diubah!" << endl;
        } else {
            cout << "Nomor tidak valid, cek kembali di menu 'Lihat Koleksi'!" << endl;
        }
    }
}

void hapusKoleksi(Koleksi dataKoleksi[], int& jumlahKoleksi) {
    bersihkanLayar();
    if (jumlahKoleksi == 0) {
        cout << "Koleksi masih kosong!" << endl;
    } else {
        cout << "=== Daftar Koleksi Merchandise Anime ===" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << "No  | Nama Karakter     | Anime             | Genre          | Deskripsi                     | Tanggal   |" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < jumlahKoleksi; i++) {
            tampilkanData(dataKoleksi[i], i + 1);
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
}

void tampilkanInfo() {
    bersihkanLayar();
    cout << "=== Tentang ===" << endl;
    cout << "Program Manajemen Koleksi Merchandise Anime" << endl;
    cout << "Dibuat oleh: Rahmat Riyadi\n\n" << endl;
    cout << "Program yang bertujuan untuk membantu seorang Wibu dalam memanajemen merchandise\nanime yang mereka miliki. Dengan adanya program ini diharapkan seorang wibu dapat\nmenuliskan koleksi yang mereka simpan sehingga memudahkannya untuk diingat.\n\nProgram ini akan dikembangkan lebih lanjut untuk memudahkan para Wibu...\nKami menantikan dukungan anda!\n" << endl;
    cout << "Instagram : @riyadi_ofisharu" << endl;
    cout << "Github : @riyadiambis" << endl;
    cout << "Versi: 1.0" << endl;
}

// Di bagian menu CRUD, kita bisa menggunakan boolean flag
void menuCRUD(Koleksi dataKoleksi[], int& jumlahKoleksi, const int MAX_KOLEKSI) {
    bool kembaliKeMenuUtama = false;
    while (!kembaliKeMenuUtama) {
        tampilkanMenuCRUD();
        int pilih_ubah = validasiInput(0, 5);

        switch (pilih_ubah) {
            case 0:
                kembaliKeMenuUtama = true;
                break;
            case 1:
                lihatKoleksi(dataKoleksi, jumlahKoleksi);
                break;
            case 2:
                bersihkanLayar();
                urutkanKoleksi(dataKoleksi, jumlahKoleksi);
                cout << "Koleksi telah diurutkan berdasarkan nama karakter!" << endl;
                lihatKoleksi(dataKoleksi, jumlahKoleksi); // Tambahkan ini
                break;
            case 3:
                tambahKoleksi(dataKoleksi, jumlahKoleksi, MAX_KOLEKSI);
                break;
            case 4:
                editKoleksi(dataKoleksi, jumlahKoleksi);
                break;
            case 5:
                hapusKoleksi(dataKoleksi, jumlahKoleksi);
                break;
        }
        if (!kembaliKeMenuUtama) {
            tungguEnter();
        }
    }
}

// Program Utama
int main() {
    const int MAX_KOLEKSI = 10;
    Koleksi dataKoleksi[MAX_KOLEKSI];
    int jumlahKoleksi = 8;

    // Data default
    dataKoleksi[0] = {{"Luffy", "One Piece", "Action", "Figure Luffy Gear 5"}, "23-03-2025"};
    dataKoleksi[1] = {{"Naruto", "Naruto Shippuden", "Action", "Figure Naruto Sage Mode"}, "08-03-2024"};
    dataKoleksi[2] = {{"Goku", "Dragon Ball", "Action", "Figure Goku Ultra Instinct"}, "12-07-2021"};
    dataKoleksi[3] = {{"Rem", "Re:Zero", "Fantasy", "Bantal dakimakura Rem"}, "27-06-2021"};
    dataKoleksi[4] = {{"Aqua", "Konosuba", "Comedy", "Figure Aqua menangis"}, "15-11-2024"};
    dataKoleksi[5] = {{"Chika Fujiwara", "Kaguya-sama", "Romance", "Poster Chika dansa"}, "14-09-2024"};
    dataKoleksi[6] = {{"Yor Forger", "Spy x Family", "Action", "Figure Yor belati"}, "02-03-2024"};
    dataKoleksi[7] = {{"Tsukasa Yuzaki", "Tonikaku Kawaii", "Romance", "Figure gaun pengantin"}, "20-12-2024"};

    tampilkanHeader();
    
    while (true) {
        tampilkanMenu();
        int pilihan = validasiInput(0, 4);

        switch (pilihan) {
            case 0:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                return 0;
            case 1:
                lihatKoleksi(dataKoleksi, jumlahKoleksi);
                break;
            case 2:
                bersihkanLayar();
                urutkanKoleksi(dataKoleksi, jumlahKoleksi);
                cout << "Koleksi telah diurutkan berdasarkan nama karakter!" << endl;
                lihatKoleksi(dataKoleksi, jumlahKoleksi);
                break;
            case 3: {
                int percobaan = 0;
                if (loginAdmin(percobaan)) {
                    menuCRUD(dataKoleksi, jumlahKoleksi, MAX_KOLEKSI);
                }
                break;
            }
            case 4:
                tampilkanInfo();
                break;

        }
        tungguEnter();
    }
    return 0;
}