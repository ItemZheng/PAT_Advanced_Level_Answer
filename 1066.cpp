#include <iostream>

// 无坑。但是要知道AVL的insert流程，主要就是insert操作

using namespace std;

int max(int x, int y){
    return x > y ? x : y;
}

class Node {
public:
    int key, height;
    Node * left, *right;
public:
    Node(int k){
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

int height(Node *node){
    if(node == nullptr){
        return 0;
    }
    else
        return node->height;
}

Node * rotateLL(Node * node){
    Node * r = node->left;
    node->left = r->right;
    r->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    r->height = max(height(r->left), height(r->right)) + 1;
    return r;
}

Node * rotateRR(Node * node){
    Node * r = node->right;
    node->right = r->left;
    r->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    r->height = max(height(r->left), height(r->right)) + 1;
    return r;
}

Node * rotateRL(Node * node){
    node->right = rotateLL(node->right);
    return rotateRR(node);
}

Node * rotateLR(Node * node){
    node->left = rotateRR(node->left);
    return rotateLL(node);
}

Node * insert(Node * root, int x){
    if(root == nullptr){
        return new Node(x);
    }
    // insert
    if(x > root->key){
        root->right = insert(root->right, x);
    } else{
        root->left = insert(root->left, x);
    }
    // adjust
    if(height(root->left) >= height(root->right) + 2){
        if(height(root->left->left) > height(root->left->right)){
            root = rotateLL(root);
        } else {
            root = rotateLR(root);
        }
    } else if(height(root->left) + 2 <= height(root->right)){
        if(height(root->right->left) > height(root->right->right)){
            root = rotateRL(root);
        } else {
            root = rotateRR(root);
        }
    }
    // update height
    root->height = max(height(root->right), height(root->left)) + 1;
    return root;
}

int main(){
    int N;
    cin >> N;

    Node * r = nullptr;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        r = insert(r, num);
    }
    cout << r->key << endl;
}