#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 无坑。

int idx = 0;

class Node {
public:
    Node *left = nullptr, *right = nullptr;
    int key;
public:
    void filling(vector<int> &keys){
        if(left != nullptr){
            left->filling(keys);
        }
        key = keys[idx++];
        if(right != nullptr){
            right->filling(keys);
        }
    }

};

int main(){
    int N;
    cin >> N;

    Node nodes[N];
    for(int i = 0; i < N; i++){
        int l, r;
        cin >> l >> r;
        if(l != -1){
            nodes[i].left = &nodes[l];
        }
        if(r != -1){
            nodes[i].right = &nodes[r];
        }
    }

    vector<int> keys;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        keys.push_back(num);
    }

    sort(keys.begin(), keys.end());
    nodes[0].filling(keys);

    queue<Node *> level_nodes;
    cout << nodes[0].key;
    level_nodes.push(&nodes[0]);
    while(!level_nodes.empty()){
        Node * root = level_nodes.front();
        level_nodes.pop();
        if(root->left != nullptr){
            cout << " " << root->left->key;
            level_nodes.push(root->left);
        }
        if(root->right != nullptr){
            cout << " " << root->right->key;
            level_nodes.push(root->right);
        }
    }
}