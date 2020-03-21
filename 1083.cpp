#include <iostream>

using namespace std;

// 无坑。简单。

class Student{
public:
    string name, id;
public:
    Student(){}
    void output(){
        cout << name << " " << id << endl;
    }
};

int main(){
    Student * students[101];
    for(int i = 0; i < 101; i++){
        students[i] = nullptr;
    }

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        Student *s = new Student();
        cin >> s->name >> s->id;
        int grade;
        cin >> grade;
        students[grade] = s;
    }

    int min, max;
    cin >> min >> max;
    bool existed = false;
    for(int i = max; i >= min; i--){
        if(students[i] != nullptr){
            existed = true;
            students[i]->output();
        }
    }
    if(!existed){
        cout << "NONE";
    }
}