#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cout << "----------------------------------------------------\n";
    cout << "| Pilih jenis program:				   |\n";
    cout << "| 1. Mengurutkan angka dari terkecil ke terbesar   |\n";
    cout << "| 2. Mengurutkan kata sesuai abjad		   |\n";
    cout << "| 3. Mengurutkan angka dari terbesar ke terkecil   |\n";
    cout << "----------------------------------------------------\n";

    int choice;
    cout << "Opsi yang dipilih: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Masukkan deret angka yang mau diurutkan (ketik 'a' lalu enter jika sudah):\n";
        vector<int> numbers;
        int num;
        while (cin >> num) {
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());

        cout << "Urutan angka dari terkecil ke terbesar:\n";
        for (int i = 0; i < numbers.size(); ++i) {
            cout << numbers[i] << " ";
        }
    } else if (choice == 2) {
        cout << "Masukkan deret kata yang ingin diurutkan (ketik '1' lalu enter jika sudah):\n";
        vector<string> words;
        string word;
        while (cin >> word && word != "1") {
            words.push_back(word);
        }

        sort(words.begin(), words.end());

        cout << "Hasil pengurutan:\n";
        for (int i = 0; i < words.size(); ++i) {
            cout << words[i] << " ";
        }
    } else if (choice == 3) {
        cout << "Masukkan deret angka yang ingin diurutkan (ketik 'a' lalu enter jika sudah selesai):\n";
        vector<int> numbers;
        int num;
        while (cin >> num) {
            numbers.push_back(num);
        }

        sort(numbers.rbegin(), numbers.rend());  

        cout << "Urutan angka dari terbesar ke terkecil:\n";
        for (int i = 0; i < numbers.size(); ++i) {
            cout << numbers[i] << " ";
        }
    } else {
        cout << "Pilihan tidak valid.\n";
    }
    return 0;
}

