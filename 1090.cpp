#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 无坑。本题从Root开始，是一棵树，所以可以用DFS的方式visit，碰到叶子统计价格（思路简单）。
//      也可以在读取的时候标记是不是leaf（retailers），然后统计到root的长度，时间复杂度一致。

class Chain{
public:
    vector<int> children;
};

double max_price = 0;
int max_count = 0;

void visit(int id, Chain chains[], double p, double r){
    if(chains[id].children.empty()){
        if(p > max_price){
            max_price = p;
            max_count = 1;
        } else if(p == max_price){
            max_count ++;
        }
    } else {
        for(int i = 0; i < chains[id].children.size(); i++){
            visit(chains[id].children[i], chains, p * (1 + r / 100), r);
        }
    }
}

int main(){
    int root, N;
    double price, r;
    cin >> N >> price >> r;

    Chain chain[N];
    for(int i = 0; i < N; i++){
        int supply;
        cin >> supply;
        if(supply == -1){
            root = i;
            continue;
        }
        chain[supply].children.push_back(i);
    }

    visit(root, chain, price, r);
    cout <<setiosflags(ios::fixed) <<  setprecision(2) << max_price << " "<< max_count << endl;
}