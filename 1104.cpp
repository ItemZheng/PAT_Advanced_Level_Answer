#include <iostream>

using namespace std;

// 无坑。注意(i + 1) * (N - i)会超过整数范围，所以需要用long
//  和左边组合有 i + 1 种，和右边组合有 N- i所以一共有 (i + 1) * (N - i)

int main(){
    double total = 0.0;

    long N;
    cin >> N;

    for(long i = 0; i < N; i++){
        double number;
        cin >> number;
        total = total + (double)(i + 1) * (double)(N - i) * number;
    }
    printf("%.2lf\n", total);
}