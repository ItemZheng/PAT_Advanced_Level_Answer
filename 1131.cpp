#include <iostream>
#include <vector>

using namespace std;

class Road{
public:
    int id;
    int No;
public:
    Road(int i, int n){
        id = i;
        No = n;
    }
};

class Node{
public:
    bool visited = false;
    int distance = -1;
    Road *lastRoad = nullptr;
    vector<Road> roads;
public:
    void add_road(int id, int No){
        Road *r = new Road(id, No);
        roads.push_back(*r);
    }
};

int main(){
    Node all_nodes[10001];

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int K, last = -1;
        cin >> K;
        for(int j = 0; j < K; j++){
            if(last == -1){
                cin >> last;
            } else {
                int l;
                cin >> l;

                all_nodes[l].add_road(last, i + 1);
                all_nodes[last].add_road(l, i + 1);
                last = l;
            }
        }
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int begin, end;
        cin >> begin >> end;

        all_nodes[begin].visited = true;

    }
}