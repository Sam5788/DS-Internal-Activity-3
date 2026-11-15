
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 12;
const int M = 29;
const int KEY = 42;

int original[N] = {
    3, 34, 65, 96, 30, 61,
    92, 26, 57, 88, 22, 53
};

// Display array
void display(int a[]) {
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 1. Bubble Sort
void bubbleSort() {
    int a[N];
    copy(original, original + N, a);

    cout << "\n--- BUBBLE SORT ---\n";

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
        display(a);
    }
}

// 2. Insertion Sort
void insertionSort() {
    int a[N];
    copy(original, original + N, a);

    cout << "\n--- INSERTION SORT ---\n";

    for (int i = 1; i < N; i++) {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
        display(a);
    }
}

// 3. Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);
        int p = i + 1;

        cout << "Pivot " << pivot << ": ";
        display(a);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// 4. Radix Sort
void radixSort() {
    int a[N];
    copy(original, original + N, a);

    cout << "\n--- RADIX SORT ---\n";

    int maxValue = *max_element(a, a + N);

    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        int output[N];
        int count[10] = {0};

        for (int i = 0; i < N; i++)
            count[(a[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = N - 1; i >= 0; i--) {
            int digit = (a[i] / exp) % 10;
            output[--count[digit]] = a[i];
        }

        for (int i = 0; i < N; i++)
            a[i] = output[i];

        cout << "After digit place " << exp << ": ";
        display(a);
    }
}

// 5. Linear Search
void linearSearch() {
    cout << "\n--- LINEAR SEARCH ---\n";

    for (int i = 0; i < N; i++) {
        cout << "Compare " << original[i]
             << " with " << KEY << endl;

        if (original[i] == KEY) {
            cout << "Found at index " << i << endl;
            return;
        }
    }

    cout << "Key not found\n";
}

// 6. Binary Search
void binarySearch(int a[]) {
    cout << "\n--- BINARY SEARCH ---\n";

    int low = 0, high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        cout << "Low=" << low << " Mid=" << mid
             << " High=" << high << endl;

        if (a[mid] == KEY) {
            cout << "Found at index " << mid << endl;
            return;
        }
        else if (a[mid] < KEY)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Key not found\n";
}

// 7. Fibonacci Search
void fibonacciSearch(int a[]) {
    cout << "\n--- FIBONACCI SEARCH ---\n";

    int fib2 = 0, fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < N) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, N - 1);

        cout << "Checking index " << i
             << " value " << a[i] << endl;

        if (a[i] < KEY) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (a[i] > KEY) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            cout << "Found at index " << i << endl;
            return;
        }
    }

    if (fib1 && offset + 1 < N &&
        a[offset + 1] == KEY) {
        cout << "Found at index " << offset + 1 << endl;
    }
    else {
        cout << "Key not found\n";
    }
}

// 8. Linear Probing
void linearProbing() {
    cout << "\n--- LINEAR PROBING ---\n";

    int table[M];

    fill(table, table + M, -1);

    for (int i = 0; i < N; i++) {
        int key = original[i];
        int index = key % M;

        cout << "\nInserting " << key;

        while (table[index] != -1) {
            cout << "\nCollision at " << index;
            index = (index + 1) % M;
        }

        table[index] = key;
        cout << "\nInserted at " << index << endl;

        for (int j = 0; j < M; j++) {
            cout << j << ": ";
            if (table[j] == -1)
                cout << "EMPTY";
            else
                cout << table[j];
            cout << endl;
        }
    }
}

// 9. Separate Chaining
void separateChaining() {
    cout << "\n--- SEPARATE CHAINING ---\n";

    vector<int> table[M];

    for (int i = 0; i < N; i++) {
        int key = original[i];
        int index = key % M;

        table[index].push_back(key);

        cout << "\nInserted " << key
             << " at index " << index << endl;

        for (int j = 0; j < M; j++) {
            cout << j << ": ";

            for (int x : table[j])
                cout << x << " -> ";

            cout << "NULL\n";
        }
    }
}

int main() {
    int sorted[N];
    copy(original, original + N, sorted);

    sort(sorted, sorted + N);

    cout << "DATA STRUCTURES IA-3 QUESTION 1\n";
    cout << "PRN Seed: 128\n";
    cout << "Search Key: 42\n";
    cout << "Hash Table Size: 29\n";

    cout << "\nOriginal Array:\n";
    display(original);

    bubbleSort();
    insertionSort();

    cout << "\n--- QUICK SORT ---\n";
    int quick[N];
    copy(original, original + N, quick);
    quickSort(quick, 0, N - 1);

    radixSort();

    linearSearch();
    binarySearch(sorted);
    fibonacciSearch(sorted);

    linearProbing();
    separateChaining();

    cout << "\nPROGRAM COMPLETED\n";

    return 0;
}
