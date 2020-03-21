#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int N;
    cin >> N;

    int existed[N + 2];
    memset(existed, 0, sizeof(int) * (N + 2));
    int missing = 1;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(num < 0 || num >= N + 2){
            continue;
        }
        existed[num] = 1;
        while(existed[missing] == 1){
            missing++;
        }
    }
    cout << missing << endl;
}