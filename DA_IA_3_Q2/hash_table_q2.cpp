
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

int arr[N] = {
    28, 41, 54, 67, 80,
    93, 6, 19, 32, 45,
    58, 71, 84, 97, 10,
    23, 36, 49, 62, 75
};

// Division Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

// Display Hash Table
void displayTable(int table[]) {
    cout << "\nIndex\tValue\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }
}

// Insert using Linear Probing
void insert(int table[], int key) {
    int index = hashFunction(key);
    int start = index;

    cout << "\nInserting: " << key;
    cout << "\nInitial Index: " << index;

    while (table[index] != -1) {
        if (table[index] == key) {
            cout << "\nDuplicate key. Not inserted.\n";
            return;
        }

        cout << "\nCollision at index: " << index;
        index = (index + 1) % SIZE;

        if (index == start) {
            cout << "\nHash Table is Full!\n";
            return;
        }
    }

    table[index] = key;
    cout << "\nInserted at index: " << index << endl;
}

int main() {
    int hashTable[SIZE];

    // Initialize Hash Table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    cout << "================================";
    cout << "\n     MANGO VARIETY HASH TABLE";
    cout << "\n================================";
    cout << "\nPRN Seed: 128";
    cout << "\nHash Table Size: " << SIZE;

    cout << "\n\nPersonalized Dataset:\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nStarting Linear Probing...";

    // Insert all dataset values
    for (int i = 0; i < N; i++) {
        insert(hashTable, arr[i]);
    }
    cout << "\n\nTesting Duplicate Key:";
insert(hashTable, 28);
    cout << "\n\nFinal Hash Table:";
    displayTable(hashTable);

    cout << "\nProgram Completed Successfully.\n";

    return 0;
}
