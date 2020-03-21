#include <iostream>
#include <queue>

using namespace std;

// 无坑。由于越前面打结的绳子对折次数越多，因此越短的越先加入即可。用优先队列

int main(){
    priority_queue<int, vector<int>, greater<int>> heap_num;
    int N;

    cin >> N;
    for(int i = 0; i < N; i++){
        int l;
        cin >> l;
        heap_num.push(l);
    }

    for(int i = 0; i < N - 1; i++){
        int l1 = heap_num.top();
        heap_num.pop();
        int l2 = heap_num.top();
        heap_num.pop();
        heap_num.push((l1 + l2) / 2);
    }
    cout << heap_num.top() << endl;
}