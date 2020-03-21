#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 没有坑

class Student{
public:
    string record_str;

    string id;
    string name;
    int score;
public:
    Student(string str){
        record_str = str;

        int idx = str.find(' ');
        id = str.substr(0, idx);
        str = str.substr(idx + 1);

        idx = str.find(' ');
        name = str.substr(0, idx);
        str = str.substr(idx + 1);

        score = stoi(str);
    }

    void output() const {
        cout << record_str << endl;
    }
};

int type;

bool compare(Student &s1, Student &s2){
    if(type == 1){
        return s1.id < s2.id;
    } else if(type == 2){
        if(s1.name != s2.name){
            return s1.name < s2.name;
        } else {
            return s1.id < s2.id;
        }
    } else{
        if(s1.score != s2.score){
            return s1.score < s2.score;
        } else {
            return s1.id < s2.id;
        }
    }
}

int main(){
    vector<Student> students;
    int N;
    cin >> N >> type;
    string no;
    getline(cin, no);
    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);
        Student * stu = new Student(str);
        students.push_back(*stu);
    }
    sort(students.begin(), students.end(), compare);
    for(int i = 0; i < N; i++){
        students[i].output();
    }
}