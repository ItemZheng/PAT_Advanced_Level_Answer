#include <iostream>

using namespace std;

// 无坑，简单的动态规划

int main(){
    int p_count = 0, pa_count = 0, pat_count = 0;
    string number;
    cin >> number;
    for(int i = 0; i < number.size(); i++){
        if(number[i] == 'P'){
            p_count = (p_count + 1) % 1000000007;
        } else if(number[i] == 'A'){
            pa_count = (pa_count + p_count) % 1000000007;
        } else if(number[i] == 'T'){
            pat_count = (pat_count + pa_count) % 1000000007;
        }
    }
    cout << pat_count << endl;
}