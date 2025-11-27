#include <bits/stdc++.h>
using namespace std;
int Matrix_chain_multiplication(int arr[], int size) {
    vector<vector<int>> mul(size, vector<int>(size, 0));
    for (int d = 1; d < size; d++) {
        for (int i = 1; i < size - d; i++) {
            int j = i + d;
            mul[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int temp = mul[i][k] + mul[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                if (temp < mul[i][j]) {
                    mul[i][j] = temp;
                }
            }
        }
    }
    return mul[1][size - 1];
}
int main() {
    int arr[] = {3, 2, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications: "<< Matrix_chain_multiplication(arr, size) << endl;
    return 0;
}
