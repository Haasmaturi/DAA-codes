//Binary search program recursive which takes input array and prints the index if found

#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Element not found
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid; // Element found at index mid
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target); // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, high, target); // Search in the right half
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}