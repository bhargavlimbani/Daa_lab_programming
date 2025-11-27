#include <iostream>
using namespace std;

void counting_sort(int arr[], int n)
{
    if (n == 0)
        return;

    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    int count[1001] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main()
{
    int arr[] = {4, 5, 5, 8, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);

    cout << "Your Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
