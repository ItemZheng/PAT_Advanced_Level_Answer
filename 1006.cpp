#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    string unlock_id, lock_id;
    string early_time, late_time;

    cin >> unlock_id >> early_time >> late_time;
    lock_id = unlock_id;

    for(int i = 0; i < N - 1; i++){
        string id, e_time, l_time;
        cin >> id >> e_time >> l_time;
        if(strcmp(e_time.c_str(), early_time.c_str()) < 0){
            unlock_id = id;
            early_time = e_time;
        }
        if(strcmp(late_time.c_str(), l_time.c_str()) < 0){
            lock_id = id;
            late_time = l_time;
        }
    }

    cout << unlock_id << " " << lock_id;
    return 0;

}