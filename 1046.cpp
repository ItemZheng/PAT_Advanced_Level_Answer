#include <iostream>

using namespace std;

// 无坑，保存1～其他城市的距离即可

int main(){
    int N;
    cin >> N;

    int D[N + 1];
    D[0] = 0;
    for(int i = 1; i <= N; i++){
        int d;
        cin >> d;
        D[i] = d + D[i - 1];
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > c2){
            c1 = c1 + c2;
            c2 = c1 - c2;
            c1 = c1 - c2;
        }
        int d = D[c2 - 1] - D[c1 - 1];
        if(D[N] - d < d){
            d = D[N] - d;
        }
        cout << d << endl;
    }
}
