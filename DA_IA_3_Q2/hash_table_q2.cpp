
#include <iostream>
using namespace std;

// PRN: 0128
// Scenario: Mango Varieties
// Dataset size: 20
// Hash table size: 23

int main() {

    int arr[20] = {
        28, 41, 54, 67, 80,
        93, 6, 19, 32, 45,
        58, 71, 84, 97, 10,
        23, 36, 49, 62, 75
    };

    cout << "MANGO VARIETY HASH TABLE";
    cout << "\nPRN Seed: 128";

    cout << "\n\nPersonalized Dataset:\n";

    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nDataset generated successfully.";

    return 0;
}
