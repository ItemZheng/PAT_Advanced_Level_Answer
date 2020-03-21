#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑，认真读题即可，注意比较

class Person{
public:
    string id;
    int virtue_grade, talent_grade;
    int level;
public:
    Person(string i, int v, int t){
        id = i;
        virtue_grade = v;
        talent_grade = t;
    }

    void output(){
        cout << id << " " << virtue_grade << " " << talent_grade << endl;
    }
};

bool cmp(Person *p1, Person *p2){
    if(p1->level != p2->level){
        return p1->level > p2->level;
    } else if(p1->virtue_grade + p1->talent_grade != p2->virtue_grade + p2->talent_grade){
        return p1->virtue_grade + p1->talent_grade > p2->virtue_grade + p2->talent_grade;
    } else if(p1->virtue_grade != p2->virtue_grade){
        return p1->virtue_grade > p2->virtue_grade;
    } else {
        return p1->id < p2->id;
    }
}

int main(){
    vector<Person *> persons;
    int N, L, H;
    cin >> N >> L >> H;
    for(int i = 0; i < N; i++){
        string id;
        int v_grade, t_grade;
        cin >> id >> v_grade >> t_grade;
        if(v_grade >= L && t_grade >= L){
            Person *p = new Person(id, v_grade, t_grade);
            persons.push_back(p);
            if(v_grade >= H && t_grade >= H){
                p->level = 10;
            } else if(t_grade < H && v_grade >= H){
                p->level = 9;
            } else if(t_grade < H && v_grade < H && v_grade >= t_grade){
                p->level = 8;
            } else {
                p->level = 7;
            }
        }
    }
    sort(persons.begin(), persons.end(), cmp);
    cout << persons.size() << endl;
    for(int i = 0; i < persons.size(); i++){
        persons[i]->output();
    }
}
