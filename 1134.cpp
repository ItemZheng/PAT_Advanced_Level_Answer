#include <iostream>
#include <cstring>

using namespace std;

// 无坑。

class Edge{
public:
    int id1 = 0, id2 = 0;
};

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    // cin >> N >> M;
    Edge edges[M];
    for(int i = 0; i < M; i++){
        scanf("%d%d", &edges[i].id1, &edges[i].id2);
        // cin >> edges[i].id1 >> edges[i].id2;
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int Nv;
        cin >> Nv;

        int vertex[N];
        memset(vertex, 0, sizeof(int) * N);

        for(int j = 0; j < Nv; j++){
            int v;
            cin >> v;
            vertex[v] = 1;
        }

        bool yes = true;
        for(int j = 0; j < M; j++){
            if(vertex[edges[j].id1] == 0 && vertex[edges[j].id2] == 0){
                yes = false;
                break;
            }
        }
        if(yes){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}