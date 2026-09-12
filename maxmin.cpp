#include <iostream>
using namespace std;
struct Pair {
    int minVal, maxVal;
};
Pair findMinMax(int arr[], int low, int high) {
    Pair result, left, right;
    if (low == high) {
        result.minVal = arr[low];
        result.maxVal = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.minVal = arr[low];
            result.maxVal = arr[high];
        } else {
            result.minVal = arr[high];
            result.maxVal = arr[low];
        }
        return result;
    }
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    result.minVal = min(left.minVal, right.minVal);
    result.maxVal = max(left.maxVal, right.maxVal);
    return result;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    Pair res = findMinMax(arr, 0, n - 1);
    cout << "Minimum element: " << res.minVal << endl;
    cout << "Maximum element: " << res.maxVal << endl;
    return 0;
}
