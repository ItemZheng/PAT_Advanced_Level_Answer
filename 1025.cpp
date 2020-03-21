#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

// 无坑，用map和vector即可

using namespace std;

int main(){
    int N;
    cin >> N;

    int local_rank[N][101];
    map<string, int> id_local_map;
    vector<string> total_rank[101];

    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 101; j++){
            local_rank[i][j] = 0;
        }

        int K;
        cin >> K;
        count = count + K;
        for(int j = 0; j < K; j++){
            string id;
            int score;
            cin >> id >> score;
            id_local_map[id] = i;
            local_rank[i][score]++;
            total_rank[score].push_back(id);
        }

        // rank local
        int total = 0;
        for(int j = 100; j >= 0; j--){
            total = total + local_rank[i][j];
            local_rank[i][j] = total - local_rank[i][j];
        }
    }

    cout << count << endl;
    int total = 0;
    for(int i = 100; i >= 0; i--){
        vector<string> ids = total_rank[i];
        total = total + ids.size();
        int rank = total - ids.size();

        sort(ids.begin(), ids.end());
        for(int j = 0; j < ids.size(); j++){
            cout << ids[j] << " " << rank + 1 << " " << id_local_map[ids[j]] + 1 << " " << local_rank[id_local_map[ids[j]]][i] + 1 << endl;
        }
    }

}