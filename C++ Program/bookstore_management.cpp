#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;

// Struktur untuk merepresentasikan data buku
struct Buku {
    string judul;
    string penulis;
    int tahun;
};

// Database buku dalam bentuk vector
vector<Buku> books;

// Autentikasi 
const string USERNAME = "rizki";
const string PASSWORD = "1234";

string getPasswordInput() {
    string password = "";
    char ch;
    while ((ch = _getch()) != 13) { // Ketika tombol Enter ditekan
        if (ch == 8 && password.length() > 0) { // Jika tombol Backspace ditekan dan password tidak kosong
            cout << "\b \b"; // Hapus karakter dari layar
            password = password.substr(0, password.length() - 1); // Hapus karakter terakhir dari string password
        } else if (ch != 8) {
            password.push_back(ch); // Tambahkan karakter ke string password
            cout << '*'; // Tampilkan * sebagai pengganti karakter yang dimasukkan
        }
    }
    cout << endl; // Pindah ke baris berikutnya setelah selesai memasukkan password
    return password;
}

// Fungsi untuk menambah buku ke dalam database
void tambahBuku() {
    string username, password;
    cout << "Anda memerlukan akses untuk memilih opsi ini!" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    password = getPasswordInput();

    // Memeriksa autentikasi
    if (username == USERNAME && password == PASSWORD) {
        Buku bukuBaru;
        cout << "------------------------------" << endl;
        cout << "-> Masukkan judul buku: ";
        getline(cin >> ws, bukuBaru.judul);
        cout << "-> Masukkan penulis buku: ";
        getline(cin >> ws, bukuBaru.penulis);
        cout << "-> Masukkan tahun terbit buku: ";
        cin >> bukuBaru.tahun;
        books.push_back(bukuBaru);
        cout << "\n------------------------------" << endl;
        cout << "-> Buku berhasil ditambahkan!" << endl;
        cout << "------------------------------\n" << endl;

    } else {
    	cout << "--------------------------------------------" << endl;
        cout << "| AUTENTIKASI GAGAL. GAGAL MENAMBAH BUKU!! |" << endl;
        cout << "--------------------------------------------\n" << endl;
    }
    cout << "\nTekan Enter untuk Kembali ke Menu" << endl;
    _getch();
}

// Fungsi untuk mencari buku berdasarkan judul atau penulis
void cariBuku() {
    string penyimpanan;
    cout << "Masukkan judul atau penulis buku: ";
    getline(cin >> ws, penyimpanan);

    bool found = false;
    
    // Ubah input pencarian ke huruf kecil
    for (size_t i = 0; i < penyimpanan.length(); ++i) {
        penyimpanan[i] = tolower(penyimpanan[i]);
    }
    
    for (size_t i = 0; i < books.size(); ++i) {
        string judul = books[i].judul;
        string penulis = books[i].penulis;

        // Ubah judul dan penulis buku ke huruf kecil
        for (size_t j = 0; j < judul.length(); ++j) {
            judul[j] = tolower(judul[j]);
        }

        for (size_t j = 0; j < penulis.length(); ++j) {
            penulis[j] = tolower(penulis[j]);
        }

        if (judul.find(penyimpanan) != string::npos || penulis.find(penyimpanan) != string::npos) {
        	cout << "--------------------------------------" << endl;
        	cout << "Buku yang ditemukan: " << endl;
            cout << "-> Judul: " << books[i].judul << ", Penulis: " << books[i].penulis << ", Tahun Terbit: " << books[i].tahun << endl;
            found = true;
        }
    }
    cout << "--------------------------------------" << endl;
    
    if (!found) {
        cout << "         Buku tidak ditemukan.        " << endl;
        cout << "--------------------------------------" << endl;
    }
    cout << "\nTekan Enter untuk Kembali ke Menu" << endl;
}

// Fungsi untuk mengedit data buku
void editBuku() {
    string username, password;
    cout << "Anda memerlukan akses untuk memilih opsi ini!" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    password = getPasswordInput();
    
    if (username == USERNAME && password == PASSWORD) {
        string judul;
        cin.ignore(); // Membersihkan newline dari buffer
        cout << "---------------------------------------" << endl;
        cout << "Masukkan judul buku yang ingin diedit: ";
        getline(cin >> ws, judul);

        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].judul == judul) {
                cout << "-> Masukkan judul baru : ";
                getline(cin >> ws, books[i].judul);
                cout << "-> Masukkan penulis baru : ";
                getline(cin >> ws, books[i].penulis);
                cout << "-> Masukkan tahun terbit baru : ";
                cin >> books[i].tahun;
                cout << "\n====== Data buku berhasil diubah ======" << endl;
                cout << "---------------------------------------\n" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
        	cout << "---------------------------------------" << endl;
            cout << "          Buku tidak ditemukan.        " << endl;
            cout << "---------------------------------------\n" << endl;
        }
    } else {
    	cout << "----------------------------------------" << endl;
        cout << "| AUTENTIKASI GAGAL. GAGAL EDIT BUKU!! |" << endl;
        cout << "----------------------------------------\n" << endl;
    }
    cout << "Tekan Enter untuk Kembali ke Menu" << endl;
    _getch();
}

bool bandingkanJudul(const Buku& buku1, const Buku& buku2) {
    return buku1.judul < buku2.judul;
}
// Fungsi untuk menampilkan semua buku yang ada
void tampilkanBuku() {
    if (books.empty()) {
        cout << "Tidak ada buku yang tersedia." << endl;
    } else {
    	sort(books.begin(), books.end(), bandingkanJudul);
    	
        cout << "Daftar Buku:" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            cout << "-> " << "Judul: " << books[i].judul << ", Penulis: " << books[i].penulis << ", Tahun Terbit: " << books[i].tahun << endl;
        }
        cout << "--------------------------------------\n" << endl;
    }
    cout << "Tekan Enter untuk Kembali ke Menu" << endl;
}

// Fungsi untuk menghapus buku berdasarkan judul
void hapusBuku() {
    string username, password;
    cout << "Anda memerlukan akses untuk memilih opsi ini!" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    password = getPasswordInput();

    if (username == USERNAME && password == PASSWORD) {
        string judul;
        cout << "-----------------------------------" << endl;
        cin.ignore(); // Membersihkan newline dari buffer
        cout << "-> Masukkan judul buku yang ingin dihapus: ";
        getline(cin >> ws, judul);

        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].judul == judul) {
                books.erase(books.begin() + i); // Menghapus buku dari vektor berdasarkan indeks
                cout << "-----------------------------------\n" << endl;
                cout << "====== Buku berhasil dihapus ======" << endl;
                cout << "-----------------------------------\n" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
        	cout << "-----------------------------------" << endl;
            cout << "Buku tidak ditemukan." << endl;
            cout << "-----------------------------------\n" << endl;
        }
    } else {
    	cout << "-----------------------------------------" << endl;
        cout << "| AUTENTIKASI GAGAL. GAGAL HAPUS BUKU!! |" << endl;
        cout << "-----------------------------------------\n" << endl;
    }
    cout << "Tekan Enter untuk Kembali ke Menu" << endl;
    _getch();
}

void clear() {
	#ifdef _WIN32
		cin.ignore();
		system("cls");
	#else
		system("clear");
	#endif
}

// Fungsi utama untuk menjalankan program
int main() {
	books.push_back({"Laskar Pelangi", "Andrea Hirata", 2005});
    books.push_back({"Bumi Manusia", "Pramoedya Ananta Toer", 1980});
    books.push_back({"Ayat-ayat Cinta", "Habiburrahman El Shirazy", 2004});
    int pilih;
    do {
        cout << "=== Bookstore Inventory Management ===" << endl;
        cout << "| 1. Tambah Buku                     |" << endl;
        cout << "| 2. Cari Buku                       |" << endl;
        cout << "| 3. Edit Data Buku                  |" << endl;
        cout << "| 4. Tampilkan Semua Buku            |" << endl;
        cout << "| 5. Hapus Buku                      |" << endl;
        cout << "| 6. Exit                            |" << endl;
        cout << "======================================" << endl;

        cout << "Pilih menu (1/2/3/4/5/6): ";
        cin >> pilih;
        clear();
        
        if (cin.fail()) { // Memeriksa apakah input adalah angka
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear(); // Membersihkan status error pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter sampai newline ditemukan
        } else {
            switch (pilih) {
                case 1:
                    tambahBuku();
                    break;
                case 2:
                    cariBuku();
                    break;
                case 3:
                    editBuku();
                    break;
                case 4:
                    tampilkanBuku();
                    break;
                case 5:
    				hapusBuku();
    				break;
                case 6:
                    cout << "Terima kasih telah menggunakan program ini :)" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                    break;
            }
            clear();
        }
    } while (pilih != 6);

    return 0;
}
