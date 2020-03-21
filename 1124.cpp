#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 无坑。

int main(){
    int M, N, S;
    cin >> M >> N >> S;

    // read in
    vector<string> followers;
    unordered_map<string, bool> winner;
    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        followers.push_back(s);
        winner[s] = false;
    }

    if(S > M){
        cout << "Keep going..." << endl;
    } else {
        int idx = S - 1;
        while(idx < M){
            // have win
            while (idx < M && winner[followers[idx]]){
                idx++;
            }

            // end of follower
            if(idx >= M){
                break;
            }

            cout << followers[idx] << endl;
            winner[followers[idx]] = true;
            idx = idx + N;
        }
    }
}