#include <iostream>
#include <string>

using namespace std;

// 无坑。思路：分别找到N位有效位数，没有的话用零补齐；注意0的特殊情况；然后计算exp，

pair<string, int> transform(string str, int N){
    // decide digits
    string digits = string(N, '0');
    int idx = 0, first_idx = -1;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '.'){
            if(first_idx != -1 || str[i] != '0'){
                digits[idx++] = str[i];
                if(first_idx == -1){
                    first_idx = i;
                }
                if(idx >= N){
                    break;
                }
            }
        }
    }
    if(first_idx == -1){
        return pair<string, int>("0." + digits, 0);
    }

    // decide exp
    int point_idx = str.find('.');
    if(point_idx == string::npos){
        point_idx = str.size();
    }
    int exp = point_idx - first_idx;
    if(exp < 0){
        exp++;
    }
    return pair<string, int>("0." + digits, exp);
}

void output(pair<string, int> num){
    cout << num.first << "*10^" << num.second;
}

int main(){
    int N;
    string n1, n2;
    cin >> N >> n1 >> n2;
    pair<string, int> t1 = transform(n1, N), t2 = transform(n2, N);
    if(t1 == t2){
        cout << "YES ";
        output(t1);
    } else {
        cout << "NO ";
        output(t1);
        cout << " ";
        output(t2);
    }
}