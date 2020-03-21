#include <iostream>
#include <unordered_map>

// 无坑。不需要存储inorder的所有列表，直接存位置就可以

using namespace std;

int *pre_order;
unordered_map<int, int> key_pos;

void find_left_most(int pre_left, int pre_right, int in_left, int in_right) {
    int key = pre_order[pre_left];
    int pos = key_pos[key];
    if (in_left == in_right) {
        cout << key << endl;
        return;
    }
    if (pos == in_left) {
        find_left_most(pre_left + pos - in_left + 1, pre_right, pos + 1, in_right);
    } else {
        find_left_most(pre_left + 1, pre_left + pos - in_left, in_left, pos - 1);
    }
}

int main() {
    int N;
    cin >> N;

    pre_order = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> pre_order[i];
    }

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        key_pos[k] = i;
    }

    find_left_most(0, N - 1, 0, N - 1);
}
