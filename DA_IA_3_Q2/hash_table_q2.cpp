
#include <iostream>
using namespace std;

// PRN: 0128
// Seed: 128
// Scenario: Mango Varieties
// Dataset Size: 20
// Hash Table Size: 23
// Hash Method: Division Method
// Collision Handling: Linear Probing

#define SIZE 23
#define N 20

// Division Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

int main() {

    // Personalized Dataset
    int arr[N] = {
        28, 41, 54, 67, 80,
        93, 6, 19, 32, 45,
        58, 71, 84, 97, 10,
        23, 36, 49, 62, 75
    };

    int hashTable[SIZE];

    // Initialize Hash Table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    // Display Heading
    cout << "================================";
    cout << "\n     MANGO VARIETY HASH TABLE";
    cout << "\n================================";

    cout << "\nPRN Seed: 128";
    cout << "\nHash Table Size: " << SIZE;

    // Display Dataset
    cout << "\n\nPersonalized Dataset:\n";

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    // Display Initial Hash Table
    cout << "\n\nInitial Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> " << hashTable[i] << endl;
    }

    // Display Hash Function Results
    cout << "\nDivision Hash Function Results:\n";

    for (int i = 0; i < N; i++) {

        cout << arr[i] << " -> "
             << hashFunction(arr[i]) << endl;

    }

    cout << "\nProgram Completed Successfully.";

    return 0;
}
