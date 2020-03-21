#include <iostream>
#include <vector>

using namespace std;

// 无坑。

class Node{
public:
    Node *left = nullptr, *right = nullptr;
    int key = 0;
public:
    Node(int k){
        key = k;
    }
};

int *in_order, *post_order;

Node *rebuildTree(int in_left, int in_right, int post_left, int post_right){
    int rootKey = post_order[post_right];
    Node *root = new Node(rootKey);
    if(in_left == in_right){
        return root;
    }

    int rootIdx = in_left;
    while(in_order[rootIdx] != rootKey){
        rootIdx++;
    }

    int left_size = rootIdx - in_left;
    if(rootIdx > in_left){
        root->left = rebuildTree(in_left, rootIdx - 1, post_left, post_left + left_size - 1);
    }
    if(in_right > rootIdx){
        root->right = rebuildTree(rootIdx + 1, in_right, post_left + left_size, post_right - 1);
    }
    return root;
}

int main(){
    int N;
    cin >> N;

    // rebuild
    in_order = new int[N];
    post_order = new int[N];
    for(int i = 0; i < N; i++){
        cin >> in_order[i];
    }
    for(int i = 0; i < N; i++){
        cin >> post_order[i];
    }

    Node * root = rebuildTree(0, N - 1, 0, N - 1);

    bool needReverse = true, first = true;
    vector<Node *> level;
    level.push_back(root);

    while(!level.empty()){
        vector<Node *> next_level;
        for(int i = 0; i < level.size(); i++){
            if(level[i]->left){
                next_level.push_back(level[i]->left);
            }
            if(level[i]->right){
                next_level.push_back(level[i]->right);
            }
        }

        if(needReverse){
            for(int i = level.size() - 1; i >= 0; i--){
                if(first){
                    first = false;
                } else {
                    cout << " ";
                }
                cout << level[i]->key;
            }
        } else {
            for(int i = 0; i < level.size(); i++){
                if(first){
                    first = false;
                } else {
                    cout << " ";
                }
                cout << level[i]->key;
            }
        }
        level = next_level;
        needReverse = !needReverse;
    }
}