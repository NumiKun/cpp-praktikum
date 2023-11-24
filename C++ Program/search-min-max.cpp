#include <iostream>
using namespace std;

int main() {
    int n;
    char choice;
    cout << "*******************************\n";
    cout << "Masukkan Jumlah Deret Data: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah data harus lebih dari 0." << endl;
        return 1;
    }

    int data, smallest, largest;

	cout << "---------------------- \n";
    cout << "| Masukkan data ke-1: ";
    cin >> data;
    smallest = data;
    largest = data;

    for (int i = 2; i <= n; i++) {
    	cout << "---------------------- \n";
        cout << "| Masukkan data ke-" << i << ": ";
        cin >> data;

        if (data < smallest) {
            smallest = data;
        }

        if (data > largest) {
            largest = data;
        }
    }

	cout << "---------------------- \n";
    cout << "\n->Nilai terkecilnya adalah " << smallest << endl;
    cout << "->Nilai terbesarnya adalah " << largest << endl;

  	cout << "Apakah anda ingin mencari nilai min dan max lagi? (Y/N) ";
  	cin >> choice;
  
  	if (choice == 'Y' || choice == 'y') {
    	main();
  	} else if (choice == 'N' || choice == 'n') {
    	return 0;
  	} else {
    	cout << "Pilihan Kurang Tepat" << endl;
    	return 0;
  	}
    return 0;
}

