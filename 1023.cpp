#include <iostream>
#include <string>
#include <algorithm>

// 无坑
//  注意：字符串显示，注意最后进位不为零要加一位，或直接输出No

using namespace std;

int main(){
    string x;
    cin >> x;
    reverse(x.begin(), x.end());

    int c = 0;
    string y = "";
    for(int i = 0; i < x.size(); i++){
        int num = x[i] - '0';
        int res = num * 2 + c;
        c = res / 10;
        res = res % 10;
        y += (res + '0');
    }
    if(c > 0){
        y += (c + '0');
    }

    int digit[10];
    for(int i = 0; i < 10; i++){
        digit[i] = 0;
    }
    for(int i = 0; i < x.size(); i++){
        digit[x[i] - '0']++;
    }
    for(int i = 0; i < y.size(); i++){
        digit[y[i] - '0']--;
    }

    int yes = true;
    for(int i = 0; i < 10; i++){
        if(digit[i] != 0){
            cout << "No" << endl;
            yes = false;
            break;
        }
    }
    if(yes){
        cout << "Yes" << endl;
    }
    reverse(y.begin(), y.end());
    cout << y << endl;
}