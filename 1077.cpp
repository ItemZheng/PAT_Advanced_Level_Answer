#include <iostream>
#include <string>

using namespace std;

// 无坑。一直存着最大的common_suffix就可以，然后挨个比较（注意是case sensitive）

string common(string com, string str){
    for(int i = 0; i < com.size() && i < str.size(); i++){
        if(com[com.size() - i - 1] != str[str.size() - i - 1]){
            return com.substr(com.size() - i);
        }
    }
    return com;
}

int main(){
    int N;
    cin >> N;
    string max_common = "";
    getline(cin, max_common);
    getline(cin, max_common);
    for(int i = 1; i < N; i++){
        string input;
        getline(cin, input);
        max_common = common(max_common, input);
        if(max_common.empty()){
            break;
        }
    }
    if(max_common.empty()){
        cout << "nai";
    } else {
        cout << max_common;
    }
}