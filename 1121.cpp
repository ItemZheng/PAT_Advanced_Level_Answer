#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑。
//  1、记录婚姻信息
//  2、记录到场情况
//  3、每个客户判断是否有配偶 以及 配偶是否到场
//

int main(){
    int pairs[100001], coming[100001];
    for(int i = 0; i < 100001; i++){
        pairs[i] = -1;
        coming[i] = -1;
    }

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int h1, h2;
        cin >> h1 >> h2;
        pairs[h1] = h2;
        pairs[h2] = h1;
    }

    int K;
    cin >> K;
    vector<int> guests;
    for(int i = 0; i < K; i++){
        int p;
        cin >> p;
        guests.push_back(p);
        coming[p] = 1;
    }

    vector<int> singles;
    for(int i = 0; i < K; i++){
        if(pairs[guests[i]] == -1 || coming[pairs[guests[i]]] == -1){
            singles.push_back(guests[i]);
        }
    }

    printf("%ld\n", singles.size());
    sort(singles.begin(), singles.end());
    for(int i = 0; i < singles.size(); i++){
        if(i > 0){
            printf(" ");
        }
        printf("%05d", singles[i]);
    }
}