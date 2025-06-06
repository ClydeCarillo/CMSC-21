/*
2024-02813
Bolando, Karylle Mirzi
FINAL OTSP: Mean, Median, and Mode (C++ Edition)
May 31, 2025
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Data {
public:
    int arr[20];

    // Functions for calculating the measures of central tendency
    float getMean() {
        int sum = 0;
        for (int i = 0; i < 20; i++) {
            sum += arr[i];
        }
        return sum / 20.0f;
    }

    float getMedian() {
        // Taking the mean of the 2 middle numbers
        return (arr[9] + arr[10]) / 2.0f;
    }

    void getMode() {
        int freq[20] = {0};
        int maxFreq = 1;

        // Count frequency
        for (int i = 0; i < 20; i++) {
            int count = 1;
            for (int j = i + 1; j < 20; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                } else {
                    break;
                }
            }
            freq[i] = count;
            if (count > maxFreq) {
                maxFreq = count;
            }
            i += count - 1; // Skip duplicates
        }

        bool first = true;
        for (int i = 0; i < 20; ) {
            int count = 1;
            for (int j = i + 1; j < 20; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                } else {
                    break;
                }
            }
            // Comma-separate multiple modes
            if (count == maxFreq) {
                if (!first) cout << ", ";
                cout << arr[i];
                first = false;
            }
            i += count;
        }
        cout << endl;
    }
};

int main() {
    Data data;

    // Read 20 sorted integers
    cout << "input: ";
    for (int i = 0; i < 20; i++) {
        cin >> data.arr[i];
    }

    // Capping the output to 2 decimal places
    cout << "output:" << endl;
    cout << fixed << setprecision(2);
    cout << "mean: " << data.getMean() << endl;
    cout << "median: " << data.getMedian() << endl;
    cout << "mode: ";
    data.getMode();
    
    return 0;
}
