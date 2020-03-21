#include <iostream>

using namespace std;

// 无坑
//  1、较差的办法：根据符号分类，比较复杂
//  2、较好的办法：只根据是否溢出分类，简单(本题使用此办法)

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long x, y, z, res;
        cin >> x >> y >> z;
        bool answer;
        res = x + y;
        if( x > 0 && y > 0 && res <= 0){    // 正溢出
            answer = true;
        } else if(y < 0 && x < 0 && res >= 0){  // 负溢出
            answer = false;
        } else {
            answer = res > z;
        }
        cout << "Case #" << i + 1 << ": ";
        if(answer){
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
}