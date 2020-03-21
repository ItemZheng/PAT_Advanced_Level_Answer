#include <iostream>
#include <vector>

// 注意点：
//      1、先判断 有几个component，O(N) 基本就可以了
//      2、再判断高度，N^2
//      3、更好的思路：判断完component之后就两次深度优先搜索，先从任意一个结点dfs后保留最高高度拥有的结点们，
//          然后从这些结点中的其中任意一个开始dfs得到最高高度的结点们，
//          这两个结点集合的并集就是所求

using namespace std;

class Vertex{
public:
    vector<int> edges;

    // visit
    bool visit;
public:
    Vertex(){ visit = false;}
    void add_edge(int v){
        edges.push_back(v);
    }
};

int rootOf(int index, int com[]){
    while(com[index] >= 0){
        index = com[index];
    }
    return index;
}

int height(int id, int h, Vertex vertexs[]){
    int max_h = h;
    vertexs[id].visit = true;
    for(int i = 0; i < vertexs[id].edges.size(); i++){
        if(!vertexs[vertexs[id].edges[i]].visit){
            if(height(vertexs[id].edges[i], h + 1, vertexs) > max_h){
                max_h = height(vertexs[id].edges[i], h + 1, vertexs);
            }
        }
    }
    vertexs[id].visit = false;
    return max_h;
}

int main(){
    int N;
    cin >> N;

    // judge component
    Vertex vertexs[N];
    int com[N];
    for(int i = 0; i < N; i++){
        com[i] = -1;
    }
    for(int i = 0; i < N - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;

        // merge
        if(rootOf(v1, com) != rootOf(v2, com)){
            com[rootOf(v1, com)] = rootOf(v2, com);
        }
        vertexs[v1].add_edge(v2);
        vertexs[v2].add_edge(v1);
    }

    // get component number
    int count = 0;
    for(int i = 0; i < N; i++){
        if(com[i] < 0){
            count++;
        }
    }
    if(count > 1){
        cout << "Error: "<< count <<" components";
        return 0;
    }

    // save all root
    int max_height = 0;
    vector<int> roots;
    for(int i = 0; i < N; i++){
        int h = height(i, 1, vertexs);
        if(h > max_height){
            roots.clear();
            max_height = h;
            roots.push_back(i);
        } else if( h == max_height){
            roots.push_back(i);
        }
    }

    for(int i = 0; i < roots.size(); i++){
        cout << roots[i] + 1 << endl;
    }
}