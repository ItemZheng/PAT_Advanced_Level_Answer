#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int time = 0;
    int current_f = 0;

    for(int i = 0; i < N; i++){
        int next_f;
        cin >> next_f;

        if(next_f > current_f){
            time = time + (next_f - current_f) * 6 + 5;
        } else {
            time = time + (current_f - next_f) * 4 + 5;
        }

        current_f = next_f;
    }

    cout << time;
}