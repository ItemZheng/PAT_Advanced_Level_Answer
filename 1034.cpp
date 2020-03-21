#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

// 注意点: 注意题目，一个Gang的定义是 1、集体的通话时长大于K   2、通话的人数要大于2【容易忘】
//        使用合并集合的思想，在合并的同时更新相关的信息
//        多使用Map，比较方便

using namespace std;
class Person;

map<string, int> name_id_map;
vector<Person> persons;
map<int, int> valid_gang;

class Person{
public:
    string name;
    int conn = -1;
    int total_weight = 0;

    int count = 0;
    int gang_weight = 0;
public:
    Person(string n){
        conn = -1;
        total_weight = 0;
        name = n;
        count = 0;
    }
};

class Gang{
public:
    int r;
    int p;
public:
    Gang(int r, int p){
        this->r = r;
        this->p = p;
    }

    bool operator < (const Gang & g) const {
        return persons[p].name > persons[g.p].name;
    }
};


int rootOf(int p){
    while(persons[p].conn >= 0){
        p = persons[p].conn;
    }
    return p;
}

void merge(int p1, int p2, int w){
    int r1 = rootOf(p1), r2 = rootOf(p2);
    if(r1 != r2){
        persons[r2].conn = r1;
        persons[r1].count += persons[r2].count;
        persons[r1].gang_weight += persons[r2].gang_weight;
    }
    persons[r1].gang_weight += w;
}

priority_queue<Gang> gangs;

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string n1, n2;
        int w;
        cin >> n1 >> n2 >> w;
        if(name_id_map.count(n1) == 0){
            name_id_map[n1] = persons.size();
            Person *p = new Person(n1);
            p->count = 1;
            persons.push_back(*p);
        }
        if(name_id_map.count(n2) == 0){
            name_id_map[n2] = persons.size();
            Person *p = new Person(n2);
            p->count = 1;
            persons.push_back(*p);
        }
        int id1 = name_id_map[n1], id2 = name_id_map[n2];
        persons[id1].total_weight += w;
        persons[id2].total_weight += w;
        merge(id1, id2, w);
    }

    // get valid gang
    for(int i = 0; i < persons.size(); i++){
        int r = rootOf(i);
        if(persons[r].gang_weight > K && persons[r].count > 2){
            if(valid_gang.count(r) == 0){
                valid_gang[r] = i;
            } else {
                if(persons[i].total_weight > persons[valid_gang[r]].total_weight){
                    valid_gang[r] = i;
                }
            }
        }
    }
    for(map<int, int> ::iterator it = valid_gang.begin(); it != valid_gang.end(); it++){
        Gang * g = new Gang(it->first, it->second);
        gangs.push(*g);
    }

    cout << gangs.size() << endl;
    while(!gangs.empty()){
        Gang g = gangs.top();
        gangs.pop();
        cout << persons[g.p].name << " " << persons[g.r].count << endl;
    }
}