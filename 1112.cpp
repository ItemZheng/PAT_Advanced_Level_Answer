#include <iostream>

using namespace std;

// 无坑，时间复杂度没有要求，直接记录即可，如果出现小于k次的字符，那这个字符一定是好的

int char_to_int(int c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a';
    }
    if(c >= '0' && c <= '9'){
        return c - '0' + 26;
    }
    return 36;
}

int main(){
    int broken[37];
    for(int i = 0; i < 37; i++){
        broken[i] = 0;
    }

    int k;
    cin >> k;

    string inputs;
    cin >> inputs;
    for(int i = 0; i < inputs.size(); i++){
        int ch = char_to_int(inputs[i]);
        if(broken[ch] == 2){
            continue;
        } else{
            bool maybe_broken = true;
            for(int j = 1; j < k; j++){
                if(i + j >= inputs.size()){
                    maybe_broken = false;
                    break;
                }
                if(inputs[i + j] != inputs[i]){
                    maybe_broken = false;
                    break;
                }
            }
            if(maybe_broken){
                broken[ch] = 1;
                i = i + k - 1;
            } else {
                broken[ch] = 2;
            }
        }
    }

    string res;
    int idx = 0;
    while(idx < inputs.size()){
        int ch = char_to_int(inputs[idx]);
        res = res + inputs[idx++];
        if(broken[ch] == 1){
            idx = idx + k - 1;
        }
    }

    for(int i = 0; i < inputs.size(); i++){
        int ch = char_to_int(inputs[i]);
        if(broken[ch] == 1){
            cout << inputs[i];
            broken[ch] = 0;
        }
    }
    cout<< endl;
    cout << res << endl;
}