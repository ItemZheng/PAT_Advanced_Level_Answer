#include <iostream>
#include <string>

using namespace std;

// 注意点：
//      进制下限，根据N2数字的digit判断
//      进制不仅仅到36，比如 aa 也可以是 100 进制的数值
//      会有运行超时的情况，因此需要找到上限，然后用二分搜索
//      即使用long long 也会有溢出的情况，所有也要同时用 value < 0 来判断radix是不是过大

int valueOfDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'a' + 10;
    }
}

long long valueOfRadixNumber(string number, long long radix) {
    long long value = 0;
    for (int i = 0; i < number.size(); i++) {
        value = value * radix + valueOfDigit(number[i]);
    }
    return value;
}

int main() {
    int tag, radix, r1;
    string N1, N2;
    cin >> N1 >> N2 >> tag >> radix;
    r1 = radix;
    if (tag == 2) {
        string temp = N1;
        N1 = N2;
        N2 = temp;
    }

    // N1 r1 is known, r2 unknown
    long long N1v = valueOfRadixNumber(N1, r1), min_radix = 1, max_radix = N1v + 1, r;
    for (int i = 0; i < N2.size(); i++) {
        if (min_radix < valueOfDigit(N2[i]) + 1) {
            min_radix = valueOfDigit(N2[i]) + 1;
        }
    }
    bool possible = false;
    long long m = min_radix;
    if(max_radix < min_radix){
        max_radix = min_radix;
    }
    r = (min_radix + max_radix) / 2;
    while (min_radix <= max_radix) {
        if (N1v == valueOfRadixNumber(N2, r)) {
            m = r;
            possible = true;
            max_radix = r - 1;
        } else if (N1v < valueOfRadixNumber(N2, r) || valueOfRadixNumber(N2, r) < 0) {
            max_radix = r - 1;
        } else if (N1v > valueOfRadixNumber(N2, r)) {
            min_radix = r + 1;
        }
        r = (min_radix + max_radix) / 2;
    }
    if(possible)
        cout << m;
    else
        cout << "Impossible";
    return 0;
}