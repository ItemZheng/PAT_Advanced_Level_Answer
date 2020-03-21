#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//  1、这道题的输入是十进制的N, D指的是先把N转化为D进制下的数字，然后再reverse
//  2、<2的不是素数，这也是一个得分点

string value_to_string(int num, int r){
    string num_str;
    while (num > 0){
        char c = num % r + '0';
        num_str = c + num_str;
        num = num / r;
    }
    return num_str;
}

int value(string num, int r, bool reverse){
    int res = 0;
    if(!reverse)
        for(int i = 0; i < num.size(); i++){
            res = res * r + num[i] - '0';
        }
    else
        for(int i = num.size() - 1; i >= 0; i--){
            res = res * r + num[i] - '0';
        }
    return res;
}

bool isPrime(int v){
    if(v < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(v); i++){
        if(v % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int D, N;
    cin >> N;

    while (N >= 0){
        cin >> D;
        string N1 = value_to_string(N, D);
        int v1 = N;
        int v2 = value(N1, D, true);
        if(isPrime(v1) && isPrime(v2)){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> N;
    }
    return 0;
}