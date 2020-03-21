#include <iostream>
#include <cmath>

using namespace std;

// 注意时间复杂度
//  1、如果max_length设为0，那就说明如果N是素数，要遍历到N才知道max_length为1
//  2、因此将max_length 初始值设置为1，这样每个整数最多遍历 2^16，3ms内即可完成

int main(){
    int N;
    cin >> N;
    int p = 2 * 3;
    int max_begin = N, max_length = 1;
    for(int i = 2; pow(i, max_length + 1) <= N; i++){
        // begin = i, p is i * (i + 1) * ... * (i + max_length) total max_length + 1;
        if(N % i == 0 && max_begin == N && max_length == 1){
            max_begin = i;
        }
        if(p > N || p < 0){
            break;
        }
        for(int l = max_length + 1; ; l++){
            if(p < 0 || p > N || N % p != 0){
                break;
            }
            max_length = l;
            max_begin = i;
            p = p * (i + l);
        }
        p = p / i * (i + max_length + 1);
    }
    cout << max_length << endl;
    for(int i = 0; i < max_length; i++){
        if(i != 0){
            cout << "*";
        }
        cout << max_begin + i;
    }
}
