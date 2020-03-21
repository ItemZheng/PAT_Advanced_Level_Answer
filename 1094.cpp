#include <iostream>
#include <vector>

using namespace std;

// 无坑。统计每一层的人数，DFS即可。

int level_counts[101];

class Node{
public:
    vector<int> children;
public:
    Node(){}

    void visit(Node nodes[], int level){
        level_counts[level]++;
        for(int i = 0; i < children.size(); i++){
            nodes[children[i]].visit(nodes, level + 1);
        }
    }
};

int main(){
    for(int i = 0; i < 101; i++){
        level_counts[i] = 0;
    }

    int N, M;
    cin >> N >> M;

    Node nodes[N + 1];
    for(int i = 0; i < M; i++){
        int parent;
        cin >> parent;
        int K;
        cin >> K;
        for(int j = 0; j < K; j++){
            int child;
            cin >> child;
            nodes[parent].children.push_back(child);
        }
    }

    nodes[1].visit(nodes, 1);

    int max_count = 0, max_level = 1;
    for(int i = 1; i < 101; i++){
        if(level_counts[i] > max_count){
            max_count = level_counts[i];
            max_level = i;
        }
    }
    cout << max_count << " " << max_level << endl;
}