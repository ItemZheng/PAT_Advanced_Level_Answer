#include <iostream>
#include <cmath>

using namespace std;

// 无坑。好题。但是思路比较重要
//  思路：计算每个位置上1可能出现的个数，首先将数字分为两个部分，前半部分和后半部分，然后根据该位置是不是>1进行调整

int main(){
    string N;
    cin >> N;
    int total = 0;
    for(int i = 0; i < N.size(); i++){
        int pre = 1, post = 1;
        if(i != 0){
            pre = stoi(N.substr(0, i)) + 1;
        }
        if(i != N.size() - 1){
            post = stoi(N.substr(i + 1, N.size() - i - 1)) + 1;
        }

        if(N[i] > '1'){
            post = 0;
        } else if(N[i] == '1'){
            pre--;
        } else {
            post = 0;
            pre--;
        }
        total = total + pre * pow(10, N.size() - i - 1) + post;
    }
    cout << total << endl;
}