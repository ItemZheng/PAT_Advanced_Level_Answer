#include <iostream>
#include <unordered_map>

using namespace std;

// 无坑。但是要进行路径折叠。

int rootOf(unordered_map<int, int> &bird_map, int id){
    int root = id;
    while(bird_map[root] >= 0){
        root = bird_map[root];
    }
    while(bird_map[id] >= 0){
        int next = bird_map[id];
        bird_map[id] = root;
        id = next;
    }
    return root;
}


int main(){
    unordered_map<int, int> bird_map;

    int N;
    cin >> N;

    int bird_count = 0, tree_count = 0;
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        int last_bird = -1;
        for(int j = 0; j < K; j++){
            int bird;
            cin >> bird;
            if(bird_map.count(bird) == 0){
                bird_map[bird] = -1;
                bird_count++;
                tree_count++;
            }
            if(last_bird != -1){
                int r1 = rootOf(bird_map, last_bird), r2 = rootOf(bird_map, bird);
                if(r1 != r2){
                    bird_map[r1] = r2;
                    tree_count--;
                }
            }
            last_bird = bird;
        }
    }

    cout << tree_count << " " << bird_count << endl;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int b1, b2;
        cin >> b1 >> b2;
        if(rootOf(bird_map, b1) != rootOf(bird_map, b2)){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}