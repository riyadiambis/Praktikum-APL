<<<<<<< HEAD
#include<iostream>
using namespace std;

int main() {
    // Inisialisasi array 3D dengan ukuran 3x3x3
    int angka[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };

    // untuk mengakses angka 17 caranya
    // index : matriks ke, baris, kolom
    cout << angka[1][2][1] << endl;

    return 0;
=======
#include<iostream>
using namespace std;

int main() {
    // Inisialisasi array 3D dengan ukuran 3x3x3
    int angka[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };

    // untuk mengakses angka 17 caranya
    // index : matriks ke, baris, kolom
    cout << angka[1][2][1] << endl;

    return 0;
>>>>>>> ec2900c (tambah kelas)
}