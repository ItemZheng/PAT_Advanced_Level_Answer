#include <iostream>
#include <vector>

// 注意点：只要将lose city去掉之后，然后计算剩下的城市有几个set就可以

using namespace std;

class Edge{
public:
    int v1, v2;
public:
    Edge(int v1, int v2){
        this->v1 = v1 - 1;
        this->v2 = v2 - 1;
    }
};

int root_of(int city_set[], int i){
    while (city_set[i] >= 0){
        i = city_set[i];
    }
    return i;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    vector<Edge *> edges;
    for(int i = 0; i < M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        Edge * e = new Edge(v1, v2);
        edges.push_back(e);
    }

    // K cases
    for(int i = 0; i < K; i++){
        int city_set[N];
        for(int j = 0; j < N; j++){
            city_set[j] = -1;
        }

        int lose_city;
        cin >> lose_city;
        lose_city--;

        // Merge City
        for(int j = 0; j < edges.size(); j++){
            Edge *e = edges[j];
            if(e->v1 == lose_city || e->v2 == lose_city){
                continue;
            }

            int r1 = root_of(city_set, e->v1), r2 = root_of(city_set, e->v2);
            if(r1 == r2){
                continue;
            }
            city_set[r2] = r1;
        }

        int count = 0;
        for(int j = 0; j < N; j++){
            if(city_set[j] < 0){
                count++;
            }
        }
        cout << count - 2 << endl;
    }

}