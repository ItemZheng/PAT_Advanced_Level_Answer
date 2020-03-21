#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int length = s.size();
        long long Z = stoi(s);
        long long A = stoi(s.substr(0, length / 2));
        long long B = stoi(s.substr(length / 2));
        if(A * B != 0 && Z % (A * B) == 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}