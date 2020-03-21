#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

// 注意点：注意局部变量
// 也可以用DFS，遍历这个树，然后记录每一个level的叶子数量

using namespace std;

int main(){
    int N = 0, M = 0;
    cin >> N >> M;
    map<string, vector<string> *> p_child_maps;
    for(int i = 0; i < M; i++){
        string p;
        int n_child = 0;
        cin >> p >> n_child;
        vector<string> *children = new vector<string>();
        for(int j = 0; j < n_child; j++){
            string c;
            cin >> c;
            children->push_back(c);
        }
        p_child_maps.insert(pair<string, vector<string>* >(p, children));
    }

    // visit
    string current_p = "01";
    queue<string*> nodes;
    nodes.push(&current_p);
    nodes.push(nullptr);    // use nullptr to mark new level
    int count = 0;
    bool first = true;
    while (!nodes.empty()){
        string *node = nodes.front();
        nodes.pop();
        if(node == nullptr){
            if(first){
                cout << count;
                first = false;
            } else {
                cout << " " << count;
            }
            if(!nodes.empty()){
                nodes.push(nullptr); // new level
                count = 0;
            } else {
                break;
            }
            continue;
        }

        // get children
        if(p_child_maps.count(*node) != 0){
            vector<string> *children = p_child_maps[*node];
            if(children == nullptr){
                break;
            }
            for(int i = 0; i < children->size(); i++){
                nodes.push(&(*children)[i]);
            }
        } else {
            count++;
        }
    }
    return 0;
}