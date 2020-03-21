#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

// 无坑，但是如果使用非递归的办法，会稍微繁琐一点
//  如果从 10个人选出了4个，那么剩下的6个都是第五

int sum = 0;

void solve_group(vector<int> programmers, int rank[], int Np, int weight[]){
    if(programmers.size() == 1){
        rank[programmers[0]] = sum + 1;
        sum = sum + 1;
        return;
    }

    vector<int> next_group;
    for(int i = 0; i * Np < programmers.size(); i++){
        vector<int> group;
        for(int j = 0; j < Np && i * Np + j < programmers.size(); j++){
            group.push_back(programmers[i * Np + j]);
        }

        // find max
        int max_id = -1;
        for(int j = 0; j < group.size(); j++){
            if(max_id == -1 || weight[group[j]] > weight[max_id]){
                max_id = group[j];
            }
        }
        next_group.push_back(max_id);
    }

    solve_group(next_group, rank, Np, weight);
    for(int i = 0; i < programmers.size(); i++){
        if(rank[programmers[i]] == -1){
            rank[programmers[i]] = sum + 1;
        }
    }
    sum = programmers.size();
}

int main(){
    // input
    int N, Np;
    cin >> N >> Np;

    int weight[N], rank[N];
    vector<int> programmers;
    for(int i = 0; i < N; i++){
        cin >> weight[i];
        rank[i] = -1;
    }
    for(int i = 0; i < N; i++){
        int order;
        cin >> order;
        programmers.push_back(order);
    }

    // begin rank
    solve_group(programmers, rank, Np, weight);
    cout << rank[0];
    for(int i = 1; i < N; i++){
        cout << " " << rank[i];
    }
}