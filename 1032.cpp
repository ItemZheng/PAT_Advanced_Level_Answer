#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, string> addresses;
    string b1, b2;
    int N;
    cin >> b1 >> b2 >> N;
    for(int i = 0; i < N; i++){
        string p, n, ch;
        cin >> p >> ch >> n;
        addresses[p] = n;
    }

    map<string, bool> exist;
    while(b1 != "-1"){
        exist[b1] = true;
        b1 = addresses[b1];
    }

    // visit b2
    while(b2 != "-1"){
        if(exist.count(b2) != 0){
            cout << b2 << endl;
            return 0;
        }
        b2 = addresses[b2];
    }
    cout << -1 << endl;
}