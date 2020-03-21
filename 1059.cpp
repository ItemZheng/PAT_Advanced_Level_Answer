#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// 无坑，不卡时间。只要注意 1=1 的情况就好

bool prime(long num){
    if(num <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    map<long, int> exp_count;
    long num;
    cin >> num;
    if(num == 1){
        cout << "1=1";
        return 0;
    }
    long temp = num;
    for(long i = 2; i <= num; i++){
        if(prime(i)){
            while(num % i == 0){
                num = num / i;
                if(exp_count.count(i) == 0){
                    exp_count[i] = 1;
                } else {
                    exp_count[i]++;
                }
            }
            if(num == 1){
                break;
            }
        }
    }
    cout << temp << "=";
    for(map<long, int>::iterator it = exp_count.begin(); it != exp_count.end(); it++){
        if(it != exp_count.begin()){
            cout << "*";
        }
        cout << it->first;
        if(it->second > 1){
            cout << "^" << it->second;
        }
    }
}