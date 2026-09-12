#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int weight, value;
};
bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}
double fractionalKnapsack(int W, Item items[], int n) {
    sort(items, items + n, compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = W - currentWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    Item items[100];
    cout << "Enter weight and value of each item: ";
    for (int i = 0; i < n; i++) cin >> items[i].weight >> items[i].value;
    cout << "Enter capacity of knapsack: ";
    cin >> W;
    cout << "Maximum value in knapsack: " << fractionalKnapsack(W, items, n);
    return 0;
}
