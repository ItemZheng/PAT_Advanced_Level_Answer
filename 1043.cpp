#include <iostream>

using namespace std;

// 无坑，递归即可，为了思路简单，直接分为 buildTree 和 buildMirrorTree

bool first = true;
bool error = false;

class Node{
public:
    int key;
    Node *left, *right;
public:
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }

    void post_order(){
        if(left != nullptr){
            left->post_order();
        }
        if(right != nullptr){
            right->post_order();
        }
        if(!first){
            cout << " ";
        } else {
            first = false;
        }
        cout << key;
    }
};

Node * buildTree(int begin, int end, int num[]){
    if(error){
        return nullptr;
    }
    Node * node = new Node(num[begin]);
    // find left
    int left_end = -1;
    for(int i = begin + 1; i <= end; i++){
        if(num[i] < node->key){
            left_end = i;
        } else {
            break;
        }
    }
    if(left_end != -1){
        node->left = buildTree(begin + 1, left_end, num);
        if(error){
            return nullptr;
        }
    }

    // find right
    int right_begin = left_end + 1;
    if(left_end == -1){
        right_begin = begin + 1;
    }
    if(right_begin <= end){
        // check
        for(int i = right_begin; i <= end; i++){
            if(num[i] < node->key){
                error = true;
                break;
            }
        }
        if(error){
            return nullptr;
        }
        node->right = buildTree(right_begin, end, num);
        if(error){
            return nullptr;
        }
    }
    return node;
}

Node *buildMirrorTree(int begin, int end, int num[]){
    if(error){
        return nullptr;
    }
    Node * node = new Node(num[begin]);
    // find left
    int left_end = -1;
    for(int i = begin + 1; i <= end; i++){
        if(num[i] >= node->key){
            left_end = i;
        } else {
            break;
        }
    }
    if(left_end != -1){
        node->left = buildMirrorTree(begin + 1, left_end, num);
        if(error){
            return nullptr;
        }
    }

    // find right
    int right_begin = left_end + 1;
    if(left_end == -1){
        right_begin = begin + 1;
    }
    if(right_begin <= end){
        // check
        for(int i = right_begin; i <= end; i++){
            if(num[i] >= node->key){
                error = true;
                break;
            }
        }
        if(error){
            return nullptr;
        }
        node->right = buildMirrorTree(right_begin, end, num);
        if(error){
            return nullptr;
        }
    }
    return node;
}

int main(){
    int N;
    cin >> N;

    int num[N];
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    Node * root = buildTree(0, N - 1, num);
    if(error){
        error = false;
        root = buildMirrorTree(0, N - 1, num);
    }
    if(error){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
        root->post_order();
    }
}