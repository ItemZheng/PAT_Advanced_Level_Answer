#include <iostream>
#include <vector>
#include <algorithm>

// 无坑。正向遍历一遍，存 0 - i的最大值，反向遍历一遍，存 i - N的最小值，然后遍历判断

using namespace std;

int main(){
    int N;
    cin >> N;

    int temp_max[N], temp_min[N], number[N], cur_max = 0;
    for(int i = 0; i < N; i++){
        cin >> number[i];
        if(number[i] > cur_max){
            cur_max = number[i];
        }
        temp_max[i] = cur_max;
    }
    int cur_min = number[N - 1];
    for(int i = N - 1; i >= 0; i--){
        if(number[i] < cur_min){
            cur_min = number[i];
        }
        temp_min[i] = cur_min;
    }

    vector<int> valids;
    for(int i = 0; i < N; i++){
        if(temp_max[i] > number[i]){
            continue;
        }
        if(temp_min[i] < number[i]){
            continue;
        }
        valids.push_back(number[i]);
    }
    sort(valids.begin(), valids.end());
    cout << valids.size() << endl;
    for(int j = 0; j < valids.size(); j++){
        if(j > 0){
            cout << " ";
        }
        cout << valids[j];
    }
    cout << endl;
}