#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑，但是注意本题是使用并查集求解，因为本题并没有给出所有的用户信息，DFS需要完整的信息

class Person{
public:
    int father = -1, mother = -1;
    vector<int> children;

    int set = 0, area = 0;
    int family = -1;
};

class Solution{
public:
    int id, count, area, set;
};

bool cmp(Solution *s1, Solution *s2){
    if(s1->area * 1.0 / s1->count != s2->area * 1.0 / s2->count){
        return s1->area * 1.0 / s1->count > s2->area * 1.0 / s2->count;
    }
    return s1->id < s2->id;
}

int rootOf(Person *person[], int id){
    while(person[id]->family >= 0){
        id = person[id]->family;
    }
    return id;
}

void merge(Person *person[], int id1, int id2){
    int r1 = rootOf(person, id1), r2 = rootOf(person, id2);
    if(r1 == r2){
        return;
    }
    int minId = r1 < r2 ? r1 : r2, maxId = r1 > r2 ? r1 : r2;
    person[minId]->family = person[minId]->family + person[maxId]->family;
    person[maxId]->family = minId;
    person[minId]->set += person[maxId]->set;
    person[minId]->area += person[maxId]->area;
}

void visit(Person *person[], int id){
    if(person[id]->father != -1){
        merge(person, id, person[id]->father);
    }
    if(person[id]->mother != -1){
        merge(person, id, person[id]->mother);
    }
    for(int i = 0; i < person[id]->children.size(); i++){
        merge(person, id, person[id]->children[i]);
    }
}

int main(){
    // init
    Person *person[10001];
    for(int i = 0; i < 10001; i++){
        person[i] = nullptr;
    }

    // input
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        Person *p = new Person();
        int id, k;
        cin >> id >> p->father >> p->mother >> k;
        if(person[p->father] == nullptr){
            person[p->father] = new Person();
        }
        if(person[p->mother] == nullptr){
            person[p->mother] = new Person();
        }
        for(int j = 0; j < k; j++){
            int c;
            cin >> c;
            p->children.push_back(c);
            if(person[c] == nullptr){
                person[c] = new Person();
            }
        }
        cin >> p->set >> p->area;
        person[id] = p;
    }

    // visit
    for(int i = 0; i < 10001; i++){
        if(person[i] != nullptr){
            visit(person, i);
        }
    }

    // output
    vector<Solution *> solutions;
    for(int i = 0; i < 10001; i++){
        if(person[i] != nullptr && person[i]->family < 0){
            Solution *s = new Solution();
            s->id = i;
            s->count = -person[i]->family;
            s->area = person[i]->area;
            s->set = person[i]->set;
            solutions.push_back(s);
        }
    }
    printf("%ld\n", solutions.size());
    sort(solutions.begin(), solutions.end(), cmp);
    for(int i = 0; i < solutions.size(); i++){
        printf("%04d %d %.3f %.3f\n", solutions[i]->id, solutions[i]->count,
               solutions[i]->set * 1.0 / solutions[i]->count, solutions[i]->area * 1.0 / solutions[i]->count);
    }

}