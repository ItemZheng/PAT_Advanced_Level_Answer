#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// 有坑。注意点：
//          1、注意精度，要用double，否则会有点过不去。
//          2、注意可能会有供货不足的情况(多用for循环就会控制边界)

class Mooncake{
public:
    double weight;
    double price;
public:
    Mooncake(){}
};

bool cmp(Mooncake &m1, Mooncake &m2){
    return  m1.price / m1.weight > m2.price / m2.weight;
}

int main(){
    int N;
    double M;
    cin >> N >> M;

    Mooncake cakes[N];
    for(int i = 0; i < N; i++){
        cin >> cakes[i].weight;
    }
    for(int i = 0; i < N; i++){
        cin >> cakes[i].price;
    }

    sort(cakes, cakes + N, cmp);

    double total_price = 0.0;
    for(int i = 0; i < N; i++){
        Mooncake &cake = cakes[i];
        if(cake.weight < M){
            M = M - cake.weight;
            total_price += cake.price;
        } else {
            total_price += cake.price * M / cake.weight;
            break;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << total_price << endl;
}