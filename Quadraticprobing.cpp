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
        int hash = key % size;
        bool inserted = false;
        for (int j = 0; j < size; j++) {
            int index = (hash + j * j) % size;
            if (table[index] == -1) {
                table[index] = key;
                inserted = true;
                break;
            }
        }
        if (!inserted)
            cout << "Cannot insert " << key << endl;
    }
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++)
        cout << i << " -> " << table[i] << endl;
    return 0;
}