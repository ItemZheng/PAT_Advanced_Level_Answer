#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 无坑，就像一个滑动窗口一样，如果小于K，就 end++; 不然就 begin++; 然后评估当前的值是否合适

int main(){
    int N, K;
    cin >> N >> K;

    int number[N];
    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    int min = -1;
    vector<pair<int, int>> idx_pairs;
    int begin = 0, end = -1;
    int sum = 0;
    while (true){
        if(sum < K){
            end++;
            if(end >= N){
                break;
            }
            sum = sum + number[end];
        } else {
            sum = sum - number[begin++];
        }
        if(sum >= K){
            if(min == -1 || (sum < min)){
                idx_pairs.clear();
                min = sum;
                idx_pairs.emplace_back(begin, end);
            } else if(sum == min){
                idx_pairs.emplace_back(begin, end);
            }
        }
    }
    for(int i = 0; i < idx_pairs.size(); i++){
        cout << idx_pairs[i].first + 1 << "-" << idx_pairs[i].second + 1 << endl;
    }
}