#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  没坑，但是很难。动态规划题目。
//  1、存储一个 vector<int> total, total[j] 代表的是价值为j的硬币序列
//  2、遍历硬币，对于一个硬币v，total[j] = total[j - v] + v || total[j]，需要判断（根据题目要求判断）

bool less_seq(vector<int> &l1, vector<int> &l2){
    for(int i = 0; i < l1.size() && i < l2.size(); i++){
        if(l1[i] < l2[i]){
            return true;
        } else if(l1[i] > l2[i]){
            return false;
        }
    }
    return l1.size() <= l2.size();
}

int main(){
    int N, M;
    cin >> N >> M;

    int values[N];
    for(int i = 0; i < N; i++){
        cin >> values[i];
    }
    sort(values, values + N);

    vector<int> total[M + 1];
    for(int i = 0; i < N; i++){
        int v = values[i];
        if(v > M){
            break;
        }
        for(int j = M; j >= v; j--){
            if(!total[j - v].empty() || j - v == 0){
                if(total[j].empty()){
                    total[j] = total[j - v];
                    total[j].push_back(v);
                } else {
                    vector<int> cur = total[j - v];
                    cur.push_back(v);
                    if(less_seq(cur, total[j])){
                        total[j] = cur;
                    }
                }
            }
        }
    }

    if(total[M].empty()){
        cout << "No Solution" << endl;
    } else {
        for(int i = 0; i < total[M].size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << total[M][i];
        }
    }
}