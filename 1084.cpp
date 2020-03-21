#include <iostream>
#include <unordered_map>

using namespace std;

// 无坑

char change_case(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch - 'a' + 'A';
    }
    return ch;
}

int main(){
    unordered_map<char, bool> broken_keys;
    string ori_str, now_str;
    getline(cin, ori_str);
    getline(cin, now_str);

    int now_idx = 0;
    for(int i = 0; i < ori_str.size(); i++){
        char ch = ori_str[i];
        if(now_idx <= now_str.size() && ch == now_str[now_idx]){
            // not broken
            now_idx++;
            continue;
        }
        // broken
        if(broken_keys.count(change_case(ch)) == 0){
            broken_keys[change_case(ch)] = true;
            cout << change_case(ch);
        }
    }
}