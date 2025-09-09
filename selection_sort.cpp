#include <iostream>
using namespace std;

void inPlaceSorting(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minimum_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[minimum_index] > arr[j])
            {
                minimum_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minimum_index];
        arr[minimum_index] = temp;
    }
}

int main()
{
    int arr[] = {4, 5, 6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    inPlaceSorting(arr, n);

    cout << "Your Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
