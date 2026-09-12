#include <iostream>
#include <climits>
using namespace std;
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0, leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    int leftMax = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);
    return max(max(leftMax, rightMax), crossMax);
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Maximum subarray sum: " << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
