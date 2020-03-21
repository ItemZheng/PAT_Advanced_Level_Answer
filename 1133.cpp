#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 无坑。

using namespace std;

class Node {
public:
    int address = 0, key = 0, next = -1, level = 0, pos = 0;
};

int K;

bool cmp(Node * n1, Node *n2){
    if(n1->level != n2->level){
        return n1->level < n2->level;
    }
    return n1->pos < n2->pos;
}

int main(){
    int N, begin;
    cin >> begin >> N >> K;

    unordered_map<int, Node *> add_map;
    for(int i = 0; i < N; i++){
        Node *node = new Node();
        cin >> node->address >> node->key >> node->next;
        if(node->key < 0){
            node->level = -2;
        } else if(node->key <= K){
            node->level = -1;
        } else{
            node->level = 0;
        }
        add_map[node->address] = node;
    }

    vector<Node *> lists;
    int pos = 0;
    while(begin != -1){
        Node * node = add_map[begin];
        lists.push_back(node);
        node->pos = pos++;
        begin = node->next;
    }

    sort(lists.begin(), lists.end(), cmp);
    for(int i = 0; i < lists.size(); i++){
        printf("%05d %d ", lists[i]->address, lists[i]->key);
        if(i < lists.size() - 1){
            printf("%05d\n", lists[i + 1]->address);
        } else {
            printf("-1\n");
        }
    }

}