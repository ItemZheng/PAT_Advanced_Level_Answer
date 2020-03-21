#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

// 好题。
//  1、一开始使用 vector存储，unordered_map计数，但是最后一个时间复杂度过不去
//  2、改进一：存储时用unordered_map去除重复的元素，所用时间降低，但是还是过不了时间
//  3、改进二：使用scanf和printf，还是超时
//  4、改进三：使用set（存储时自动去除），然后使用algorithm中自带的set_union和set_insertion，还是过不了时间
//  5、改进四：最后将自带的set_union和set_insertion换成自己遍历，只遍历s2，如果s1中找到了那就N_c++，否则就N_t++
//  主要思路就是先把N_t置为s1的size，然后只遍历s2，如果s1中找到了那就N_c++，否则就N_t++(这样的思路unordered_map也可以不超时)

int main(){
    int N;
    scanf("%d", &N);

    set<int> sets[N];
    for(int i = 0; i < N; i++){
        int M;
        scanf("%d", &M);
        for(int j = 0; j < M; j++){
            int num;
            scanf("%d", &num);
            sets[i].insert(num);
        }
    }

    int K;
    scanf("%d", &K);
    for(int i = 0 ; i < K; i++){
        int s1, s2;
        scanf("%d%d", &s1, &s2);
        int N_t = sets[s1 - 1].size(), N_c = 0;
        for(set<int>::iterator it = sets[s2 - 1].begin(); it != sets[s2 - 1].end(); it++){
            if(sets[s1 - 1].find(*it) == sets[s1 - 1].end()){
                // Can not find
                N_t++;
            } else {
                N_c++;
            }
        }
        printf("%.1f%%\n", N_c * 100.0 / N_t);
    }
}