#include "headers/accounts/main.hpp"
#include <iostream>

using namespace std;

int main() {
  Account acc;
  acc.holder_name = "Andre";
  acc.holder_soc_sec_number = "123.456.789-00";
  acc.amount = 1000;

  Account acc2;
  acc2.holder_name = "Joao";
  acc2.holder_soc_sec_number = "987.654.321-00";
  acc2.amount = 500;

  if (transfer(acc, acc2, 250)) {
    cout << "Transfer successful" << endl;
    cout << "Account holder " << acc2.holder_name
         << " received 250 dollars from " << acc.holder_name << endl;
  } else {
    cout << "Transfer failed" << endl;
  }

  if (transfer(acc2, acc, 800)) {
    cout << "Transfer successful" << endl;
    cout << "Account holder " << acc.holder_name
         << " received 800 dollars from " << acc2.holder_name << endl;
  } else {
    cout << "Transfer failed" << endl;
  }

  return 0;
}
