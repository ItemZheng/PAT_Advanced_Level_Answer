#include <iostream>
#include <string>

using namespace std;

// 无坑。注意空格即可，需要以getline的方式读入才不会漏掉空格。

int main(){
    string s, chs;
    getline(cin, s);
    getline(cin, chs);

    bool isDelete[129];
    for(int i = 0; i < 129; i++){
        isDelete[i] = false;
    }

    for(int i = 0; i < chs.size(); i++){
        isDelete[(int)chs[i]] = true;
    }

    for(int i = 0; i < s.size(); i++){
        if(!isDelete[(int)s[i]]){
            cout << s[i];
        }
    }

}