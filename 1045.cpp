#include <iostream>
#include <vector>

using namespace std;

// 动态规划题，想到思路就简单
//      1、首先，将颜色转化为排名，不是喜欢的颜色直接去掉
//      2、接下来，存一个count数组，count[i] 指的是布条最后一个颜色是i（排名）的最大长度
//      3、遍历布条，如果当前颜色排名是c，那就只更新count[c]，从count[0] ~ count[i]找到最大的count max，更新count[c] = max + 1

int main() {
    int N;
    cin >> N;
    int colors[N];
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        colors[c - 1] = i;
    }

    int M;
    cin >> M;
    vector<int> stripe;
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        if (colors[c - 1] >= 0) {
            stripe.push_back(colors[c - 1]);
        }
    }

    int count[K];
    for(int i = 0; i < K; i++){
        count[i] = 0;
    }

    for(int len = 0; len < stripe.size(); len++){
        // update
        int c = stripe[len];
        int max = -1;
        for(int i = 0; i <= c; i++){
            if(count[i] > max){
                max = count[i];
            }
        }
        count[c] = max + 1;
    }

    int max = 0;
    for(int i = 0; i < K; i++){
        if(count[i] > max){
            max = count[i];
        }
    }

    cout << max << endl;

}