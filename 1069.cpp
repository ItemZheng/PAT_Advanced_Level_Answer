#include <iostream>
#include <algorithm>

using namespace std;

// 无坑。
//      注意如果输入就是 6174，那也要输出一遍
//      注意首先要把输入转化为4位的string
//      思路：写一个能把string从小到大排序或从大到小排序的函数

bool cmp(char a, char b){
    return a > b;
}

string sortStr(string ori, bool ase){
    char o[5];
    for(int i = 0; i < 4; i++){
        o[i] = ori[i];
    }
    o[4] = '\0';
    if(ase){
        sort(o,o + 4);
    } else {
        sort(o, o + 4, cmp);
    }
    return string(o);
}

int main(){
    int input;
    cin >> input;
    char str[5];
    sprintf(str, "%04d",input);
    string origin_number = string(str);

    if(sortStr(origin_number, true) == sortStr(origin_number, false)){
        cout << origin_number << " - " << origin_number << " = 0000" << endl;
    } else {
        string num = origin_number;
        do{
            string asc_num = sortStr(num, true);
            string desc_num = sortStr(num, false);
            int x = stoi(desc_num) - stoi(asc_num);
            char res[5];
            sprintf(res, "%04d", x);
            string res_str = string(res);
            cout << desc_num << " - " << asc_num << " = " << res_str << endl;
            num = res_str;
        }while(num != "6174");
    }
}