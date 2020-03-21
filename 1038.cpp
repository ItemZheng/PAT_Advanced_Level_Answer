#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//  无坑，但是比较难想到
//      需要用字符串比较，只要s1s2 < s2s1 那就说明s1要排到前面; 交换法其实是

bool increase(string &s1, string &s2){
    return s1 + s2 < s2 + s1;
}

int main(){

    int n;
    cin >> n;
    vector<string> numbers;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        numbers.push_back(s);
    }

    sort(numbers.begin(), numbers.end(), increase);

    string result;
    for(int i = 0; i < n; i++){
        result.append(numbers[i]);
    }
    while(!result.empty() && result[0] == '0'){
        result = result.substr(1);
    }
    if(!result.empty()){
        cout << result << endl;
    } else {
        cout << "0" << endl;
    }
}