#include <iostream>

using namespace std;

// 无坑。
//  1、rebuild Tree
//  2、preorder第一个一定是root，postorder最后一个一定是root
//  3、找到root之后，划分左子树和右子树是关键
//      i. 如果有左右子树，那么preoder中第二个一定是左子树，postorder中左子树的root一定不在倒数第二个，这种情况没有歧义
//      ii. 如果preoder中第二个值 在postorder中的倒数第二个，那么这颗子树有可能左子树或右子树，无法判断，因此歧义出现在这里
//

bool first = true;

class Node{
public:
    Node *left = nullptr, *right = nullptr;
    int key;
public:
    Node(int k){
        key = k;
    }

    void visit(){
        if(left != nullptr){
            left->visit();
        }
        if (first){
            first = false;
        } else {
            cout << " ";
        }
        cout << key;
        if(right != nullptr){
            right->visit();
        }
    }
};

int *pre_order, *post_order;

bool uniqueTree = true;

Node * rebuildTree(int pre_left, int pre_right, int pos_left, int pos_right){
    Node *r = new Node(pre_order[pre_left]);
    if(pre_right == pre_left){
        return r;
    }

    // find left root
    int rootKey = pre_order[pre_left + 1];
    int rootIdx = pos_left;
    while(rootKey != post_order[rootIdx]){
        rootIdx++;
    }
    if(rootIdx == pos_right - 1){
        uniqueTree = false;
        r->left = rebuildTree(pre_left + 1, pre_right, pos_left, pos_right - 1);
    } else {
        int left_size = rootIdx - pos_left + 1;
        r->left = rebuildTree(pre_left + 1, pre_left + left_size, pos_left, rootIdx);
        r->right = rebuildTree(pre_left + left_size + 1, pre_right, rootIdx + 1, pos_right - 1);
    }
    return r;
}

int main(){
    // input
    int N;
    cin >> N;
    pre_order = new int[N];
    post_order = new int[N];
    for(int i = 0; i < N; i++){
        cin >> pre_order[i];
    }
    for(int i = 0; i < N; i++){
        cin >> post_order[i];
    }

    Node *root = rebuildTree(0, N - 1, 0, N - 1);
    if(uniqueTree){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    root->visit();
    cout << endl;
}