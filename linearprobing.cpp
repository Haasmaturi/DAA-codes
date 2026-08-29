#include <iostream>
using namespace std;
int main() {
    int size, n;
    cout << "Enter hash table size: ";
    cin >> size;
    int table[size];
    for (int i = 0; i < size; i++)
        table[i] = -1;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int index = key % size;
        int original = index;
        while (table[index] != -1) {
            index = (index + 1) % size;

            if (index == original) {
                cout << "Hash table is full!\n";
                break;
            }
        }
        if (table[index] == -1)
            table[index] = key;
    }
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++)
        cout << i << " -> " << table[i] << endl;
    return 0;
}