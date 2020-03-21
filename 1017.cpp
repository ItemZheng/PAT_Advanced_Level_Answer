#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// 注意点：
//      8:00 之前到达的顾客也是需要计算等待时间的
//      流程 顾客离开，顾客到达，服务顾客，计算下个时间点
//      优先队列的使用

class Customer{
public:
    string arrival_time_str;
    int arrival_time;
    int waiting_time = 0;
    int serve_time;
public:
    Customer(string arrival_str, int serve_time){
        this->arrival_time_str = arrival_str;
        int hh = stoi(arrival_str.substr(0, 2));
        int mm = stoi(arrival_str.substr(3, 2));
        int ss = stoi(arrival_str.substr(6, 2));
        this->arrival_time = (hh - 8) * 3600 + 60 * mm + ss;
        if(this->arrival_time < 0){
            this->waiting_time = -1 * this->arrival_time;
            this->arrival_time = 0;
        } else {
            this->waiting_time = 0;
        }
        if(serve_time >= 60){
            serve_time = 60;
        }
        this->serve_time = serve_time * 60;
    }

    bool operator < (const Customer &c) const {
        return this->arrival_time > c.arrival_time;
    }
};

class Window{
public:
    int leave_time;
public:
    bool operator < (const Window &w) const {
        return this->leave_time > w.leave_time;
    }
};

priority_queue<Customer> customers;
queue<Customer> arrive_customers;
priority_queue<Window> busy_windows;
queue<Window> free_windows;

void customer_leaves(int t){
    while(!busy_windows.empty()){
        if(busy_windows.top().leave_time <= t){
            free_windows.push(busy_windows.top());
            busy_windows.pop();
        } else {
            break;
        }
    }
}

void customer_arrives(int t){
    while(!customers.empty()){
        if(customers.top().arrival_time <= t){
            arrive_customers.push(customers.top());
            customers.pop();
        } else{
            break;
        }
    }
}

int serve_customer(int t){
    int waiting = 0;
    while(!arrive_customers.empty() && !free_windows.empty()){
        Customer customer = arrive_customers.front();
        waiting += (t - customer.arrival_time + customer.waiting_time);
        arrive_customers.pop();

        Window w = free_windows.front();
        free_windows.pop();
        w.leave_time = t + customer.serve_time;
        busy_windows.push(w);
    }
    return waiting;
}

int next_time(){
    if(customers.empty()){
        if(!busy_windows.empty()){
            return busy_windows.top().leave_time;
        }
        return -1;
    }
    int min_time = customers.top().arrival_time;
    if(!busy_windows.empty()){
        if(busy_windows.top().leave_time < min_time){
            return busy_windows.top().leave_time;
        }
    }
    return min_time;
}

int main(){
    // important time :
    //  next leave time(window)
    //  next arrive time(customer)

    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string time;
        int server_time;
        cin >> time >> server_time;
        if(time <= "17:00:00"){
            Customer *customer = new Customer(time, server_time);
            customers.push(*customer);
        }
    }
    for(int i = 0; i < K; i++){
        Window *window = new Window();
        free_windows.push(*window);
    }

    int total_time = 0, total_count = customers.size();
    int current_time = 0;
    while(!customers.empty() || !arrive_customers.empty()){
        customer_leaves(current_time);
        customer_arrives(current_time);
        total_time += serve_customer(current_time);
        current_time = next_time();
    }

    cout << setiosflags(ios::fixed) << setprecision(1) << total_time / (60.0 * total_count) << endl;
}
