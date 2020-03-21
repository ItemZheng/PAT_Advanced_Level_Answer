#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 动态规划
//  从 1 个 Factor 到 K 个Factor 遍历
//  从 K - 1 到 K 个 Factor 需要遍历 可能的Factor，尝试加入

bool greater_than(vector<int> &l1, vector<int> &l2){
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < l1.size(); i++){
        sum1 += l1[i];
    }
    for(int i = 0; i < l2.size(); i++){
        sum2 += l2[i];
    }
    if(sum1 != sum2){
        return sum1 > sum2;
    }
    sort(l1.rbegin(), l1.rend());
    sort(l2.rbegin(), l2.rend());
    for(int i = 0; i < l1.size() && i < l2.size(); i++){
        if(l1[i] != l2[i]){
            return l1[i] > l2[i];
        }
    }
    return l1.size() > l2.size();
}

int main(){
    int N, K, P;
    cin >> N >> K >> P;

    vector<int> sum[K + 1][N + 1];
    for(int i = 1; pow(i, P) <= N; i++){
        int v = (int) pow(i, P);
        sum[1][v].push_back(i);
    }

    // 在每一层都网上加 i^P, i 循环
    for(int level = 2; level <= K; level++){
        for(int j = level; j < N + 1; j++){
            for(int i = 1; pow(i, P) < j; i++){
                int v = (int) pow(i, P);
                if(!sum[level - 1][j - v].empty()){
                    if(sum[level][j].empty()){
                        sum[level][j] = sum[level - 1][j - v];
                        sum[level][j].push_back(i);
                    } else {
                        vector<int> cur =  sum[level - 1][j - v];
                        cur.push_back(i);
                        if(greater_than(cur, sum[level][j])){
                            sum[level][j] = cur;
                        }
                    }
                }
            }
        }
    }

    if(sum[K][N].empty()){
        cout << "Impossible" << endl;
    } else {
        sort(sum[K][N].rbegin(), sum[K][N].rend());
        cout << N << " = ";
        for(int i = 0; i < sum[K][N].size(); i++){
            if(i != 0){
                cout << " + ";
            }
            cout << sum[K][N][i] << "^" << P;
        }
        cout << endl;
    }
}