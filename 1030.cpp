#include <iostream>
#include <vector>

// 无坑, 注意City的Update，参数尽量不要和类内的变量名一致

using namespace std;

class Road{
public:
    int id;
    int cost;
    int dis;
public:
    Road(int id, int dis, int cost){
        this->id = id;
        this->dis = dis;
        this->cost = cost;
    }
};

class City{
public:
    vector<Road> roads;

    // visit need
    int cost;
    int dis;
    int path;
    bool visit;
public:
    City(){
        visit = false;
        cost = 0;
        dis = -1;
        path = -1;
    }

    void update(int cost, int dis, int path){
        if(visit){
            return;
        }
        if(dis < this->dis || (dis == this->dis && cost < this->cost) || this->dis == -1){
            this->dis = dis;
            this->cost = cost;
            this->path = path;
        }
    }

    void addRoad(int i, int d, int c){
        Road * r = new Road(i, d, c);
        roads.push_back(*r);
    }
};

void output(int c, City cities[], int S){
    if(c == S){
        cout << c;
    } else {
        output(cities[c].path, cities, S);
        cout << " " << c;
    }
}

int main(){
    int N, M, S, D;
    cin >> N >> M >> S >> D;

    City cities[N];
    for(int i = 0; i < M; i++){
        int c1, c2, dis, cost;
        cin >> c1 >> c2 >> dis >> cost;
        cities[c1].addRoad(c2, dis, cost);
        cities[c2].addRoad(c1, dis, cost);
    }

    cities[S].visit = true;
    cities[S].dis = 0;
    cities[S].cost = 0;
    int cur_city = S;
    while(!cities[D].visit){
        // update all connect
        for(int i = 0; i < cities[cur_city].roads.size(); i++){
            Road r = cities[cur_city].roads[i];
            cities[r.id].update(cities[cur_city].cost + r.cost, cities[cur_city].dis + r.dis, cur_city);
        }

        // find small dis
        int min_id = -1;
        for(int i = 0; i < N; i++){
            if(!cities[i].visit && cities[i].dis != -1){
                if(min_id == -1 || (cities[i].dis < cities[min_id].dis)){
                    min_id = i;
                }
            }
        }
        if(min_id == -1 || min_id == D){
            break;
        }
        cur_city = min_id;
        cities[min_id].visit = true;
    }

    // output path
    output(D, cities, S);
    cout << " " << cities[D].dis << " " << cities[D].cost;
}

