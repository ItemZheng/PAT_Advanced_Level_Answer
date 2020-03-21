#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑。注意rootOf的条件是 < 0

int rootOf(int clusters[], int id){
    while(clusters[id] >= 0){
        id = clusters[id];
    }
    return id;
}

int main(){
    int N;
    cin >> N;

    vector<int> hobbies[1001];
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int K = stoi(s);
        for(int j = 0; j < K; j++){
            int h;
            cin >> h;
            hobbies[h].push_back(i);
        }
    }

    int cluster[N];
    for(int i = 0; i < N; i++){
        cluster[i] = -1;
    }

    for(int h = 1; h < 1001; h++){
        for(int i = 1; i < hobbies[h].size(); i++){
            int id1 = hobbies[h][i - 1], id2 = hobbies[h][i];
            int r1 = rootOf(cluster, id1), r2 = rootOf(cluster, id2);
            if(r1 != r2){
                cluster[r1] = cluster[r1] + cluster[r2];
                cluster[r2] = r1;
            }
        }
    }

    vector<int> numbers;
    for(int i = 0; i < N; i++){
        if(cluster[i] < 0){
            numbers.push_back(-cluster[i]);
        }
    }
    sort(numbers.rbegin(), numbers.rend());
    cout << numbers.size() << endl;
    for(int i = 0; i < numbers.size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << numbers[i];
    }
    cout << endl;
}