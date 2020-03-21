#include <iostream>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

// 好题。本题是在栈上增加获取中位数操作，思路是除了栈外在维护一个中位数
//      维护有序vector时间复杂度过于高，push和pop需要移动大量元素
//      维护两个heap的话，由于heap不能随意删除元素，因此不行
//      最后采用的是两个multiset，可以维护有序的数列，而且可以随意删除元素

multiset<int> upper;        // 中位数之上，从小到大
multiset<int, greater<int>> lower;  //中位数之下，从大到小

void adjust(){
    if(upper.size() > lower.size()){
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    } else if(lower.size() > upper.size() + 1){
        upper.insert(*lower.begin());
        lower.erase(lower.begin());
    }
}

int main(){
    stack<int> s;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "PeekMedian"){
            if(s.empty()){
                cout << "Invalid" << endl;
            } else {
                cout << *lower.begin() << endl;
            }
        } else if(cmd == "Push"){
            int num;
            cin >> num;

            // push to stack
            s.push(num);
            // push to set
            if(lower.empty() || num <= *lower.begin()){
                lower.insert(num);
            } else {
                upper.insert(num);
            }
            adjust();
        } else if(cmd == "Pop"){
            if(s.empty()){
                cout << "Invalid" << endl;
            } else {
                int num = s.top();
                s.pop();
                cout << num << endl;
                if(num <= *lower.begin()){
                    lower.erase(lower.find(num));
                } else {
                    upper.erase(upper.find(num));
                }
                adjust();
            }
        }
    }
}