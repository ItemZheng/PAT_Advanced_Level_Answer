#include <iostream>
#include <cstring>

using namespace std;

// 无坑。判断条件是：
//  1、首先是一个环，首尾元素相同
//  2、除了首尾元素，其他元素不能出现两次
//  3、Vi-1 到 Vi 要能走通

int main(){
    int N, M;
    cin >> N >> M;
    int path[N][N];
    memset(path, 0, sizeof(int) * N * N);

    for(int i = 0; i < M; i++){
        int c1, c2;
        cin >> c1 >> c2;
        path[c1 - 1][c2 - 1] = 1;
        path[c2 - 1][c1 - 1] = 1;
    }

    int hash[N], K;
    cin >> K;
    for(int i = 0; i < K; i++){
        memset(hash, 0, sizeof(int) * N);

        int size, remain_nodes = N, last_node = -1, first_node = -1;
        bool OK = true;
        cin >> size;
        for(int j = 0; j < size; j++){
            int c;
            cin >> c;

            // 走得通
            if(last_node != -1){
                if(path[last_node -1][c - 1] == 0){
                    OK = false;
                }
            }

            // 除了首尾元素，其他不能重复出现
            if(hash[c - 1] == 0){
                remain_nodes--;
                hash[c - 1] = 1;
            } else if(hash[c - 1] == 1 && j < size - 1){
                OK = false;
            }
            if(first_node == -1){
                first_node = c;
            }
            last_node = c;
        }
        if(OK && remain_nodes == 0 && first_node == last_node){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}