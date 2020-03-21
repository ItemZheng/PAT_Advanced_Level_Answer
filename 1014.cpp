#include <iostream>
#include <queue>

using namespace std;

// 注意点：
//      1、超过17:00的顾客不服务，但是17:00前到达的顾客还是要服务的
//      2、当前时间超过17:00就不再排队即可，并且清空队伍

class Customers{
public:
    int serve_time;
    int leave_time;
};

class Line{
public:
    queue<int> customers;
    int done_time;
};

int main(){
    int M, N, K, Q;
    cin >> N >> M >> K >> Q;
    Customers customers[K];
    Line lines[N];
    for(int i = 0; i < K; i++){
        cin >> customers[i].serve_time;
        customers[i].leave_time = -1;
    }

    // init
    int cur_c = 0, cur_t = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(cur_c < K){
                lines[j].customers.push(cur_c);
                cur_c++;
            } else {
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(!lines[i].customers.empty()){
            lines[i].done_time = customers[lines[i].customers.front()].serve_time;
        }
    }

    // begin server
    while(true){
        int early_done_line = -1;
        for(int i = 0; i < N; i++){
            if(!lines[i].customers.empty()){
                if(early_done_line == -1){
                    early_done_line = i;
                } else{
                    if(lines[i].done_time < lines[early_done_line].done_time){
                        early_done_line = i;
                    }
                }
            }
        }
        if(early_done_line == -1){
            break;
        }

        // Update done time
        cur_t = lines[early_done_line].done_time;
        customers[lines[early_done_line].customers.front()].leave_time = cur_t;
        lines[early_done_line].customers.pop();
        if(cur_c < K && cur_t < 540){
            lines[early_done_line].customers.push(cur_c);
            cur_c++;
        }
        if(!lines[early_done_line].customers.empty()){
            if(cur_t >= 540){
                while (!lines[early_done_line].customers.empty()){
                    lines[early_done_line].customers.pop();
                }
            } else {
                lines[early_done_line].done_time += customers[lines[early_done_line].customers.front()].serve_time;
            }
        }
    }

    // Serve done
    for(int i = 0; i < Q; i++){
        int c;
        cin >> c;
        int leave_time = customers[c - 1].leave_time;
        if(leave_time == -1){
            cout << "Sorry" << endl;
        } else {
            if(8 + leave_time / 60 < 10){
                cout << 0;
            }
            cout << 8 + leave_time / 60 << ":";
            if(leave_time % 60 < 10){
                cout << 0;
            }
            cout << leave_time % 60 << endl;
        }
    }

}