#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int k = (s.size() + 2) / 3, n = s.size() + 2 - 2 * k;
    for(int i = 0; i < k - 1; i++){
        string space(n - 2, ' ');
        cout << s[0] << space << s[s.size() - 1] << endl;
        s = s.substr(1, s.size() - 2);
    }
    cout << s << endl;
}