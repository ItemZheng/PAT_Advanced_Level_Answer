#include <iostream>
#include <unordered_map>

using namespace std;

// 无坑，直接用unordered_map计数，最后遍历map（本质是hash表）

int main() {
    unordered_map<int, int> color_count;
    int M, N;
    cin >> M >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int c;
            cin >> c;
            if (color_count.count(c) > 0) {
                color_count[c]++;
            } else {
                color_count[c] = 1;
            }
        }
    }
    int max_c = 0, max_color = -1;
    for (unordered_map<int, int>::iterator it = color_count.begin(); it != color_count.end(); it++) {
        if (it->second > max_c) {
            max_c = it->second;
            max_color = it->first;
        }
    }

    cout << max_color << endl;
}