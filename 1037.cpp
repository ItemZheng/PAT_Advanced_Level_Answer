#include <iostream>
#include <vector>
#include <algorithm>

// 无坑，思路：从大到小排序，正向，两个都大于0才相乘，否则Break；反向，两个都小于0相乘，否则Break

using namespace std;

bool decrease(int &x, int &y){
    return x > y;
}

int main(){
    int nc, np;
    cin >> nc;
    vector<int> cs, ps;
    for(int i = 0; i < nc; i++){
        int x;
        cin >> x;
        cs.push_back(x);
    }

    cin >> np;
    for(int i = 0; i < np; i++){
        int x;
        cin >> x;
        ps.push_back(x);
    }

    sort(cs.begin(), cs.end(), decrease);
    sort(ps.begin(), ps.end(), decrease);

    int sum = 0;
    for(int i = 0; i < nc && i < np; i++){
        int x = cs[i], y = ps[i];
        if(x > 0 && y > 0){
            sum = sum + x * y;
        } else {
            break;
        }
    }
    for(int i = nc - 1, j = np - 1; i >= 0 && j >= 0; i--, j--){
        int x = cs[i], y = ps[j];
        if(x < 0 && y < 0){
            sum = sum + x * y;
        } else {
            break;
        }
    }
    cout << sum << endl;
}

