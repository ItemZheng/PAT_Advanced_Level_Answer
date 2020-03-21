#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑。

class Student{
public:
    string name;
    int online = -1, g_mid = -1, g_final = -1, g = -1;
public:
    void calculate(){
        if(g_final >= g_mid){
            g = g_final;
        } else {
            g = (int)round(0.4 * g_mid + 0.6 * g_final);
        }
    }

    void output(){
        cout << name << " " << online << " " << g_mid << " " << g_final << " " << g << endl;
    }

};

bool cmp(Student *s1, Student *s2){
    if(s1->g != s2->g){
        return s1->g > s2->g;
    }
    return s1->name < s2->name;
}

int main(){
    unordered_map<string, Student *> name_map;
    int P, M, N;
    cin >> P >> M >> N;

    for(int i = 0; i < P; i++){
        string name;
        int g;
        cin >> name >> g;
        if(g >= 200){
            Student * s = new Student();
            s->online = g;
            s->name = name;
            name_map[name] = s;
        }
    }

    for(int i = 0; i < M; i++){
        string name;
        int g;
        cin >> name >> g;
        if(name_map.count(name) > 0){
            name_map[name]->g_mid = g;
        }
    }

    for(int i = 0; i < N; i++){
        string name;
        int g;
        cin >> name >> g;
        if(name_map.count(name) > 0){
            name_map[name]->g_final = g;
            name_map[name]->calculate();
        }
    }

    vector<Student *> students;
    for(unordered_map<string, Student *> ::iterator it = name_map.begin(); it != name_map.end(); it++){
        if(it->second->g >= 60){
            students.push_back(it->second);
        }
    }

    sort(students.begin(), students.end(), cmp);
    for(int i = 0; i < students.size(); i++){
        students[i]->output();
    }

}