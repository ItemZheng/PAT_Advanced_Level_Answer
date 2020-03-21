#include <iostream>
#include <vector>

using namespace std;

// 无坑，一个BFS函数遍历即可

class User{
public:
    vector<int> followers;
    bool visited = false;
};

int BFS(int userId, int K, User users[]){
    int count = 0;

    vector<int> visit_users;
    visit_users.push_back(userId);
    users[userId].visited = true;

    for(int level = 0; level < K; level++){
        vector<int> next;
        for(int i = 0; i < visit_users.size(); i++){
            int id = visit_users[i];
            for(int k = 0; k < users[id].followers.size(); k++){
                if(!users[users[id].followers[k]].visited){
                    next.push_back(users[id].followers[k]);
                    users[users[id].followers[k]].visited = true;
                    cout << users[id].followers[k] << " ";
                    count++;
                }
            }
        }
        cout << endl;
        visit_users = next;
    }
    return count;
}

int main(){
    int N, L;
    cin >> N >> L;

    User users[N];
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        for(int j = 0; j < K; j++){
            int follow;
            cin >> follow;
            users[follow - 1].followers.push_back(i);
        }
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int begin = 0;
        cin >> begin;
        cout << BFS(begin - 1, L, users) << endl;
        for(int j = 0; j < N; j++){
            users[j].visited = false;
        }
    }
}