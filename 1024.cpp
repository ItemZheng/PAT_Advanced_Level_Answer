#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 注意点： 注意题目的数字范围 long long 也会越界
//         要用字符串

string add(string x){
    string y = x;
    reverse(x.begin(), x.end());

    string res = "";
    int carry = 0;
    for(int i = 0; i < x.size() || i < y.size(); i++){
        int x_digit = 0, y_digit = 0;
        if(i < x.size()){
            x_digit = x[i] - '0';
        }
        if(i < y.size()){
            y_digit = y[i] - '0';
        }
        res = res + (char)((x_digit + y_digit + carry) % 10 + '0');
        carry = (x_digit + y_digit + carry) / 10;
    }
    if(carry > 0){
        res = res + (char)('0' + carry);
    }
    reverse(res.begin(), res.end());
    return res;
}

bool is_palindromic(string n){
    string y = n;
    reverse(y.begin(), y.end());
    return n == y;
}

int main(){
    string N;
    int K;
    cin >> N >> K;

    if(is_palindromic(N)){
        cout << N << endl;
        cout << 0 << endl;
    } else {
        for(int i = 0; i < K; i++){
            N = add(N);
            if(is_palindromic(N)){
                cout << N << endl;
                cout << i + 1 << endl;
                return 0;
            }
        }
        cout << N << endl;
        cout << K << endl;
    }
}