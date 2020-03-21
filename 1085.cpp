#include <iostream>
#include <algorithm>

using namespace std;

// 无坑，先排序，然后遍历即可。

int main(){
    int N, p;
    cin >> N >> p;

    long long numbers[N];
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    sort(numbers, numbers + N);

    int max_length = 0;
    for(int begin = 0; begin < N; begin++){
        for(int length = max_length + 1; begin + length - 1 < N; length++){
            if(numbers[begin] * p >= (numbers[begin + length - 1])){
                max_length = length;
            } else {
                break;
            }
        }
    }
    cout << max_length << endl;
}