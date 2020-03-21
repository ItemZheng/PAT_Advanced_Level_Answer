#include <iostream>

using namespace std;

// 无坑

string num_str(int x){
    string res;
    if(x / 13 == 0){
        res = "S";
    } else if(x / 13 == 1){
        res = "H";
    } else if(x / 13 == 2){
        res = "C";
    } else if(x / 13 == 3){
        res = "D";
    } else {
        res = "J";
    }
    res = res + to_string(x % 13 + 1);
    return res;
}

int main(){
    int size = 54, order[54], ori[54];
    int K;
    cin >> K;
    for(int i = 0; i < size; i++){
        cin >> order[i];
        order[i]--;
        ori[i] = i;
    }

    for(int i = 0; i < K; i++){
        int temp[54];
        for(int j = 0; j < 54; j++){
            temp[order[j]] = ori[j];
        }
        for(int j = 0; j < 54; j++){
            ori[j] = temp[j];
        }
    }
    cout << num_str(ori[0]);
    for(int i = 1; i < size; i++){
        cout << " " << num_str(ori[i]);
    }
}