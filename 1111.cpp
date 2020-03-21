#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑。
//  1、先存地图，然后从begin开始遍历，两次dijistala找到路径
//  2、最后输出

class Road{
public:
    int id, time, distance;
public:
    Road(int i, int t, int d){
        id = i;
        time = t;
        distance = d;
    }
};

class Intersection{
public:
    vector<Road *> roads;
    int total_time = -1, distance = -1, path = -1, counts = 0;
    bool visited = false;
public:
    void add_road(int anotherId, int time, int dis){
        Road *r = new Road(anotherId, time, dis);
        roads.push_back(r);
    }
};

void output(vector<int> &path){
    for(int i = 0; i < path.size(); i++){
        if(i > 0){
            cout << " -> ";
        }
        cout << path[i];
    }
    cout << endl;
}

int main(){
    // read map
    int N, M;
    cin >> N >> M;
    Intersection intersections[N];
    for(int i = 0; i < M; i++){
        int id1, id2, one_way, dis, time;
        cin >> id1 >> id2 >> one_way >> dis >> time;
        intersections[id1].add_road(id2, time, dis);
        if(one_way == 0){
            intersections[id2].add_road(id1, time, dis);
        }
    }

    int begin, des;
    cin >> begin >> des;
    vector<int> short_path, fast_path;

    // distance
    intersections[begin].distance = 0;
    intersections[begin].total_time = 0;
    int cur_id = begin;
    while(true){
        intersections[cur_id].visited = true;
        // update
        for(int i = 0; i < intersections[cur_id].roads.size(); i++){
            int anotherId = intersections[cur_id].roads[i]->id, dis = intersections[cur_id].roads[i]->distance;
            int t = intersections[cur_id].roads[i]->time;
            if(!intersections[anotherId].visited){
                if(intersections[anotherId].distance == -1 ||
                intersections[anotherId].distance > intersections[cur_id].distance + dis ||
                (intersections[anotherId].distance == intersections[cur_id].distance + dis
                && intersections[anotherId].total_time > intersections[cur_id].total_time + t)){
                    intersections[anotherId].distance = intersections[cur_id].distance + dis;
                    intersections[anotherId].total_time = intersections[cur_id].total_time + t;
                    intersections[anotherId].path = cur_id;
                }
            }
        }

        // find min
        int min_id = -1;
        for(int i = 0; i < N; i++){
            if(!intersections[i].visited && intersections[i].distance != -1){
                if(min_id == -1 || intersections[i].distance < intersections[min_id].distance){
                    min_id = i;
                }
            }
        }
        if(min_id == -1 || min_id == des){
            break;
        }
        cur_id = min_id;
    }
    int idx = des;
    while(idx != -1){
        short_path.push_back(idx);
        idx = intersections[idx].path;
    }
    reverse(short_path.begin(), short_path.end());
    int min_dis = intersections[des].distance;

    // time
    for(int i = 0; i < N; i++){
        intersections[i].distance = -1;
        intersections[i].total_time = -1;
        intersections[i].visited = false;
        intersections[i].path = -1;
    }
    intersections[begin].total_time = 0;
    cur_id = begin;
    while(true){
        intersections[cur_id].visited = true;
        // update
        for(int i = 0; i < intersections[cur_id].roads.size(); i++){
            int anotherId = intersections[cur_id].roads[i]->id, dis = intersections[cur_id].roads[i]->distance;
            int t = intersections[cur_id].roads[i]->time;
            if(!intersections[anotherId].visited){
                if(intersections[anotherId].total_time == -1 ||
                   intersections[anotherId].total_time > intersections[cur_id].total_time + t ||
                   (intersections[anotherId].total_time == intersections[cur_id].total_time + t
                    && intersections[anotherId].counts > intersections[cur_id].counts + 1)){
                    intersections[anotherId].total_time = intersections[cur_id].total_time + t;
                    intersections[anotherId].path = cur_id;
                    intersections[anotherId].counts = intersections[cur_id].counts + 1;
                }
            }
        }

        // find min
        int min_id = -1;
        for(int i = 0; i < N; i++){
            if(!intersections[i].visited && intersections[i].total_time != -1){
                if(min_id == -1 || intersections[i].total_time < intersections[min_id].total_time){
                    min_id = i;
                }
            }
        }
        if(min_id == -1 || min_id == des){
            break;
        }
        cur_id = min_id;
    }
    idx = des;
    while(idx != -1){
        fast_path.push_back(idx);
        idx = intersections[idx].path;
    }
    reverse(fast_path.begin(), fast_path.end());
    int min_time = intersections[des].total_time;

    // same path
    bool same = fast_path.size() == short_path.size();
    if(same){
        for(int i = 0; i < fast_path.size(); i++){
            if(fast_path[i] != short_path[i]){
                same = false;
                break;
            }
        }
    }

    if(same){
        cout << "Distance = " << min_dis << "; ";
        cout << "Time = " << min_time << ": " ;
        output(fast_path);
    } else {
        cout << "Distance = " << min_dis << ": ";
        output(short_path);
        cout << "Time = " << min_time << ": " ;
        output(fast_path);
    }
}