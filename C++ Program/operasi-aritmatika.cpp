#include <iostream>
#include <string>
using namespace std;
int main() {
  int num1, num2;
  char op;
  char choice;
  
  cout << "Masukkan angka pertama: ";
  cin >> num1;
  cout << "Masukkan operator matematikanya (+, -, *, /, %): ";
  cin >> op;
  cout << "Masukkan angka kedua: ";
  cin >> num2;
  
  double result;
  
  switch (op) {
    case '+':
      	result = num1 + num2;
      	break;
    case '-':
      	result = num1 - num2;
      	break;
    case '*':
      	result = num1 * num2;
      	break;
    case '/':
      	if (num2 == 0) {
        	cout << "Error: division by 0" << endl;
        	return 1;
      	}
      	result = num1 / num2;
      	break;
    case '%':
    	if (num2 == 0) {
        	cout << "Error: modulus by 0" << endl;
        	return 1;
      	}
    	result = num1 % num2;
    	break;
    default:
      	cout << "Operator Salah" << endl;
      	return 1;
  }
  
  cout << "Hasil dari " << num1 << " " << op << " " << num2 << " adalah " << result << endl;
  cout << "Apakah anda ingin menghitung lagi? (Y/N) ";
  cin >> choice;
  
  if (choice == 'Y' || choice == 'y') {
    main();
  } else if (choice == 'N' || choice == 'n') {
    return 0;
  } else {
    cout << "Pilihan Kurang Tepat" << endl;
    return 0;
  }
}
