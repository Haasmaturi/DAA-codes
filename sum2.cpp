#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    int n, T;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target T: ";
    cin >> T;
    unordered_set<int> s;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int required = T - arr[i];
        if (s.find(required) != s.end()) {
            cout << "Pair found: "
                 << required << " + " << arr[i]
                 << " = " << T << endl;
            found = true;
            break;
        }
        s.insert(arr[i]);
    }
    if (!found)
        cout << "No pair found." << endl;
    return 0;
}