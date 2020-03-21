#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 无坑。

int main(){
    // get m, n
    int N;
    cin >> N;
    int n = 1, m = N;
    for(int i = (int) sqrt(N); i > 1; i--){
        if(N % i == 0){
            n = i;
            m = N / i;
            break;
        }
    }

    // get numbers;
    int numbers[N];
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    sort(numbers, numbers + N);
    reverse(numbers, numbers + N);

    // matrix
    int matrix[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    // fill
    int col = 0, row = 0, dir = 0, idx = 0;
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
    while(idx < N){
        matrix[row][col] = numbers[idx++];
        int next_col = col + dir_y[dir], next_row = row + dir_x[dir];
        if(next_col >= 0 && next_col < n && next_row < m && next_row >= 0 && matrix[next_row][next_col] == 0){
            col = next_col;
            row = next_row;
        } else{
            dir = (dir + 1) % 4;
            next_col = col + dir_y[dir], next_row = row + dir_x[dir];
            if(next_col >= 0 && next_col < n && next_row < m && next_row >= 0 && matrix[next_row][next_col] == 0){
                col = next_col;
                row = next_row;
            } else {
                break;
            }
        }
    }

    // matrix
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j > 0){
                cout << " ";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}