#include <iostream>
#include <vector>

using namespace std;

// 无坑，需要思路清晰。
//  1、注意stack的pop顺序就是tree的inorder遍历顺序
//  2、注意stack的push顺序就是tree的pre_order顺序，因为需要先push中间，然后push左边（然后pop左边，pop中间）push右边（pop右边）
//  3、有了inorder和preorder的顺序就可以重新构造树

bool first = true;
vector<int> inorder_seq, preorder_seq, stack_seq;

class Node {
public:
    Node * left, * right;
    int key;
public:
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }

    void visit(){
        if(left != nullptr){
            left->visit();
        }
        if(right != nullptr){
            right->visit();
        }
        if(first){
            first = false;
        } else {
            cout << " ";
        }
        cout << key;
    }
};

Node * rebuild(int pre_left, int pre_right, int in_left, int in_right){
    Node * r = new Node(preorder_seq[pre_left]);
    int root = preorder_seq[pre_left];

    int idx = in_left;
    for(idx = in_left; idx <= in_right; idx++){
        if(inorder_seq[idx] == root){
            break;
        }
    }

    int left_size = idx - in_left, right_size = in_right - idx;
    if(left_size > 0){
        r->left = rebuild(pre_left + 1, pre_left + left_size, in_left, idx - 1);
    }
    if(right_size > 0){
        r->right = rebuild(pre_left + left_size + 1, pre_right, idx + 1, in_right);
    }
    return r;
}


int main(){
    int N;
    cin >> N;
    for(int i = 0; i < 2 * N; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "Push"){
            int number;
            cin >> number;
            stack_seq.push_back(number);
            preorder_seq.push_back(number);
        } else {
            inorder_seq.push_back(stack_seq.back());
            stack_seq.pop_back();
        }
    }

    Node * r = rebuild(0, N - 1, 0, N - 1);
    r->visit();
}