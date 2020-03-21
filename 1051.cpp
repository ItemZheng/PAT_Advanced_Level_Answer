#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 无坑，模拟一遍即可

int main(){
    int M, N, K;
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        stack<int> s;
        queue<int> pop_seq;
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            pop_seq.push(num);
        }

        // push
        for(int j = 1; j <= N; j++){
            // check size
            if(s.size() >= M){
                break;
            }
            s.push(j);
            // try pop
            while(!pop_seq.empty() && !s.empty() && s.top() == pop_seq.front()){
                s.pop();
                pop_seq.pop();
            }
        }

        // output
        if(pop_seq.empty() && s.empty()){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}