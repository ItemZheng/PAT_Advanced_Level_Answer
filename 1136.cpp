#include <iostream>
#include <algorithm>

using namespace std;

// 无坑。

string reverse_str(string str){
    reverse(str.begin(), str.end());
    return str;
}

string add(string num){
    string num_r = reverse_str(num);

    int carry = 0;
    string res;
    for(int i = 0; i < num.size(); i++){
        int c1 = num[i] - '0';
        int c2 = num_r[i] - '0';
        char c = char((c1 + c2 + carry) % 10 + '0');
        res = res + c;
        carry = (c1 + c2 + carry) / 10;
    }
    if(carry > 0){
        res = res + (char)('0' + carry);
    }
    return reverse_str(res);
}

int main(){
    string num;
    cin >> num;
    if(reverse_str(num) == num){
        cout << num << " is a palindromic number." << endl;
    } else {
        for(int i = 0; i < 10; i++){
            cout << num << " + " << reverse_str(num) << " = ";
            num = add(num);
            cout << num << endl;
            if(reverse_str(num) == num){
                cout << num << " is a palindromic number." << endl;
                return 0;
            }
        }
        cout << "Not found in 10 iterations." << endl;
    }
}