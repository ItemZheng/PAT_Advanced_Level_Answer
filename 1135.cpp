#include <iostream>

using namespace std;

// 无坑，递归判断红黑树即可。

class Node {
public:
    Node *left = nullptr, *right = nullptr;
    int key = 1;
    bool black = true;

    int blackHeight = 1;
public:
    Node(int k){
        if(k < 0){
            key = -k;
            black = false;
        } else {
            key = k;
            black = true;
        }
    }
};

Node * insert(Node * r, int key){
    if(r == nullptr){
        return new Node(key);
    }
    if(abs(key) <= r->key){
        r->left = insert(r->left, key);
    } else {
        r->right = insert(r->right, key);
    }
    return r;
}

int blackHeightOf(Node *r){
    if(r == nullptr){
        return 1;
    }
    return r->blackHeight;
}

bool isBlack(Node *r){
    if(r == nullptr){
        return true;
    }
    return r->black;
}

bool judgeNode(Node *r){
    if(r == nullptr){
        return true;
    }
    // 第四点
    if(!r->black){
        if(!isBlack(r->left)){
            return false;
        }
        if(!isBlack(r->right)){
            return false;
        }
    }

    if(!judgeNode(r->left)){
        return false;
    }
    if(!judgeNode(r->right)){
        return false;
    }

    if(blackHeightOf(r->left) != blackHeightOf(r->right)){
        return false;
    }

    if(r->black){
        r->blackHeight = blackHeightOf(r->left) + 1;
    } else {
        r->blackHeight = blackHeightOf(r->left);
    }
    return true;
}

bool isBlackRedTree(Node *root){
    // 第二点
    if(!root->black){
        return false;
    }
    return judgeNode(root);
}

int main(){
    int K;
    cin >> K;
    for(int k = 0; k < K; k++){
        int N;
        cin >> N;

        Node *root = nullptr;
        for(int i = 0; i < N; i++){
            int key;
            cin >> key;
            root = insert(root, key);
        }

        if(isBlackRedTree(root)){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}