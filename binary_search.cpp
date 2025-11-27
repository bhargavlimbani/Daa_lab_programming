#include <iostream>
using namespace std;


int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }   
    return -1;
}

int main() {
    int arr[] = {1, 3, 9, 50, 52};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
