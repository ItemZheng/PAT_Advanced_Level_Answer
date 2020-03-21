#include <vector>
#include <iostream>

using namespace std;

//无坑。用数组保存数被猜到几次，然后保存猜数字的人的顺序，找到第一个次数为1的即可

int main(){
    int number[10001];
    for(int i = 0; i < 10001; i++){
        number[i] = 0;
    }

    int N;
    cin >> N;
    vector<int> players;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        number[x]++;
        players.push_back(x);
    }

    for(int i = 0; i < players.size(); i++){
        if(number[players[i]] == 1){
            cout << players[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}

