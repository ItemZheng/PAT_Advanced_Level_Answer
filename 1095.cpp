#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <queue>

// 注意时间复杂度。
//  1、注意他查询的次数很多，如果记录查询的时间，然后遍历所有的车判断，时间复杂度是来不及的。
//  2、本题要先根据 车牌号 > 时间 的方式排序，然后组成完整的停车记录
//  3、然后将完整的记录根据进入时间排序
//  4、根据离开时间排序（用优先队列实现）
//  5、到查询时间之后，先将能进入的车进入，然后将能出去的车出去，最后直接输出优先队列的size

using namespace std;

class Record{
public:
    string plate_number;
    int time;
    int status;
    bool deleted = false;
public:
    Record(){
        status = 0;
    }
};

bool cmp(Record &r1, Record &r2){
    if(r1.plate_number != r2.plate_number){
        return r1.plate_number < r2.plate_number;
    }
    return r1.time < r2.time;
}

int trans_time(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

class Cars{
public:
    string plate_number;
    int in_time, leave_time;
    int stay_second = 0;
public:
    void calculate_stay_times(){
        stay_second = leave_time - in_time;
    }

    bool operator < (const Cars * c) const {
        return leave_time > c->leave_time;
    }
};

bool cmp_car(Cars *c1, Cars *c2){
    return c1->in_time < c2->in_time;
}

vector<Cars *> pair_cars;
priority_queue<int, vector<int>, greater<int>> campus_cars;

int next_car = 0;

void car_in(int time){
    while(next_car < pair_cars.size() && pair_cars[next_car]->in_time <= time){
        campus_cars.push(pair_cars[next_car]->leave_time);
        next_car++;
    }
}

void car_leaves(int time){
    while(!campus_cars.empty() && campus_cars.top() <= time){
        campus_cars.pop();
    }
}

int main(){
    int N, K;
    cin >> N >> K;

    Record records[N];
    for(int i = 0; i < N; i++){
        string timeStr, s;
        cin >> records[i].plate_number >> timeStr >> s;
        records[i].time = trans_time(timeStr);
        if(s == "in"){
            records[i].status = 0;
        } else {
            records[i].status = 1;
        }
    }
    vector<int> query_times;
    for(int i = 0; i < K; i++){
        string timeStr;
        cin >> timeStr;
        query_times.push_back(trans_time(timeStr));
    }

    // sort
    sort(records, records + N, cmp);
    unordered_map<string, int> car_stay_time_map;
    int max_time = 0;
    vector<string> max_cars;
    for(int i = 0; i < N - 1; i++){
        if(!records[i].deleted && records[i].status == 0){
            if(records[i].plate_number == records[i + 1].plate_number && records[i + 1].status == 1){
                records[i + 1].deleted = true;
                Cars *car = new Cars();
                car->plate_number = records[i].plate_number;
                car->leave_time = records[i + 1].time;
                car->in_time = records[i].time;
                car->calculate_stay_times();
                pair_cars.push_back(car);
                if(car_stay_time_map.count(car->plate_number) > 0){
                    car_stay_time_map[car->plate_number] = car_stay_time_map[car->plate_number] + car->stay_second;
                } else {
                    car_stay_time_map[car->plate_number] = car->stay_second;
                }
                if(car_stay_time_map[car->plate_number] > max_time){
                    max_cars.clear();
                    max_time = car_stay_time_map[car->plate_number];
                    max_cars.push_back(car->plate_number);
                } else if(car_stay_time_map[car->plate_number] == max_time){
                    max_cars.push_back(car->plate_number);
                }
            }
        }
    }
    sort(pair_cars.begin(), pair_cars.end(), cmp_car);

    // 模拟
    for(int i = 0; i < K; i++){
        car_in(query_times[i]);
        car_leaves(query_times[i]);
        cout << campus_cars.size() << endl;
    }

    for(int i = 0; i < max_cars.size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << max_cars[i];
    }
    cout << " " << setw(2) << setfill('0') << max_time / 3600 << ":";
    cout << setw(2) << setfill('0') << (max_time % 3600) / 60 << ":";
    cout << setw(2) << setfill('0') << max_time % 60 << endl;
}