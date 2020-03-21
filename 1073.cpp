#include <iostream>
#include <string>

// 无坑，思考清楚情况就好。先判断符号位，然后拿到所有的有效数字，然后拿到指数，根据指数判断。

using namespace std;

int main(){
    string number;
    cin >> number;

    if(number[0] == '-'){
        cout << '-';
        number = number.substr(1);
    } else if(number[0] == '+'){
        number = number.substr(1);
    }

    int idx = number.find('E');
    string prefix = number.substr(0, idx);
    prefix = prefix[0] + prefix.substr(2);
    int exp = stoi(number.substr(idx + 1));

    if(exp < 0){
        cout << "0.";
        string zeros = string(-exp - 1, '0');
        cout << zeros << prefix;
    } else{
        if(exp >= prefix.size() - 1){
            // no point
            cout << prefix;
            string zeros = string(exp - prefix.size() + 1, '0');
            cout << zeros;
        } else{
            // point
            cout << prefix.substr(0, exp + 1) << ".";
            cout << prefix.substr(exp + 1);
        }
    }
}