#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 无坑

class Student{
public:
    int id, GE, GI;
    vector<int> applicants;
public:
    Student(){}
};

class School{
public:
    int quota;
    priority_queue<int, vector<int>, greater<int>> students;
    int last_GE = -1, last_GI = -1;
public:
    School(){}

    void output(){
        if(students.size() > 0){
            cout << students.top();
            students.pop();
            while(!students.empty()){
                cout << " " << students.top();
                students.pop();
            }
        }
        cout << endl;
    }

    bool accept(Student *s){
        if((s->GE == last_GE && s->GI == last_GI) || quota > 0){
            last_GI = s->GI;
            last_GE = s->GE;
            students.push(s->id);
            quota--;
            return true;
        }
        return false;
    }
};

bool cmp(Student * s1, Student *s2){
    if(s1->GE + s1->GI != s2->GE + s2->GI){
        return s1->GE + s1->GI > s2->GE + s2->GI;
    } else{
        return s1->GE > s2->GE;
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    Student *students[N];
    School school[M];
    for(int i = 0; i < M; i++){
        cin >> school[i].quota;
    }
    for(int i = 0; i < N; i++){
        Student *s = new Student();
        cin >> s->GE >> s->GI;
        s->id = i;
        for(int j = 0; j < K; j++){
            int school;
            cin >> school;
            s->applicants.push_back(school);
        }
        students[i] = s;
    }

    sort(students, students + N, cmp);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < students[i]->applicants.size(); j++){
            if(school[students[i]->applicants[j]].accept(students[i])){
                break;
            }
        }
    }

    for(int i = 0; i < M; i++){
        school[i].output();
    }
}