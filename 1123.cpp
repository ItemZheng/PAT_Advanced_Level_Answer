#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 无坑。最重要的是记住AVL树的实现。尤其是旋转的过程
//      判断complete先获取LevelOrder然后再判断 2*i+1是不是左子树，2*i+2是不是右子树

class Node {
public:
    Node * left = nullptr, *right = nullptr;
    int key = 0, height = 1;
public:
    Node(int k){
        key = k;
        height = 1;
    }
};

int heightOf(Node *r){
    if(r == nullptr){
        return 0;
    }
    return r->height;
}

int maxNum(int a, int b){
    return a > b ? a : b;
}

Node * rotateLL(Node *r){
    Node * root = r->left;
    r->left = root->right;
    root->right = r;

    r->height = maxNum(heightOf(r->left), heightOf(r->right)) + 1;
    root->height = maxNum(heightOf(root->left), heightOf(root->right)) + 1;
    return root;
}

Node * rotateRR(Node *r){
    Node *root = r->right;
    r->right = root->left;
    root->left = r;

    r->height = maxNum(heightOf(r->left), heightOf(r->right)) + 1;
    root->height = maxNum(heightOf(root->left), heightOf(root->right)) + 1;
    return root;
}

Node * rotateRL(Node *r){
    r->right = rotateLL(r->right);
    r = rotateRR(r);
    return r;
}

Node * rotateLR(Node *r){
    r->left = rotateRR(r->left);
    r = rotateLL(r);
    return r;
}

Node * insert(Node * r, int key){
    if(r == nullptr){
        return new Node(key);
    }
    if(key < r->key){
        r->left = insert(r->left, key);
        if(heightOf(r->left) - heightOf(r->right) >= 2){
            if(heightOf(r->left->left) > heightOf(r->left->right)){
                r = rotateLL(r);
            } else {
                r = rotateLR(r);
            }
        }
    } else {
        r->right = insert(r->right, key);
        if(heightOf(r->right) - heightOf(r->left) >= 2){
            if(heightOf(r->right->right) > heightOf(r->right->left)){
                r = rotateRR(r);
            } else {
                r = rotateRL(r);
            }
        }
    }
    r->height = maxNum(heightOf(r->left), heightOf(r->right)) + 1;
    return r;
}

int main(){
    int N;
    cin >> N;
    Node * root = nullptr;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }

    vector<Node *> order_nodes;
    queue<Node *> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        Node * n = nodes.front();
        nodes.pop();
        order_nodes.push_back(n);
        if(n->left != nullptr){
            nodes.push(n->left);
        }
        if(n->right != nullptr){
            nodes.push(n->right);
        }
    }
    bool isComplete = true;
    for(int i = 0; i < order_nodes.size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << order_nodes[i]->key;

        int child = 2 * i + 1;
        if(child < order_nodes.size()){
            if(order_nodes[i]->left != order_nodes[child]){
                isComplete = false;
            }
            child++;
            if(child < order_nodes.size()){
                if(order_nodes[i]->right != order_nodes[child]){
                    isComplete = false;
                }
            }
        }
    }
    cout << endl;
    if(isComplete){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}