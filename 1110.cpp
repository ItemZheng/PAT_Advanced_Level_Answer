#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 无坑。
//  先重新构建二叉树，然后获取level_order的顺序，用下面方法判断
//  1、完全二叉树的特点是 结点的左儿子是 2 * i - 1 右儿子是 2 * i
//  2、也可以按顺序遍历，孩子的个数一定是  2 。。。。2 1 0 0

class Node {
public:
    Node *left = nullptr, *right = nullptr;
    int id;
    bool hasParent = false;
};

int main(){
    // input
    int N;
    cin >> N;
    Node nodes[N];
    for(int i = 0; i < N; i++){
        string s1, s2;
        cin >> s1 >> s2;

        nodes[i].id = i;
        if(s1 != "-"){
            int id1 = stoi(s1);
            nodes[i].left = &nodes[id1];
            nodes[id1].hasParent = true;
        }
        if(s2 != "-"){
            int id2 = stoi(s2);
            nodes[i].right = &nodes[id2];
            nodes[id2].hasParent = true;
        }
    }

    // get root
    Node * root = &nodes[0];
    for(int i = 0; i < N; i++){
        if(!nodes[i].hasParent){
            root = &nodes[i];
            break;
        }
    }

    // get ordered nodes
    queue<Node *> level_nodes;
    vector<Node *> order_nodes;
    level_nodes.push(root);
    while(!level_nodes.empty()){
        Node *n = level_nodes.front();
        level_nodes.pop();
        order_nodes.push_back(n);
        if(n->left != nullptr){
            level_nodes.push(n->left);
        }
        if(n->right != nullptr){
            level_nodes.push(n->right);
        }
    }

    // judge
    bool valid = true;
    for(int i = 0; i < order_nodes.size(); i++){
        int l = 2 * i + 1;
        if(l < order_nodes.size()){
            if(order_nodes[l] != order_nodes[i]->left){
                valid = false;
                break;
            }

            l++;
            if(l < order_nodes.size()){
                if(order_nodes[l] != order_nodes[i]->right){
                    valid = false;
                    break;
                }
            }
        }
    }

    if(valid){
        cout << "YES " << order_nodes[N - 1]->id << endl;
    } else {
        cout << "NO " << order_nodes[0]->id << endl;
    }
}