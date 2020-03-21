#include <iostream>
#include <vector>

using namespace std;

// 无坑。DFS比较方便，BFS比较快

class Node{
public:
    vector<int> nodes;
};

double min_price = -1;
int min_count = 0;

void visit(double p, double r, Node nodes[], int id){
    if(nodes[id].nodes.empty()){
        if(min_price == -1 || p < min_price){
            min_price = p;
            min_count = 1;
        } else if(min_price == p){
            min_count++;
        }
    } else {
        for(int i = 0; i < nodes[id].nodes.size(); i++){
            visit(p * (1 + r / 100), r, nodes, nodes[id].nodes[i]);
        }
    }
}

int main(){
    int N;
    double price, r;
    cin >> N >> price >> r;

    Node nodes[N];
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        for(int j = 0; j < K; j++){
            int s;
            cin >> s;
            nodes[i].nodes.push_back(s);
        }
    }

    visit(price, r, nodes, 0);
    printf("%.4lf %d\n", min_price, min_count);
}