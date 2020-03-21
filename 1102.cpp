#include <iostream>
#include <queue>

using namespace std;

// 无坑，递归遍历即可。

bool first = true;

class Node {
public:
    Node * left = nullptr, *right = nullptr;
    bool has_parent = false;
    int key;

public:
    void invert(){
        Node * temp = left;
        left = right;
        right = temp;
        if(left != nullptr){
            left->invert();
        }
        if(right != nullptr){
            right->invert();
        }
    }

    void visit(){
        if(left != nullptr){
            left->visit();
        }
        if(first){
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

int main(){
    int N;
    cin >> N;

    Node nodes[N];
    for(int i = 0; i < N; i++){
        string s1, s2;
        cin >> s1 >> s2;
        nodes[i].key = i;
        if(s1 != "-"){
            nodes[i].left = &nodes[stoi(s1)];
            nodes[stoi(s1)].has_parent = true;
        }
        if(s2 != "-"){
            nodes[i].right = &nodes[stoi(s2)];
            nodes[stoi(s2)].has_parent = true;
        }
    }

    Node * root = &nodes[0];
    for(int i = 0; i < N; i++){
        if(!nodes[i].has_parent){
            root = &nodes[i];
            break;
        }
    }

    root->invert();

    queue<Node *> level_nodes;
    level_nodes.push(root);
    while(!level_nodes.empty()){
        Node *r = level_nodes.front();
        level_nodes.pop();
        if(r != root){
            cout << " ";
        }
        cout << r->key;

        if(r->left != nullptr){
            level_nodes.push(r->left);
        }
        if(r->right != nullptr){
            level_nodes.push(r->right);
        }
    }
    cout << endl;

    root->visit();
    cout << endl;

}