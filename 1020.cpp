#include <iostream>
#include <queue>

// 无坑

using namespace std;

class Node{
public:
    Node *left, *right;
    int key;
public:
    Node(int key){
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

Node *rebuildTree(int l_idx_post, int r_idx_post, int post[], int l_idx_in, int r_idx_in, int in[]){
    Node *root = new Node(post[r_idx_post]);
    // find root of in[]
    int root_idx = l_idx_in;
    for(int i = l_idx_in; i <= r_idx_in; i++){
        if(post[r_idx_post] == in[i]){
            root_idx = i;
            break;
        }
    }

    int left_num = root_idx - l_idx_in, right_num = r_idx_in - root_idx;
    if(left_num > 0){
        root->left = rebuildTree(l_idx_post, l_idx_post + left_num - 1, post, l_idx_in, root_idx -1, in);
    }
    if(right_num > 0){
        root->right = rebuildTree(l_idx_post + left_num, r_idx_post - 1, post, root_idx + 1, r_idx_in, in);
    }
    return root;
}

int main(){
    int N;
    cin >> N;
    int post[N], in[N];
    for(int i = 0; i < N; i++){
        cin >> post[i];
    }
    for(int i = 0; i < N; i++){
        cin >> in[i];
    }

    Node *root = rebuildTree(0, N - 1, post, 0, N - 1, in);
    queue<Node *> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        Node *n = nodes.front();
        nodes.pop();

        if(n == root){
            cout << n->key;
        } else {
            cout << " " << n->key;
        }

        if(n->left != nullptr){
            nodes.push(n->left);
        }
        if(n->right != nullptr){
            nodes.push(n->right);
        }
    }
}