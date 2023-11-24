#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

bool cariData(const vector<string> &data, const string &kata) {
    for (vector<string>::const_iterator it = data.begin(); it != data.end(); ++it) {
        if (*it == kata) {
            return true;
        }
    }
    return false;
}

int main() {
    char jawaban;
    do {
        vector<string> dataArray;

        cout << "=============================================\n";
        cout << "| Masukkan Data dan tekan Enter jika sudah  |\n\n";
        cout << "Data: ";
        string input;
        getline(cin, input);

        istringstream stream(input);
        string token;

        while (stream >> token) {
            if (token == "selesai") {
                break;
            }

            dataArray.push_back(token);
        }

        cout << "---------------------------------------\n";
        string kataDicari;
        cout << "Masukkan data yang ingin dicari: ";
        getline(cin, kataDicari);
        cout << "---------------------------------------\n";

        istringstream searchStream(kataDicari);
        string searchToken;

        while (searchStream >> searchToken) {
            if (searchToken == "selesai") {
                break;
            }

            if (cariData(dataArray, searchToken)) {
                cout << searchToken << " ditemukan pada data.\n";
            } else {
                cout << searchToken << " tidak ditemukan pada data.\n";
            }
        }

        cout << "\nApakah Anda ingin menggunakan program lagi? (y/Y untuk ya, n/N untuk tidak): ";
        cin >> jawaban;
        cin.ignore();

    } while (jawaban == 'y' || jawaban == 'Y');

    cout << "\n===============================================\n";
    cout << "| Terima kasih sudah menggunakan Program Gweh |\n";
    cout << "===============================================\n\n";
    return 0;
}

