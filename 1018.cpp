#include <iostream>
#include <vector>

using namespace std;

// 注意点：
//      1、遇到最短路径，首先用Dijistra算法，以及保存所有的最短的路径
//      2、用递归的方式判断所有的合法路径哪个是Best
//      3、注意最优的评判指标（本题）：
//          最短时间 > 需要从PBMC带出来的车辆 > 需要带回PBMC的车辆
//      4、注意坑点：前面沿途的点多出来的能补充后面的点，后面的点多出来不能补充前面的点，因此需要按顺序递归遍历，从0开始

int C_MAX = 0;

int min_need = -1, min_need_back = -1;
vector<int> min_path, path;

class Road{
public:
    int id, time;
public:
    Road(int id, int time){
        this->time = time;
        this->id = id;
    }
};

class Station{
public:
    int cap;
    vector<Road> roads;
    int need;
    int need_back;

    // visit need
    bool visited;
    int min_time;
    vector<int> path;
public:
    Station(){
        cap = C_MAX / 2;
        need = 0;
        need_back = 0;

        visited = false;
        min_time = -1;
    }

    void add_road(int another_id, int time){
        Road *r = new Road(another_id, time);
        roads.push_back(*r);
    }

    void update(int time, int last_id){
        if(visited){
            return;
        }
        if(min_time == -1 || time == min_time){
            min_time = time;
            path.push_back(last_id);
        }
        if(min_time > time){
            path.clear();
            min_time = time;
            path.push_back(last_id);
        }
    }
};

void judge_path(int id, int need, int need_back, Station stations[], int Sp){
    path.push_back(id);
    int cur_need = stations[id].need, cur_need_back = stations[id].need_back;
    need_back = need_back + cur_need_back - cur_need;
    if(need_back < 0){
        need = need - need_back;
        need_back = 0;
    }
    if(id == Sp){
        // judge
        if(min_need == -1 || need < min_need || (need == min_need && need_back < min_need_back)){
            min_need_back = need_back;
            min_need = need;
            min_path.clear();
            for(int i = 0; i < path.size(); i++){
                min_path.push_back(path[i]);
            }
        }
    } else {
        for(int i = 0; i < stations[id].path.size(); i++){
            judge_path(stations[id].path[i], need, need_back, stations, Sp);
        }
    }

    path.pop_back();
}

int main(){
    // read in
    int N, Sp, M;
    cin >> C_MAX >> N >> Sp >> M;
    Station stations[N+1];
    for(int i = 0; i < N; i++){
        cin >> stations[i+1].cap;
        if(stations[i+1].cap > C_MAX / 2){
            stations[i+1].need_back = stations[i+1].cap - C_MAX / 2;
        } else {
            stations[i+1].need = C_MAX / 2 - stations[i+1].cap;
        }
    }

    // road
    for(int i = 0; i < M; i++){
        int s1, s2, time;
        cin >> s1 >> s2 >> time;
        stations[s1].add_road(s2, time);
        stations[s2].add_road(s1, time);
    }

    // find from Sp
    stations[Sp].visited = true;
    stations[Sp].min_time = 0;

    int cur_id = Sp;
    while(true){
        // update all neighbour
        for(int i = 0; i < stations[cur_id].roads.size(); i++){
            Road r = stations[cur_id].roads[i];
            int another_id = r.id;
            stations[another_id].update(stations[cur_id].min_time + r.time, cur_id);
        }

        // find next id
        int min_id = -1;
        for(int i = 0; i < N + 1; i++){
            if(!stations[i].visited && stations[i].min_time != -1){
                if(min_id == -1){
                    min_id = i;
                } else if(stations[i].min_time < stations[min_id].min_time){
                    min_id = i;
                }
            }
        }
        if(min_id == -1){
            break;
        }
        stations[min_id].visited = true;
        cur_id = min_id;
        if(min_id == 0){
            break;
        }
    }

    // find best road
    judge_path(0, 0, 0, stations, Sp);

    cout << min_need << " ";
    cout << "0";
    for(int i = 0; i < min_path.size() - 1; i++){
        cout << "->" << min_path[i+1];
    }
    cout << " " << min_need_back << endl;
}