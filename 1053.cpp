#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑
//      1、首先读取树的信息，vector保存，Node内只要保存children的id和weight即可
//      2、将孩子排序，以符合顺序输出
//      3、递归遍历

class Node;
bool com(int x, int y);

vector<Node *> nodes;
vector<int> Path;

void Print(){
    cout << Path[0];
    for(int i = 1; i < Path.size(); i++){
        cout << " " << Path[i];
    }
    cout << endl;
}

class Node{
public:
    vector<int> children;
    int weight;
public:
    Node(int w){
        weight = w;
    }

    void Sort(){
        sort(children.begin(), children.end(), com);
        for(int i = 0; i < children.size(); i++){
            nodes[children[i]]->Sort();
        }
    }

    void visit(int sum, int target){
        if(children.size() == 0 && sum + weight == target){
            Path.push_back(weight);
            Print();
            Path.pop_back();
        }
        if(children.size() != 0){
            if(sum + weight > target){
                return;
            } else {
                Path.push_back(weight);
                for(int i = 0; i < children.size(); i++){
                    nodes[children[i]]->visit(sum + weight, target);
                }
                Path.pop_back();
            }
        }
    }
};

bool com(int x, int y){
    return nodes[x]->weight > nodes[y]->weight;
}

int main(){
    int N, M, S;
    cin >> N >> M >> S;

    for(int i = 0; i < N; i++){
        int w;
        cin >> w;
        Node *n = new Node(w);
        nodes.push_back(n);
    }

    for(int i = 0; i < M; i++){
        int id, K;
        cin >> id >> K;
        for(int j = 0; j < K; j++){
            int c;
            cin >> c;
            nodes[id]->children.push_back(c);
        }
    }

    nodes[0]->Sort();
    nodes[0]->visit(0, S);
}