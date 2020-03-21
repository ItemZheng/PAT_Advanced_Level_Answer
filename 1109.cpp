#include <iostream>
#include <algorithm>

using namespace std;

// 无坑。先按照题目要求排序，先按身高从高到低，再按字母顺序
//      然后计算每一行的人员排序

class Person{
public:
    string name;
    int height;
};

bool cmp(Person *p1, Person *p2){
    if(p1->height != p2->height){
        return p1->height > p2->height;
    }
    return p1->name < p2->name;
}

int main(){
    int N, K;
    cin >> N >> K;

    Person *person[N];
    for(int i = 0; i < N; i++){
        Person *p = new Person();
        cin >> p->name >> p->height;
        person[i] = p;
    }
    sort(person, person + N, cmp);

    Person ** p = person;
    for(int i = 0; i < K; i++){
        int size = N / K;
        if(i == 0){
            size = N - (N / K) * (K - 1);
        }

        Person * row[size];
        row[size / 2] = p[0];
        int left = size / 2 - 1, right = size / 2 + 1, idx = 1;
        while(idx < size){
            if(left >= 0){
                row[left--] = p[idx++];
            }
            if(idx >= size){
                break;
            }
            if(right < size){
                row[right++] = p[idx++];
            }
        }
        for(int j = 0; j < size; j++){
            if(j > 0){
                cout << " ";
            }
            cout << row[j]->name;
        }
        cout << endl;
        p = p + size;
    }
}