#include <string>
#include <iostream>
#include <algorithm>

// 无坑

using namespace std;

int main(){
    string name;
    getline(cin, name);
    if(name.size() == 0){
        cout << 0;
        return 0;
    }
    int max_len = 1;
    for(int i = 0; i < name.size(); i++){
        int len = max_len + 1;
        while(i + len <= name.size()){
            string str = name.substr(i, len), r_str = str;
            reverse(r_str.begin(), r_str.end());
            if (str == r_str){
                max_len = len;
            }
            len++;
        }
    }
    cout << max_len << endl;
}

