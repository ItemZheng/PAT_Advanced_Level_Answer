#include <iostream>

using namespace std;

// 无坑，注意一下交换的逻辑就好

int main(){
    int N;
    cin >> N;
    int numbers[N], position[N];   // numbers and positions
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
        position[numbers[i]] = i;
    }

    int min_count = 0, next_unknown_position = 1;
    while(true){
        // get position of zero
        int pos_zero = position[0], pos_another;
        if(pos_zero != 0){
            pos_another = position[pos_zero];
        } else {
            for(int j = next_unknown_position; j < N; j++){
                if(numbers[j] != j){
                    break;
                } else {
                    next_unknown_position = j + 1;
                }
            }
            if(next_unknown_position == N){
                break;
            } else {
                pos_another = next_unknown_position;
            }
        }

        // swap
        min_count ++;
        position[numbers[pos_another]] = pos_zero;
        position[0] = pos_another;

        numbers[pos_zero] = numbers[pos_another];
        numbers[pos_another] = 0;
    }
    cout << min_count << endl;
}