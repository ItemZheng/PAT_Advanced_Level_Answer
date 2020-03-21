#include <iostream>
#include <vector>
#include <unordered_map>

// 无坑，如果removed_list是空的就不输出

using namespace std;

class Node{
public:
    int addr, next;
    int key;
public:
    Node(int a, int k, int n){
        addr = a;
        next = n;
        key = k;
    }
};

void output(vector<Node*> &nodes){
    if(nodes.empty()) {
        return;
    }
    for(int i = 0; i < nodes.size(); i++){
        printf("%05d %d ", nodes[i]->addr, nodes[i]->key);
        if(i == nodes.size() - 1){
            printf("-1\n");
        } else {
            printf("%05d\n", nodes[i+1]->addr);
        }
    }
}

int main(){
    int begin_add, N;
    cin >> begin_add >> N;
    unordered_map<int, Node *> add_map;
    for(int i = 0; i < N; i++){
        int a, n, k;
        cin >> a >> k >> n;
        Node *node = new Node(a, k, n);
        add_map[a] = node;
    }

    unordered_map<int, bool> existed;
    vector<Node *> remain_node, removed_nodes;
    int add = begin_add;
    while(add != -1){
        Node * node = add_map[add];
        if(existed.count(abs(node->key)) == 0){
            remain_node.push_back(node);
            existed[abs(node->key)] = true;
        } else {
            removed_nodes.push_back(node);
        }
        add = node->next;
    }

    output(remain_node);
    output(removed_nodes);
}