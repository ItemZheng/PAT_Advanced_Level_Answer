#include <iostream>
#include <algorithm>
#include <vector>

// 无坑，思路：直接按照输出标准排序，然后遍历整个数组找到符合的人
//  如果先按年龄做hash数组，然后取对应的年龄，然后再按输出标准排序的话，会造成时间复杂度过高

using namespace std;

class People{
public:
    string name;
    int age;
    int net;
public:
    People(string n, int a, int t){
        name = n;
        age = a;
        net = t;
    }

    void output(){
        cout << name << " " << age << " " << net << endl;
    }
};

bool compare(People *p1, People *p2){
    if(p1->net != p2->net)
        return p1->net > p2->net;
    else if(p1->age != p2->age){
        return p1->age < p2->age;
    }
    return p1->name < p2->name;
}

int main(){
    vector<People *> all_person;
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string name;
        int age, net;
        cin >> name >> age >> net;
        People *p = new People(name, age, net);
        all_person.push_back(p);
    }

    sort(all_person.begin(), all_person.end(), compare);

    // query
    for(int i = 0; i < K; i++){
        int count, amin, amax;
        cin >> count >> amin >> amax;

        cout << "Case #" << i + 1 << ":" << endl;
        int out_count = 0;
        for(int j = 0; j < all_person.size(); j++){
            if(all_person[j]->age >= amin && all_person[j]->age <= amax){
                out_count++;
                all_person[j]->output();
                if(out_count >= count){
                    break;
                }
            }
        }
        if(out_count == 0){
            cout << "None" << endl;
            continue;
        }
    }
}