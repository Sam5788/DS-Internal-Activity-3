
#include <iostream>
using namespace std;

// PRN: 0128
// Seed: 128
// Scenario: Mango Varieties
// Hash Table Size: 23

#define SIZE 23

int main() {

    int arr[20] = {
        28, 41, 54, 67, 80,
        93, 6, 19, 32, 45,
        58, 71, 84, 97, 10,
        23, 36, 49, 62, 75
    };

    int hashTable[SIZE];

    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    cout << "MANGO VARIETY HASH TABLE\n";
    cout << "PRN Seed: 128\n";

    cout << "\nPersonalized Dataset:\n";

    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nInitial Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> " << hashTable[i] << endl;
    }

    return 0;
}
