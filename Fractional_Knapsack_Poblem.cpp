#include <iostream>
#include <algorithm>
using namespace std;
struct item {
    int wt;
    int val;
    double ratio;
};
int main() {
    int size;
    cout << "Enter total items: ";
    cin >> size;
    item items[size];
    cout << "Enter details of items:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter item[" << i << "] wt: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] val: ";
        cin >> items[i].val;
        items[i].ratio = (double)items[i].val / items[i].wt; 
    }
    sort(items, items + size, [](const item &a, const item &b) {
        return a.ratio > b.ratio;
    });
    int capacity;
    cout << "Enter total capacity: ";
    cin >> capacity;
    double total_value = 0.0;
    int current_weight = 0;
    cout << "\nSelected items (weight, value, taken):\n";
    for (int i = 0; i < size && capacity > 0; i++) {
        if (items[i].wt <= capacity) {
            capacity -= items[i].wt;
            total_value += items[i].val;
            cout << items[i].wt << " " << items[i].val << " (1.0)\n";
        } else {
            double fraction = (double)capacity / items[i].wt;
            total_value += items[i].val * fraction;
            cout << items[i].wt << " " << items[i].val << " (" << fraction << ")\n";
            capacity = 0; 
        }
    }
    cout << "\nTotal value: " << total_value << endl;
    return 0;
}
