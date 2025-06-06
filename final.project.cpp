/*
2024-02813 - BOLANDO, KARYLLE MIRZI
2024-07137 - RAGASAJO, JEAHNA HARRIET
2024-03648 - VILICARIO, ANJOE
CMSC 21 - E1
Final Project: No Strings Attached
June 3, 2025
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Class for FLAMES Game
class FlamesGame {
private:
    string name1, name2;

    // Helper to validate if name only contains letters and spaces
    bool isValidName(const string& name) {
        for (char ch : name) {
            if (!isalpha(ch) && ch != ' ')
                return false;
        }
        return true;
    }

    // Helper to convert name to lowercase
    void toLowerCase(string& str) {
        for (char& ch : str) {
            ch = tolower(ch);
        }
    }

    // Removes common characters and returns count of common characters
    int removeCommonLetters(string& n1, string& n2) {
        int count = 0;
        for (char& ch1 : n1) {
            for (char& ch2 : n2) {
                if (ch1 == ch2 && ch1 != ' ' && ch2 != ' ') {
                    ch1 = ch2 = ' ';
                    count++;
                    break;
                }
            }
        }
        return count;
    }

public:
    void play() {
        cout << "\n--- FLAMES Game ---\n";
        cout << "Enter first name: ";
        getline(cin, name1);
        while (!isValidName(name1)) {
            cout << "Invalid input! Only letters and spaces allowed.\n";
            cout << "Enter first name: ";
            getline(cin, name1);
        }

        cout << "Enter second name: ";
        getline(cin, name2);
        while (!isValidName(name2)) {
            cout << "Invalid input! Only letters and spaces allowed.\n";
            cout << "Enter second name: ";
            getline(cin, name2);
        }

        toLowerCase(name1);
        toLowerCase(name2);

        int commonCount = removeCommonLetters(name1, name2);

        cout << "You have " << commonCount << " common letters.\n";

        if (commonCount == 1)
            cout << "Result: Friends\n";
        else if (commonCount == 2)
            cout << "Result: Lovers\n";
        else if (commonCount % 3 == 0)
            cout << "Result: Admirers\n";
        else if (commonCount % 4 == 0)
            cout << "Result: Married Couple\n";
        else if (commonCount % 5 == 0)
            cout << "Result: Enemies\n";
        else if (commonCount % 6 == 0)
            cout << "Result: Sweethearts\n";
        else
            cout << "Result: No FLAMES determination matched.\n";
    }
};

// Class for Gene Game
class GeneGame {
private:
    string longSeq, shortSeq;

    bool isValidGeneSequence(const string& seq) {
        for (char ch : seq) {
            if (ch != 'A' && ch != 'T' && ch != 'G' && ch != 'C')
                return false;
        }
        return true;
    }

public:
    void play() {
        cout << "\n--- Gene Sequence Game ---\n";
        cout << "Enter the human gene sequence (A, T, G, C only): ";
        cin >> longSeq;

        while (!isValidGeneSequence(longSeq)) {
            cout << "Invalid input! Enter only A, T, G, C: ";
            cin >> longSeq;
        }

        cout << "Enter the shorter gene sequence (A, T, G, C only): ";
        cin >> shortSeq;

        while (!isValidGeneSequence(shortSeq)) {
            cout << "Invalid input! Enter only A, T, G, C: ";
            cin >> shortSeq;
        }

        int count = 0;
        cout << "Occurrences of '" << shortSeq << "' at indices: ";
        for (size_t i = 0; i <= longSeq.length() - shortSeq.length(); ++i) {
            if (longSeq.substr(i, shortSeq.length()) == shortSeq) {
                cout << i << " ";
                count++;
            }
        }

        if (count == 0)
            cout << "None\n";
        else
            cout << "\nTotal occurrences: " << count << endl;

        cin.ignore(); // Clean buffer for next getline
    }
};

// Main program with menu
int main() {
    FlamesGame flames;
    GeneGame gene;
    int choice;

    while (true) {
        cout << "\nMenu\n";
        cout << "1. FLAMES\n";
        cout << "2. Gene\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline character

        switch (choice) {
            case 1:
                flames.play();
                break;
            case 2:
                gene.play();
                break;
            case 3:
                cout << "Thank you for playing!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}