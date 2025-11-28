#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> naive_string_match(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> positions;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;

        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            positions.push_back(i);
        }
    }

    return positions;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> result = naive_string_match(text, pattern);

    cout << "Pattern found at indices: ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
