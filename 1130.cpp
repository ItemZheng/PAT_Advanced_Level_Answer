#include <iostream>

using namespace std;

// 无坑，第一层不用加括号，有孩子就加括号

class Node {
public:
    Node *left = nullptr, *right = nullptr;
    string s;
    bool has_parent = false;
public:
    void visit(Node * root){
        if((left || right) && this != root)
            cout << "(";
        if(left != nullptr){
            left->visit(root);
        }
        cout << s;
        if(right != nullptr){
            right->visit(root);
        }
        if((left || right) && this != root)
            cout << ")";
    }
};

int main(){
    int N;
    cin >> N;

    Node nodes[N];
    for(int i = 0; i < N; i++){
        int l, r;
        cin >> nodes[i].s >> l >> r;
        if(l != -1){
            nodes[i].left = &nodes[l-1];
            nodes[l-1].has_parent = true;
        }
        if(r != -1){
            nodes[i].right = &nodes[r-1];
            nodes[r-1].has_parent = true;
        }
    }

    Node *root = &nodes[0];
    for(int i = 1; i < N; i++){
        if(!nodes[i].has_parent){
            root = &nodes[i];
        }
    }

    root->visit(root);
    cout << endl;
}