#include <iostream>
#include <string>
#include <map>
#include <queue>

// 注意点：如果只有一个账户，注意要输出 is 1 account 而不是 are N accounts

using namespace std;

map<char, char> swap_map;
queue<pair<string, string>> teams;

int main(){
    int N;
    cin >> N;

    swap_map['1'] = '@';
    swap_map['0'] = '%';
    swap_map['l'] = 'L';
    swap_map['O'] = 'o';

    for(int i = 0; i < N; i++){
        string team, password;
        cin >> team >> password;
        bool mod = false;
        for(int j = 0; j < password.size(); j++){
            if(swap_map.count(password[j]) > 0){
                password[j] = swap_map[password[j]];
                mod = true;
            }
        }
        if(mod)
            teams.push(pair<string, string>(team, password));
    }
    if(teams.size() > 0){
        cout << teams.size() << endl;
    } else {
        if(N == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << N << " accounts and no account is modified" << endl;
    }
    while(!teams.empty()){
        cout << teams.front().first << " " << teams.front().second << endl;
        teams.pop();
    }
}