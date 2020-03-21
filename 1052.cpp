#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 有坑点。
// 思路：
//      1、先从给出的存储信息，构建出目标链表
//      2、遍历链表，搭建vector
//      3、vector排序后输出
// 坑点：
//      1、他给的地址可能是-1，即是一个空链表，输出需要注意
//      2、注意输出的地址一定是5位的，用string保存地址比较省心，用int存注意输出格式（尤其是第一行的起始地址格式）

class Node{
public:
    string addr;
    int key;
    string next;
public:
    Node(string a, int k, string n){
        addr = a;
        key = k;
        next = n;
    }
};

bool compare(Node &n1, Node &n2){
    return n1.key < n2.key;
}

int main(){
    unordered_map<string, Node*> add_map;
    vector<Node> add_v;
    int N;
    string begin;
    cin >> N >> begin;

    for(int i = 0; i < N; i++){
        string a, n;
        int k;
        cin >> a >> k >> n;

        Node *node = new Node(a, k, n);
        add_map[a] = node;
    }

    string addr = begin;
    while(addr != "-1"){
        add_v.push_back(*(add_map[addr]));
        addr = add_map[addr]->next;
    }

    sort(add_v.begin(), add_v.end(), compare);

    if(add_v.size() == 0){
        cout << 0 << " " << -1 << endl;
        return 0;
    }
    cout << add_v.size() << " " << add_v[0].addr << endl;
    for(int i = 0; i < add_v.size(); i++){
        cout <<  add_v[i].addr << " " << add_v[i].key << " ";
        if(i < add_v.size() - 1){
            cout <<  add_v[i + 1].addr;
        } else {
            cout << -1;
        }
        cout << endl;
    }
}