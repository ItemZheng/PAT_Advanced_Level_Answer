#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// 无坑，用递归，计算好左子树和右子树的大小，以及递归出口即可

class Node {
public:
    int key;
    Node *left, *right;
public:
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

Node * buildTree(int left, int right, int num[]){
    // get root
    if(left > right){
        return nullptr;
    }
    if(left == right){
        return new Node(num[left]);
    }

    // get left size and right size
    int size = right - left + 1;
    int level = int(log2(size + 1));
    int left_size = int((pow(2, level) - 2) / 2), right_size = left_size;
    int half_size = int(pow(2, level - 1));
    if(size - left_size - right_size - 1 < half_size){
        left_size += size - left_size - right_size - 1;
    } else {
        left_size += half_size;
    }
    Node *root = new Node(num[left + left_size]);
    // 递归
    if(left_size > 0){
        root->left = buildTree(left, left_size + left - 1, num);
    }
    if(size - left_size - 1 > 0){
        root->right = buildTree(left_size + left + 1, right, num);
    }
    return root;
}

void visit(Node *root){
    queue<Node *> level;
    level.push(root);
    bool first = true;
    while(!level.empty()){
        Node *node = level.front();
        level.pop();
        if(first){
            first = false;
        } else {
            cout << " ";
        }
        cout << node->key;
        if(node->left != nullptr){
            level.push(node->left);
            if(node->right != nullptr){
                level.push(node->right);
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    int num[N];
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    sort(num, num + N);
    Node *root = buildTree(0, N - 1, num);
    visit(root);
}