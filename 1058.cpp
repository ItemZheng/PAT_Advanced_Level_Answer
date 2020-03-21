#include <iostream>
#include <string>

using namespace std;

// 无坑。把输入的字符串转化为long，直接相加输出对应的字符

long currency_to_value(string str){
    int idx = str.find('.');
    // get Galleon
    long g = stol(str.substr(0, idx));
    str = str.substr(idx + 1);

    // get Sickle
    idx = str.find('.');
    long s = stol(str.substr(0, idx));
    str = str.substr(idx + 1);

    // get Knut
    long k = stol(str);

    return g * 17 * 29 + s * 29 + k;
}

void output(long val){
    cout << val / (17 * 29) << ".";
    cout << val % (17 * 29) / 29 << ".";
    cout << val % 29 << endl;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    long l1 = currency_to_value(s1), l2 = currency_to_value(s2);
    output(l1 + l2);
}