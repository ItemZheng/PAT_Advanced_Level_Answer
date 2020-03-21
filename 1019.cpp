#include <vector>
#include <iostream>
#include <algorithm>

// 无坑

using namespace std;

int main() {
    vector<int> digits;
    int N, base;
    cin >> N >> base;

    if (N == 0) {
        digits.push_back(0);
    } else {
        while (N > 0) {
            digits.push_back(N % base);
            N = N / base;
        }
    }

    reverse(digits.begin(), digits.end());
    int yes = true;
    for (int i = 0; i < digits.size() / 2; i++) {
        if (digits[i] != digits[digits.size() - i - 1]) {
            yes = false;
            break;
        }
    }

    if (yes)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << digits[0];
    for (int i = 0; i < digits.size() - 1; i++) {
        cout << " " << digits[i + 1];
    }

}