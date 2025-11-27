#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pindex = low;
    int pivot = arr[high];
    for(int i = low; i < high; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex], arr[high]);
    return pindex;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
