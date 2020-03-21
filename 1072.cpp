#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// 无坑，时间复杂度要求不高。
//  把Gas Station也作为City即可，前N为住宅，后M个为Gas Station，然后作Dijstara算法
//  一共做M次Dijstara算法即可（M < 10）
//  然后结束之后统计对应的信息即可

class Road{
public:
    int id;
    int dis;
public:
    Road(int i, int d){
        id = i;
        dis = d;
    }
};

class Node{
public:
    vector<Road *> roads;
    bool visited = true;
    int distance = -1;

public:
    void add_road(int id, int dis){
        Road *r = new Road(id, dis);
        roads.push_back(r);
    }

};

int main(){
    int N, M, K, D;
    cin >> N >> M >> K >> D;

    Node nodes[N + M];
    for(int i = 0; i < K; i++){
        string s1, s2;
        int dis;
        cin >> s1 >> s2 >> dis;

        int id1, id2;
        if(s1[0] == 'G'){
            id1 = N + stoi(s1.substr(1)) - 1;
        } else {
            id1 = stoi(s1) - 1;
        }
        if(s2[0] == 'G'){
            id2 = N + stoi(s2.substr(1)) - 1;
        } else {
            id2 = stoi(s2) - 1;
        }
        nodes[id1].add_road(id2, dis);
        nodes[id2].add_road(id1, dis);
    }

    // visit
    int choose_id = -1, min_dis = 0, min_total_dis = 0;
    for(int begin = N; begin < N + M; begin++){
        for(int i = 0; i < N + M; i++){
            nodes[i].visited = false;
            nodes[i].distance = -1;
        }
        int cur_id = begin;
        nodes[cur_id].distance = 0;

        bool can = true;
        while(true){
            // update
            nodes[cur_id].visited = true;
            if(cur_id < N && nodes[cur_id].distance > D){
                can = false;
                break;
            }
            for(int i = 0; i < nodes[cur_id].roads.size(); i++){
                int another_id = nodes[cur_id].roads[i]->id, dis = nodes[cur_id].roads[i]->dis;
                if(!nodes[another_id].visited){
                    if(nodes[another_id].distance == -1 || nodes[another_id].distance > nodes[cur_id].distance + dis){
                        nodes[another_id].distance = nodes[cur_id].distance + dis;
                    }
                }
            }

            int min_id = -1;
            for(int i = 0; i < N + M; i++){
                if(!nodes[i].visited && nodes[i].distance != -1){
                    if(min_id == -1 || nodes[i].distance < nodes[min_id].distance){
                        min_id = i;
                    }
                }
            }

            if(min_id == -1){
                break;
            }
            cur_id = min_id;
        }

        if(!can){
            continue;
        }

        int cur_min_dis = -1, total_dis = 0;
        for(int i = 0; i < N; i++){
            if(!nodes[i].visited){
                can = false;
                break;
            }
            if(cur_min_dis == -1 || nodes[i].distance < cur_min_dis){
                cur_min_dis = nodes[i].distance;
            }
            total_dis = total_dis + nodes[i].distance;
        }
        if(!can){
            continue;
        }

        if(choose_id == -1 || (cur_min_dis > min_dis) || (cur_min_dis == min_dis && total_dis < min_total_dis)){
            choose_id = begin;
            min_dis = cur_min_dis;
            min_total_dis = total_dis;
        }
    }

    if(choose_id == -1){
        cout << "No Solution" << endl;
    } else {
        cout << "G" << choose_id - N + 1 << endl;
        cout << setiosflags(ios::fixed) << setprecision(1) << min_dis * 1.0 << " " << round(10 * min_total_dis * 1.0 / N) / 10.0 << endl;
    }
}