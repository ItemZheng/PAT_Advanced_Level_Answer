#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// 无坑。需要了解平方探测法。

bool prime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int insert(int TSize, int hash[], int num){
    for(int i = 0; i < TSize; i++){
        if(hash[(num + i * i) % TSize] == -1){
            hash[(num + i * i) % TSize] = num;
            return (num + i * i) % TSize;
        }
    }
    return -1;
}

int main(){
    int TSize, N;
    cin >> TSize >> N;

    while(!prime(TSize)){
        TSize++;
    }

    int hash[TSize];
    memset(hash, -1, sizeof(int) * TSize);

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;

        int pos = insert(TSize, hash, num);
        if(i != 0){
            cout << " ";
        }
        if(pos == -1){
            cout << "-";
        } else {
            cout << pos;
        }
    }
}