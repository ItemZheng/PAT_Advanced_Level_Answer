#include <iostream>
#include <string>

using namespace std;

int integer = 0, numerator = 0, denominator = 1;

// 有坑。注意点：  1、寻找最大公因数用gcd
//               2、需要注意最大公因数需要是正数
//              3、运算过程不需要计算整数

int gcd(int m, int n){
    if(m % n == 0){
        return n;
    }
    return gcd(n, m % n);
}

int find_max_factor(){
    int n = numerator, d = denominator;
    if(n < 0){
        n = -n;
    }
    if(n > d){
        return gcd(n, d);
    }
    return gcd(d, n);
}

void simplify(){
    if(numerator == 0){
        denominator = 1;
        return;
    }
    int factor = find_max_factor();
    numerator = numerator / factor;
    denominator = denominator / factor;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string relation;
        cin >> relation;
        int idx = relation.find('/');
        int n, d;
        if(idx != string::npos){
            n = stoi(relation.substr(0, idx));
            d = stoi(relation.substr(idx + 1));
        } else {
            d = 1;
            n = stoi(relation);
        }
        numerator = numerator * d + n * denominator;
        denominator = denominator * d;
        simplify();
    }
    integer = integer + numerator / denominator;
    numerator = numerator % denominator;
    if(integer == 0 && numerator == 0){
        cout << 0;
    } else {
        if(integer != 0){
            cout << integer;
        }
        if(numerator != 0){
            if(integer != 0){
                cout << " ";
            }
            cout << numerator << "/" << denominator;
        }
    }
}