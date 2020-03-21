#include <iostream>
#include <vector>

// 注意点：
//  看清楚题目，题目的输出一个是最短路径的条数，另一个是能召集的最大team数，
//  是一条最短路径的沿途最大team数，而不是所有最短路径的沿途team数

using namespace std;

class Road {
public:
    int id;
    int length;
public:
    Road(int id, int length) {
        this->id = id;
        this->length = length;
    }
};

class City {
public:
    // info
    int id;
    int teams_num;
    vector<Road*> roads;

    // visit
    bool visited;
    int distance;
    bool backup;
    int count = 0;
    int gather_team = 0;
public:
    void addRoad(int c, int l){
        Road *road = new Road(c, l);
        roads.push_back(road);
    }
};

int main() {
    // read in
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;
    // teams_num
    City cities[N];
    for (int i = 0; i < N; i++) {
        cities[i].id = i;
        cin >> cities[i].teams_num;
        cities[i].distance = -1;
        cities[i].visited = false;
        cities[i].backup = false;
    }
    // roads
    for (int i = 0; i < M; ++i) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        cities[c1].addRoad(c2, l);
        cities[c2].addRoad(c1, l);
    }

    // from C1 to C2
    cities[C1].distance = 0;
    cities[C1].visited = true;
    cities[C1].gather_team = cities[C1].teams_num;
    cities[C1].count = 1;
    // update all point connect to C1
    for(int i = 0; i < cities[C1].roads.size(); i++){
        Road *r = cities[C1].roads[i];
        cities[r->id].distance = r->length;
        cities[r->id].gather_team = cities[C1].teams_num + cities[r->id].teams_num;
        cities[r->id].count = cities[C1].count;
    }

    // traversal
    while(true){
        // find min
        int min_id = -1, dis = -1;
        for(int i = 0; i < N; i++){
            if(!cities[i].visited && cities[i].distance != -1){
                if(min_id == -1){
                    min_id = i;
                    dis = cities[i].distance;
                } else {
                    if(cities[i].distance < dis){
                        min_id = i;
                        dis = cities[i].distance;
                    }
                }
            }
        }
        if(min_id == -1 || min_id == C2){
            break;
        }

        // update all connected id
        cities[min_id].visited = true;
        for(int i = 0; i < cities[min_id].roads.size(); i++){
            Road *r = cities[min_id].roads[i];
            if(cities[r->id].visited){
                continue;
            }
            if(cities[r->id].distance == -1){
                cities[r->id].distance = cities[min_id].distance + r->length;
                cities[r->id].count = cities[min_id].count;
                cities[r->id].gather_team = cities[min_id].gather_team + cities[r->id].teams_num;
            } else if(cities[r->id].distance > cities[min_id].distance + r->length){
                cities[r->id].distance = cities[min_id].distance + r->length;
                cities[r->id].count = cities[min_id].count;
                cities[r->id].gather_team = cities[min_id].gather_team + cities[r->id].teams_num;
            } else if(cities[r->id].distance == cities[min_id].distance + r->length){
                cities[r->id].count += cities[min_id].count;
                if(cities[min_id].gather_team + cities[r->id].teams_num > cities[r->id].gather_team)
                    cities[r->id].gather_team = cities[min_id].gather_team + cities[r->id].teams_num;
            }
        }
    }
    cout << cities[C2].count << " " << cities[C2].gather_team << endl;
}