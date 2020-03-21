#include <iostream>
#include <cstring>

using namespace std;

// 注意点：题目没有说一定是连接图。

int rootOf(int graph[], int id){
    while(graph[id] >= 0){
        id = graph[id];
    }
    return id;
}

int main(){
    int N, M;
    cin >> N >> M;

    // read in and get graph
    int degree[N], graph[N];
    memset(degree, 0, sizeof(int) * N);
    memset(graph, -1, sizeof(int) * N);
    for(int i = 0; i < M; i++){
        int l1, l2;
        cin >> l1 >> l2;
        degree[l1 - 1] ++;
        degree[l2 - 1] ++;
        int r1 = rootOf(graph, l1 - 1), r2 = rootOf(graph, l2 - 1);
        if(r1 != r2){
            graph[r1] = r2;
        }
    }

    // judge connected
    int even_num = 0, odd_num = 0, count = 0;
    bool connected = true;
    for(int i = 0; i < N; i++){
        if(graph[i] < 0){
            count++;
        }
        if(count > 1){
            connected = false;
            break;
        }
    }

    // judge degree
    for(int i = 0; i < N; i++){
        if(degree[i] % 2 == 0){
            even_num++;
        } else {
            odd_num++;
        }
        if(i > 0){
            cout << " ";
        }
        cout << degree[i];
    }
    cout << endl;

    // output
    if(!connected){
        cout << "Non-Eulerian" << endl;
    } else if(even_num == N){
        cout << "Eulerian" << endl;
    } else if(odd_num == 2){
        cout << "Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }
}