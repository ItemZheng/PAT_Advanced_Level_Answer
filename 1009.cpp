#include <iostream>
#include <iomanip>

// 注意点：注意C++固定小数位数的代码

using namespace std;

int main(){
    float a[2001], c[2001];
    for(int i = 0; i < 2001; i++){
        a[i] = c[i] = 0;
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int idx;
        float fab;
        cin >> idx >> fab;
        a[idx] = fab;
    }

    cin >> K;
    for(int i = 0; i < K; i++){
        int idx;
        float fab;
        cin >> idx >> fab;
        for(int j = 0; j < 2001; j++){
            if(a[j] != 0){
                c[j + idx] += fab * a[j];
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 2001; i++){
        if(c[i]!= 0){
            count++;
        }
    }
    cout << count;

    for(int i = 2000; i >= 0; i--){
        if(c[i]!= 0){
            cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << c[i];
        }
    }
    return 0;
}