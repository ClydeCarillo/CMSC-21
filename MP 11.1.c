/* 2024-02813
   Bolando, Karylle Mirzi
   Machine Problem #11.1: Hexadecimal or Not? (C++ Edition)
   Date Due: May 23, 2025 
   
   This one is badly graded...
   
   */

#include <iostream>
#include <string>
using namespace std;

class HexChecker {
private:
    string str;

public:
    void getInput() {
        cout << "Enter a string: ";
        cin >> str;
    }

    bool isHexadecimal() {
        for (char c : str) {
            if (!((c >= '0' && c <= '9') ||
                  (c >= 'A' && c <= 'F') ||
                  (c >= 'a' && c <= 'f'))) {
                return false;
            }
        }
        return true;
    }

    void showResult() {
        if (isHexadecimal()) {
            cout << "HEXADECIMAL!" << endl;
        } else {
            cout << "NOT HEXADECIMAL!" << endl;
        }
    }
};

int main() {
    HexChecker checker;
    checker.getInput();
    checker.showResult();
    return 0;
}
