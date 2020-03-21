#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

// 注意点：
//      1、超过两个小时的，都调整为两个小时
//      2、桌子分配规则
//          （1） 有VIP，且有VIP桌子，优先分配
//          （2） 否则找到最先到达的，然后找到编号最小的桌子分配
//      3、存储：
//          （1）未到的玩家（优先队列），到了的VIP（队列），到了的普通玩家（队列）
//          （2）忙碌的桌子（优先队列，离开时间），空闲的VIP桌子，空闲的普通桌子（整数的优先队列）

using namespace std;

string time_str(int t){
    int h = t / 3600 + 8, m = (t / 60) % 60, s = t % 60;
    string str = "";
    if(h < 10){
        str += "0";
    }
    str = str + to_string(h) + ":";
    if(m < 10){
        str += "0";
    }
    str = str + to_string(m) + ":";
    if(s < 10){
        str += "0";
    }
    str = str + to_string(s);
    return str;
}

class Player{
public:
    string arrive_time_str;
    int arrive_time;
    int play_time;
    bool vip;

    int waiting_time;
public:
    Player(string arr_str, int t, bool vip){
        arrive_time_str = arr_str;
        if(t > 120) t = 120;
        play_time = t * 60;
        waiting_time = 0;
        int h = stoi(arr_str.substr(0, 2)), m = stoi(arr_str.substr(3, 2)), s = stoi(arr_str.substr(6, 2));
        arrive_time = (h - 8) * 3600 + m * 60 + s;
        this->vip = vip;
    }
    void output() const {
        cout << arrive_time_str << " " << time_str(arrive_time + waiting_time) << " ";
        cout << setiosflags(ios::fixed) << setprecision(0) << round(waiting_time / 60.0) << endl;
    }
    bool operator < (const Player & p ) const {
        return arrive_time_str > p.arrive_time_str;
    }
};

class Table{
public:
    int id;
    bool vip;
    int leave_time;

    int count;
public:
    Table(){
        this->id = 0;
        this->vip = false;
        this->leave_time = -1;
        count = 0;
    }
    bool operator < (const Table & t ) const {
        return leave_time > t.leave_time;
    }
    void increase(){
        count++;
    }
};


queue<Player> arrive_vip, arrive_cus;
priority_queue<Player> all_players;

priority_queue<int, vector<int>, greater<int>> free_table, vip_free_table;
priority_queue<Table> busy_table;

void player_leave(int t){
    while(!busy_table.empty()){
        if(busy_table.top().leave_time <= t){
            if(busy_table.top().vip){
                vip_free_table.push(busy_table.top().id);
            } else {
                free_table.push(busy_table.top().id);
            }
            busy_table.pop();
        } else{
            break;
        }
    }
}

void player_arrive(int t){
    while(!all_players.empty()){
        if(all_players.top().arrive_time <= t){
            Player p = all_players.top();
            if(p.vip){
                arrive_vip.push(p);
            } else {
                arrive_cus.push(p);
            }
            all_players.pop();
        } else {
            break;
        }
    }
}

void player_play(int t, Table tables[]){
    while(!arrive_cus.empty() || !arrive_vip.empty()){
        if(vip_free_table.empty() && free_table.empty()){
            break;
        }
        priority_queue<int, vector<int>, greater<int>> *table_queue = &vip_free_table;
        queue<Player> *player_queue = &arrive_vip;
        if(arrive_vip.empty() || vip_free_table.empty()){
            // Get table
            if(vip_free_table.empty()){
                table_queue = &free_table;
            } else if(free_table.empty()){
                table_queue = &vip_free_table;
            } else {
                if(vip_free_table.top() < free_table.top()){
                    table_queue = &vip_free_table;
                } else{
                    table_queue = &free_table;
                }
            }
            if(arrive_vip.empty()){
                player_queue = &arrive_cus;
            } else if(arrive_cus.empty()){
                player_queue = &arrive_vip;
            } else {
                if(arrive_vip.front().arrive_time < arrive_cus.front().arrive_time){
                    player_queue = &arrive_vip;
                } else {
                    player_queue = &arrive_cus;
                }
            }
        }
        int table_idx = table_queue->top();
        table_queue->pop();
        Table &table = tables[table_idx];
        table.increase();

        Player p = player_queue->front();
        player_queue->pop();
        p.waiting_time = t - p.arrive_time;
        p.output();

        table.leave_time = t + p.play_time;
        busy_table.push(table);
    }
}

int next_time(){
    int time = -1;
    if(!all_players.empty()){
        time = all_players.top().arrive_time;
    }
    if(!busy_table.empty()){
        if(time == -1){
            time = busy_table.top().leave_time;
        } else if(busy_table.top().leave_time < time){
            time = busy_table.top().leave_time;
        }
    }
    return time;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string arr_str;
        int t, vip;
        cin >> arr_str >> t >> vip;
        Player *p = nullptr;
        p = new Player(arr_str, t, vip == 1);
        all_players.push(*p);
    }
    int K, M;
    cin >> K >> M;
    Table tables[K];
    for(int i = 0; i < K; i++){
        tables[i].id = i;
    }
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        tables[t-1].vip = true;
    }
    for(int i = 0; i < K; i++){
        if(tables[i].vip){
            vip_free_table.push(i);
        } else {
            free_table.push(i);
        }
    }
    // begin calculate
    int current_t = 0;
    while(!arrive_cus.empty() || !arrive_vip.empty() || !all_players.empty()){
        player_leave(current_t);
        player_arrive(current_t);
        player_play(current_t, tables);
        current_t = next_time();
        if(current_t == -1 || current_t >= 13 * 3600){
            break;
        }
    }
    // output
    for(int i = 0; i < K; i++){
        if(i != 0) cout << " ";
        cout << tables[i].count;
    }
}