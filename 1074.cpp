#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 无坑，看清楚题目即可。是reverse every K element，而不是 first K element
// 如果超时就把unordered_map改成Node *数组

using namespace std;

class Node{
public:
    string add;
    int key;
    string next;
public:
    Node(string a, int k, string n){
        add = a;
        key = k;
        next = n;
    }
};

int main(){
    string begin;
    int N, K;
    cin >> begin >> N >> K;

    unordered_map<string, Node *> address_map;
    for(int i = 0; i < N; i++){
        string a, n;
        int k;
        cin >> a >> k >> n;
        Node * node = new Node(a, k, n);
        address_map[a] = node;
    }

    if(begin == "-1"){
        cout << -1 << endl;
        return 0;
    }

    vector<Node *> lists;
    while(begin != "-1"){
        Node * node = address_map[begin];
        lists.push_back(node);
        begin = node->next;
    }
    for(int i = 0; (i + 1) * K <= lists.size(); i++){
        reverse(lists.begin() + i * K, lists.begin() + i * K + K);
    }
    for(int i = 0; i < lists.size(); i++){
        cout << lists[i]->add << " " << lists[i]->key << " ";
        if(i == lists.size() - 1){
            cout << -1 << endl;
        } else {
            cout << lists[i + 1]->add << endl;
        }
    }
}