#include <iostream>
#include <string>
#include <stack>

using namespace std;

char to_char(int num){
    if(num < 10){
        return '0' + num;
    }
    return num - 10 + 'A';
}

string to_r13_digit(int N){
    if(N == 0){
        return "00";
    }
    string res = "";
    res = res + to_char((N/13)%13);
    return res + to_char(N % 13);
}

int main(){
    cout << "#";
    for(int i = 0; i < 3; i++){
        int num;
        cin >> num;
        cout << to_r13_digit(num);
    }
}