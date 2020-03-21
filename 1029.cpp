#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 坑点：内存限制

int main() {
    queue<int> nums;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        nums.push(num);
    }

    int M;
    cin >> M;
    int idx = 0;
    for(int j = 0; j < M; j++){
        int num;
        cin >> num;
        while(!nums.empty() && nums.front() < num){
            idx++;
            if(idx == (N + M + 1) / 2){
                cout << nums.front() << endl;
                return 0;
            }
            nums.pop();
        }
        idx++;
        if(idx == (N + M + 1) / 2){
            cout << num << endl;
            return 0;
        }
    }

    while(idx < (N + M + 1) / 2){
        idx++;
        if(idx == (N + M + 1) / 2){
            cout << nums.front() << endl;
            return 0;
        }
        nums.pop();
    }
}