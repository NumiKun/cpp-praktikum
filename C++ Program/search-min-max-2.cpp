#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    vector<int> data;
    string input;

    cout << "Masukkan data (pisahkan dengan koma, tekan Enter 2x untuk mengakhiri):\n";

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }

        stringstream ss(input);
        int number;
        while (ss >> number) {
            data.push_back(number);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
    }

    if (data.empty()) {
        cout << "Tidak ada data yang dimasukkan." << endl;
    } else {
        int smallest = numeric_limits<int>::max();
        int largest = numeric_limits<int>::min();

        for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
            if (*it < smallest) {
                smallest = *it;
            }

            if (*it > largest) {
                largest = *it;
            }
        }

        cout << "Nilai terkecil: " << smallest << endl;
        cout << "Nilai terbesar: " << largest << endl;
    }
    return 0;
}
