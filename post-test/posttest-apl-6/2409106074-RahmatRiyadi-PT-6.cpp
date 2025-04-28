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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

// Fungsi Menu Utama, Sort dan CRUD
void tampilkanMenuUtama() {
    bersihkanLayar();
    cout << "=== MENU UTAMA ===" << endl;
    cout << "1. Tampilkan Koleksi" << endl;
    cout << "2. Perubahan Data Koleksi" << endl;
    cout << "3. Tentang Program" << endl;
    cout << "4. Logout" << endl;
    cout << "Pilih menu (1-4): ";
}

void tampilkanMenuCRUD() {
    bersihkanLayar();
    cout << "=== Menu Perubahan Koleksi ===" << endl;
    cout << "1. Lihat Semua Koleksi" << endl;
    cout << "2. Tambah Koleksi" << endl;
    cout << "3. Edit Koleksi" << endl;
    cout << "4. Hapus Koleksi" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Pilih menu (0-4): ";
}

void tampilkanMenuTampilData() {
    bersihkanLayar();
    cout << "=== Menu Tampilkan Data Koleksi ===" << endl;
    cout << "1. Urutkan Nama Karakter (A-Z)" << endl;
    cout << "2. Urutkan Judul Anime (Z-A)" << endl;
    cout << "3. Urutkan Genre Anime (Z-A)" << endl;
    cout << "4. Urutkan Tahun Input Data" << endl;
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
        cout << left;
        cout << setw(4) << "No" << "| ";
        cout << setw(18) << "Nama Karakter" << "| ";
        cout << setw(18) << "Anime" << "| ";
        cout << setw(15) << "Genre" << "| ";
        cout << setw(30) << "Deskripsi" << "| ";
        cout << "Tanggal" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < jumlahKoleksi; i++) {
            tampilkanData(dataKoleksi[i], i + 1);
        }
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    }
}

bool loginKonfir(int& percobaan) {
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
        Koleksi *pointerKeKoleksi = &dataKoleksi[jumlahKoleksi];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nama Karakter: ";
        getline(cin, pointerKeKoleksi->merch.namaKarakter);
        cout << "Nama Anime: ";
        getline(cin, pointerKeKoleksi->merch.judulAnime);
        cout << "Genre Anime: ";
        getline(cin, pointerKeKoleksi->merch.genre);
        cout << "Deskripsi: ";
        getline(cin, pointerKeKoleksi->merch.deskripsi);
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
        pointerKeKoleksi->tanggalDitambahkan = tanggal;
        jumlahKoleksi++;
        cout << "Koleksi berhasil ditambahkan!" << endl;
    }
}

void editDeskripsiPointer(string *deskripsi) {
    cout << "Masukkan deskripsi baru: ";
    cin.ignore();
    getline(cin, *deskripsi);
}

void editKoleksi(Koleksi &itemKoleksi) { 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nama Karakter baru: ";
    getline(cin, itemKoleksi.merch.namaKarakter);
    cout << "Nama Anime baru: ";
    getline(cin, itemKoleksi.merch.judulAnime);
    cout << "Genre Anime baru: ";
    getline(cin, itemKoleksi.merch.genre);
    cout << "Deskripsi baru: ";
    getline(cin, itemKoleksi.merch.deskripsi);
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
    itemKoleksi.tanggalDitambahkan = tanggal;
    cout << "Data berhasil diubah!" << endl;
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
            Koleksi *ptr = &dataKoleksi[nomor - 1];
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
    cout << "Dibuat oleh: Rahmat Riyadi\n" << endl;
    cout << "Program ini bertujuan membantu seorang wibu dalam mengelola koleksi merchandise anime mereka," << endl;
    cout << "seperti figure, poster, dan barang-barang bertema karakter anime favorit." << endl;
    cout << "Fitur yang tersedia meliputi:" << endl;
    cout << "- Melihat daftar koleksi" << endl;
    cout << "- Menambahkan koleksi baru" << endl;
    cout << "- Mengedit data koleksi" << endl;
    cout << "- Menghapus koleksi" << endl;
    cout << "\nSemoga program ini bermanfaat! Tetap semangat koleksi waifu dan husbando kalian!" << endl;
    cout << endl;
    cout << "Dukung Saya di :" << endl;
    cout << "Instagram : @riyadi_ofisharu" << endl;
    cout << "Github : @riyadiambis" << endl;
    cout << "Versi: 2.2" << endl;
    cout << "Apa yang baru :" << endl;
    cout << "Pengurutan merchandise kini tersedia lebih banyak pilihan" << endl;
}

void menuCRUD(Koleksi dataKoleksi[], int& jumlahKoleksi, const int MAX_KOLEKSI) {
    bool kembaliKeMenuUtama = false;
    while (!kembaliKeMenuUtama) {
        tampilkanMenuCRUD();
        int pilih_ubah = validasiInput(0, 4);

        switch (pilih_ubah) {
            case 0:
                kembaliKeMenuUtama = true;
                break;
            case 1:
                lihatKoleksi(dataKoleksi, jumlahKoleksi);
                break;
            case 2:
                tambahKoleksi(dataKoleksi, jumlahKoleksi, MAX_KOLEKSI);
                break;
            case 3: {
                bersihkanLayar();
                if (jumlahKoleksi == 0) {
                    cout << "Daftar koleksi masih kosong!" << endl;
                } else {
                    lihatKoleksi(dataKoleksi, jumlahKoleksi);
                    cout << "Masukkan nomor koleksi yang ingin diedit (1-" << jumlahKoleksi << "): ";
                    int nomor = validasiInput(1, jumlahKoleksi);
                    editKoleksi(dataKoleksi[nomor - 1]);
                }
                break;
            }
            case 4:
                hapusKoleksi(dataKoleksi, jumlahKoleksi);
                break;
        }
        if (!kembaliKeMenuUtama) {
            tungguEnter();
        }
    }
}

void bubbleSortNamaKarakter(Koleksi arr[], int jumlahKoleksi) {
    for (int i = 0; i < jumlahKoleksi - 1; i++) {
        for (int j = 0; j < jumlahKoleksi - i - 1; j++) {
            Koleksi *ptr1 = &arr[j];
            Koleksi *ptr2 = &arr[j + 1];
            if (ptr1->merch.namaKarakter > ptr2->merch.namaKarakter) {
                Koleksi temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
        }
    }
}

void insertionSortAnimeDesc(Koleksi arr[], int jumlahKoleksi) {
    for (int i = 1; i < jumlahKoleksi; i++) {
        Koleksi key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].merch.judulAnime < key.merch.judulAnime) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSortGenreDesc(Koleksi arr[], int jumlahKoleksi) {
    for (int i = 0; i < jumlahKoleksi - 1; i++) {
        int max = i;
        for (int j = i + 1; j < jumlahKoleksi; j++) {
            if (arr[j].merch.genre > arr[max].merch.genre) {
                max = j;
            }
        }
        Koleksi temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int konversiTanggalKeInteger(string tanggal) {
    int hari = 0, bulan = 0, tahun = 0;
    hari = (tanggal[0] - '0') * 10 + (tanggal[1] - '0');
    bulan = (tanggal[3] - '0') * 10 + (tanggal[4] - '0');
    tahun = (tanggal[6] - '0') * 1000 +
            (tanggal[7] - '0') * 100 +
            (tanggal[8] - '0') * 10 +
            (tanggal[9] - '0');
    return tahun * 10000 + bulan * 100 + hari;
}

void merge(Koleksi arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Koleksi L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (konversiTanggalKeInteger(L[i].tanggalDitambahkan) <= konversiTanggalKeInteger(R[j].tanggalDitambahkan)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortTanggal(Koleksi arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortTanggal(arr, l, m);
        mergeSortTanggal(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void menuTampilData(Koleksi dataKoleksi[], int jumlahKoleksi) {
    Koleksi salinanKoleksi[jumlahKoleksi];
    bool kembali = false;
    while (!kembali) {
        tampilkanMenuTampilData();
        int pilihan = validasiInput(0, 5);

        for (int i = 0; i < jumlahKoleksi; i++) {
            salinanKoleksi[i] = dataKoleksi[i];
        }

        switch (pilihan) {
            case 0:
                kembali = true;
                break;
            case 1:
                bubbleSortNamaKarakter(salinanKoleksi, jumlahKoleksi);
                lihatKoleksi(salinanKoleksi, jumlahKoleksi);
                break;
            case 2:
                insertionSortAnimeDesc(salinanKoleksi, jumlahKoleksi);
                lihatKoleksi(salinanKoleksi, jumlahKoleksi);
                break;
            case 3:
                selectionSortGenreDesc(salinanKoleksi, jumlahKoleksi);  
                lihatKoleksi(salinanKoleksi, jumlahKoleksi);
                break;
            case 4:
                mergeSortTanggal(salinanKoleksi, 0, jumlahKoleksi - 1);
                lihatKoleksi(salinanKoleksi, jumlahKoleksi);
                break;
        }
        if (!kembali) tungguEnter();
    }
}

// Program Utama
int main() {
    const int MAX_KOLEKSI = 25;
    Koleksi dataKoleksi[MAX_KOLEKSI];
    int jumlahKoleksi = 23;

    // Data default
    dataKoleksi[0] = {{"Luffy", "One Piece", "Action", "Figure Luffy Gear 5"}, "23-03-2025"};
    dataKoleksi[1] = {{"Naruto", "Naruto Shippuden", "Action", "Figure Naruto Sage Mode"}, "08-03-2024"};
    dataKoleksi[2] = {{"Goku", "Dragon Ball", "Action", "Figure Goku Ultra Instinct"}, "12-07-2021"};
    dataKoleksi[3] = {{"Rem", "Re:Zero", "Fantasy", "Bantal dakimakura Rem"}, "27-06-2021"};
    dataKoleksi[4] = {{"Aqua", "Konosuba", "Comedy", "Figure Aqua menangis"}, "15-11-2024"};
    dataKoleksi[5] = {{"Chika Fujiwara", "Kaguya-sama", "Romance", "Poster Chika dansa"}, "14-09-2024"};
    dataKoleksi[6] = {{"Yor Forger", "Spy x Family", "Action", "Figure Yor belati"}, "02-03-2024"};
    dataKoleksi[7] = {{"Tsukasa Yuzaki", "Tonikaku Kawaii", "Romance", "Figure gaun pengantin"}, "20-12-2024"};
    dataKoleksi[8] = {{"Levi Ackerman", "Attack on Titan", "Action", "Figure Levi bersama pedang"}, "12-05-2023"};
    dataKoleksi[9] = {{"Mikasa Ackerman", "Attack on Titan", "Action", "Figure Mikasa syal merah"}, "14-07-2022"};
    dataKoleksi[10] = {{"Eren Yeager", "Attack on Titan", "Action", "Figure Eren Titan Mode"}, "19-09-2023"};
    dataKoleksi[11] = {{"Sakura Kinomoto", "Cardcaptor Sakura", "Fantasy", "Baju Cosplay Sakura"}, "05-04-2021"};
    dataKoleksi[12] = {{"Ichigo Kurosaki", "Bleach", "Action", "Figure Ichigo Zangetsu mode"}, "22-11-2022"};
    dataKoleksi[13] = {{"Rukia Kuchiki", "Bleach", "Action", "Figure Rukia Chappy Bunny"}, "18-06-2021"};
    dataKoleksi[14] = {{"Natsu Dragneel", "Fairy Tail", "Action", "Figure Natsu Fire Dragon mode"}, "30-08-2023"};
    dataKoleksi[15] = {{"Lucy Heartfilia", "Fairy Tail", "Fantasy", "Figure Lucy kunci bintang"}, "10-02-2022"};
    dataKoleksi[16] = {{"Zero Two", "Darling", "Romance", "Zero Two sayap merah"}, "03-01-2024"};
    dataKoleksi[17] = {{"Hinata Shoyo", "Haikyuu!!", "Sports", "Figure Hinata spike pose"}, "25-03-2023"};
    dataKoleksi[18] = {{"Kageyama Tobio", "Haikyuu!!", "Sports", "Figure Kageyama serve pose"}, "17-05-2022"};
    dataKoleksi[19] = {{"Gon Freecss", "Hunter x Hunter", "Adventure", "Figure Gon Nen mode"}, "09-12-2021"};
    dataKoleksi[20] = {{"Killua Zoldyck", "Hunter x Hunter", "Adventure", "Figure Killua skateboard mode"}, "28-02-2023"};
    dataKoleksi[21] = {{"Lelouch Lamperouge", "Code Geass", "Strategy", "Figure Lelouch Zero mask"}, "15-08-2022"};
    dataKoleksi[22] = {{"C.C.", "Code Geass", "Strategy", "Figure C.C. dengan pizza"}, "07-10-2023"};

    tampilkanHeader();
    
    while (true) {
        tampilkanMenuUtama();
        int pilihan = validasiInput(1, 4);

        switch (pilihan) {
            case 1:
                menuTampilData(dataKoleksi, jumlahKoleksi);
                break;
            case 2: {
                int percobaan = 0;
                if (loginKonfir(percobaan)) {
                    menuCRUD(dataKoleksi, jumlahKoleksi, MAX_KOLEKSI);
                }
                break;
            }
            case 3:
                tampilkanInfo();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                return 0;
        }
        if (pilihan != 1) tungguEnter();
    }
    return 0;
}