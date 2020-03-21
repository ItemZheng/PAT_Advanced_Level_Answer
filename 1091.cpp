#include <iostream>
#include <queue>

// 注意点：
//      1、用DFS会溢出，改用BFS。
//      2、如果内存超限，在合适的地方使用delete

using namespace std;
int M, N, L;

int offset_l[6] = {0, 0, 0, 0, 1, -1};
int offset_m[6] = {1, -1, 0, 0, 0, 0};
int offset_n[6] = {0, 0, 1, -1, 0, 0};

class Pos{
public:
    int l, m, n;
public:
    Pos(int l, int m, int n){
        this->l = l;
        this->m = m;
        this->n = n;
    }

    Pos * neigh_pos(int i ){
        return new Pos(l + offset_l[i], m + offset_m[i], n + offset_n[i]);
    }

    bool valid(){
        return l >= 0 && l < L && m >= 0 && m < M && n >= 0 && n < N;
    }
};

int BFS(int ***pixels, int l, int m, int n, int count){
    Pos *p = new Pos(l, m, n);
    queue<Pos *> positions;
    positions.push(p);
    pixels[l][m][n] = 0;
    count++;

    while(!positions.empty()){
        Pos *pos = positions.front();
        positions.pop();
        for(int i = 0; i < 6; i++){
            Pos *next = pos->neigh_pos(i);
            if(next->valid() && pixels[next->l][next->m][next->n] == 1){
                pixels[next->l][next->m][next->n] = 0;
                count++;
                positions.push(next);
            } else {
                delete next;
            }
        }
        delete pos;
    }
    return count;
}

int main(){
    int T;
    cin >> M >> N >> L >> T;

    int total_count = 0;
    int ***pixels = new int**[L];
    for(int i = 0; i < L; i++){
        pixels[i] = new int *[M];
        for(int m = 0; m < M; m++){
            pixels[i][m] = new int[N];
            for(int n = 0; n < N; n++){
                cin >> pixels[i][m][n];
            }
        }
    }
    for(int i = 0; i < L; i++){
        for(int m = 0; m < M; m++){
            for(int n = 0; n < N; n++){
                if(pixels[i][m][n] > 0){
                    int count = BFS(pixels, i, m, n, 0);
                    if(count >= T){
                        total_count = total_count + count;
                    }
                }
            }
        }
    }
    cout << total_count << endl;
}