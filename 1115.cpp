#include <iostream>
#include <vector>

// 无坑。构建一棵BST, 然后保存所有层的Node *

using namespace std;

class Node {
public:
    int key = 0;
    Node *left = nullptr, *right = nullptr;
public:
    Node(int k){
        key = k;
    }
};

Node *insert(Node *node, int key){
    if(node == nullptr){
        return new Node(key);
    }
    if(key <= node->key){
        node->left = insert(node->left, key);
        return node;
    }
    node->right = insert(node->right, key);
    return node;
}

int main(){
    int N;
    cin >> N;
    Node *root = nullptr;
    for(int i = 0; i < N; i++){
        int key;
        cin >> key;
        if(key >= -1000 && key <= 1000)
            root = insert(root, key);
    }

    vector<vector<Node *> > level_nodes;
    vector<Node *> level;
    level.push_back(root);
    while(!level.empty()){
        level_nodes.push_back(level);
        vector<Node *> next_level;
        for(int i = 0; i < level.size(); i++){
            if(level[i]->left != nullptr){
                next_level.push_back(level[i]->left);
            }
            if(level[i]->right != nullptr){
                next_level.push_back(level[i]->right);
            }
        }
        level = next_level;
    }

    int l1 = level_nodes[level_nodes.size() - 2].size(), l2 = level_nodes[level_nodes.size() - 1].size();
    cout << l2 << " + " << l1 << " = " << l1 + l2 << endl;
}