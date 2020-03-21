#include <iostream>
#include <vector>

using namespace std;

// 无坑，很简单。

int getSum(string num){
    int s = 0;
    for(int i = 0; i < num.size(); i++){
        s = s + num[i] - '0';
    }
    return s;
}

int main(){
    int existSum[40];
    for(int i = 0; i < 40; i++){
        existSum[i] = 0;
    }

    int N, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int sum = getSum(s);
        if(existSum[sum] == 0){
            count++;
            existSum[sum] = 1;
        }
    }

    cout << count << endl;
    for(int i = 0; i < 40; i++){
        if(existSum[i] == 1){
            cout << i;
            if(count != 1)
                cout << " ";
            count--;
        }
    }
}