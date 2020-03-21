#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

#define OFF_LINE 0
#define ON_LINE 1

using namespace std;

// 注意点：
//      1、注意是所有的记录中至少有一个配对的记录
//      2、不产生消费的记录不输出

int rates[24];

class Record{
public:
    string time;
    int type;
    int day;
    int hour;
    int minute;
public:
    Record(string time, int type){
        this->type = type;
        this->time = time;
        this->day = stoi(time.substr(3, 2));
        this->hour = stoi(time.substr(6, 2));
        this->minute = stoi(time.substr(9, 2));
    }

    string getFormatStr(){
        return time.substr(3);
    }

    string getMonth(){
        return time.substr(0, 2);
    }
};

bool sort_record(Record *r1, Record *r2){
    return r1->time > r2->time;
}

pair<int, int> calculate_bill(Record *r1, Record *r2){
    int day = 0, hour = 0, min = 0;
    min = r2->minute - r1->minute;
    if(min < 0){
        min = min + 60;
        hour--;
    }
    hour = hour + r2->hour - r1->hour;
    if(hour < 0){
        hour = hour + 24;
        day--;
    }
    day = day + r2->day - r1->day;
    int total_min = day * 24 * 60 + hour * 60 + min;
    int total = total_min;
    int cur_c = r1->hour, bill = - rates[cur_c] * r1->minute;
    total_min = total_min + r1->minute;
    while(total_min > 0){
        int count = 0;
        count = total_min >= 60 ? 60 : total_min;
        bill = bill + count * rates[cur_c];
        total_min = total_min - count;
        cur_c = (cur_c + 1) % 24;
    }

    return make_pair(total, bill);
}

int main(){
    // Inputs
    for(int i = 0; i < 24; i++){
        cin >> rates[i];
    }
    int N;
    cin >> N;
    map<string, vector<Record *> *> name_record_maps;
    for(int i = 0; i < N; i++){
        string name, time, type;
        cin >> name >> time >> type;
        Record * record;
        if(type == "on-line"){
            record = new Record(time, ON_LINE);
        }else{
            record = new Record(time, OFF_LINE);
        }
        if(name_record_maps.count(name) == 0){
            vector<Record *> *records = new vector<Record*>();
            records->push_back(record);
            name_record_maps[name] = records;
        } else {
            name_record_maps[name]->push_back(record);
        }
    }

    // Sort By Name
    for(map<string, vector<Record *> *>::iterator it = name_record_maps.begin(); it != name_record_maps.end(); it++){
        string name = it->first;
        vector<Record *>* records = it->second;
        sort(records->begin(), records->end(), sort_record);
        bool output = false;
        int total = 0;
        while(!records->empty()){
            // Online
            Record *r1 = records->back();
            records->pop_back();
            if(r1->type == OFF_LINE){
                continue;
            }

            if(records->empty()){
                break;
            }
            Record *r2 = records->back();
            if(r2->type == ON_LINE){
                continue;
            }
            // r1: OnLine r2: Offline
            records->pop_back();

            pair<int, int> res = calculate_bill(r1, r2);
            int bill = res.second, minites = res.first;
            total = total + bill;
            if(!output){
                cout << name << " " << records[0].front()->getMonth() << endl;
                output = true;
            }
            cout << r1->getFormatStr() << " " << r2->getFormatStr() << " ";
            cout << minites << " " << "$" << setiosflags(ios::fixed) << setprecision(2) << bill / 100.0 << endl;
        }
        if(output){
            cout << "Total amount: " << "$" << setiosflags(ios::fixed) << setprecision(2) << total / 100.0 << endl;
        }
    }
    return 0;
}
