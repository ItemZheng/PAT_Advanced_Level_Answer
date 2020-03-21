#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 无坑，递归遍历即可，注意amount需要是int的，不然会段错误

double total_price = 0.0;

class Chain{
public:
    vector<int> retailers;
    bool isRetailer = false;
    int amount = 0;
public:
    Chain(){}
};

void visit(Chain chains[], int id, double price, double r){
    if(chains[id].isRetailer){
        total_price += price * chains[id].amount;
    } else {
        for(int i = 0; i < chains[id].retailers.size(); i++){
            visit(chains, chains[id].retailers[i], price * (1 + r / 100), r);
        }
    }
}

int main(){
    int N;
    double oriPrice, r;
    cin >> N >> oriPrice >> r;

    Chain chains[N];
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;

        if(K == 0){
            cin >> chains[i].amount;
            chains[i].isRetailer = true;
        } else {
            for(int j = 0; j < K; j++){
                int id;
                cin >> id;
                chains[i].retailers.push_back(id);
            }
        }
    }

    visit(chains, 0, oriPrice, r);
    cout << setiosflags(ios::fixed) << setprecision(1) << total_price << endl;
}