#include <iostream>

using namespace std;

// 无坑。数组要开得大，虽然每个硬币不超过500，但是 M - i 会超过500，所以数组要开到1001

int main(){
    int N, M;
    cin >> N >> M;

    int coin[1001];
    for(int i = 0; i < 1001; i++){
        coin[i] = 0;
    }
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        coin[c]++;
    }
    for(int i = 0; i <= M / 2; i++){
        if(coin[i] > 0){
            coin[i]--;
            if(coin[M - i] > 0){
                cout << i << " " << M - i << endl;
                return 0;
            } else {
                coin[i]++;
            }
        }
    }
    cout << "No Solution" << endl;
}