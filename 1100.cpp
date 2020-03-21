#include <iostream>

using namespace std;

// 注意本题不像二进制，二进制中2是10，而本题是13进制 13是 tam 而不是 tam tret

string higher[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string lower[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

int find_pos(string str){
    for(int i = 0; i < 13; i++){
        if(lower[i] == str){
            return i;
        }
        if(higher[i] == str){
            return i * 13;
        }
    }
    return 0;
}

void print(int num){
    if(num == 0){
        cout << lower[0] << endl;
        return;
    }
    if(num / 13){
        cout << higher[num / 13];
        if(num % 13){
            cout << " " << lower[num % 13];
        }
    } else {
        cout << lower[num % 13];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    string number;
    getline(cin, number);
    for(int i = 0; i < N; i++){
        getline(cin, number);
        if(number[0] >= '0' && number[0] <= '9'){
            print(stoi(number));
        } else {
            int idx = number.find(' ');
            if(idx == string::npos){
                cout << find_pos(number) << endl;
            } else {
                string h = number.substr(0, idx), l = number.substr(idx + 1);
                cout << find_pos(h) + find_pos(l) << endl;
            }
        }
    }
}