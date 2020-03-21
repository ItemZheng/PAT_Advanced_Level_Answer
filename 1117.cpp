#include <iostream>
#include <algorithm>

using namespace std;

// 无坑。

int main(){
    int N;
    cin >> N;
    int distance[N];
    for(int i = 0; i < N; i++){
        cin >> distance[i];
    }

    sort(distance, distance + N);
    reverse(distance, distance + N);

    int E = 0;
    for(int i = 0; i < N; i++){
        if(distance[i] > i + 1){
            E = i + 1;
        } else {
            break;
        }
    }
    cout << E << endl;
}