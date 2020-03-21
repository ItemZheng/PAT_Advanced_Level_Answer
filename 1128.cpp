#include <iostream>
#include <cstring>

using namespace std;

// 无坑。分别记录同一row，diagonal，anti_diagonal是否出现

int main(){
    int M;
    cin >> M;

    for(int i = 0; i < M; i++){
        int N;
        cin >> N;

        int pos[N];
        for(int j = 0; j < N; j++){
            cin >> pos[j];
            pos[j]--;
        }

        int row[N], diagonal[2 * N], anti_diagonal[2 * N];
        memset(row, 0, sizeof(int) * N);
        memset(diagonal, 0, sizeof(int) * 2 * N);
        memset(anti_diagonal, 0, sizeof(int) * 2 * N);

        // judge
        bool ok = true;
        for(int j = 0; j < N; j++){
            int r = pos[j];
            // same row
            if(row[r] == 1){
                ok = false;
                break;
            }
            row[r] = 1;

            // same diagonal
            if(diagonal[r + j] == 1){
                ok = false;
                break;
            }
            diagonal[r + j] = 1;

            // same anti diagonal
            if(anti_diagonal[r - j + N] == 1){
                ok = false;
                break;
            }
            anti_diagonal[r - j + N] = 1;
        }

        if(ok){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}