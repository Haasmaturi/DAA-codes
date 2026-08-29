#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    cout << "\nFrequency of elements:\n";
    for (auto x : frequency) {
        cout << x.first << " -> " << x.second << endl;
    }
    return 0;
}