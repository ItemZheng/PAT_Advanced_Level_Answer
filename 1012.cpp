#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Student{
public:
    int c, m, e, a;
public:
    Student(int c, int m, int e){
        this->c = c;
        this->m = m;
        this->e = e;
        this->a = c + m + e;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    int rank_c[101], rank_m[101], rank_e[101], rank_a[301];
    unordered_map<string, Student *> stu_map;
    for(int i = 0; i < 101; i++){
        rank_c[i] = rank_m[i] = rank_e[i] = 0;
    }
    for(int i = 0; i < 301; i++)    rank_a[i] = 0;

    // set map
    for(int i = 0; i < N; i++){
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        Student * stu = new Student(c, m, e);
        rank_a[stu->a]++;
        rank_e[stu->e]++;
        rank_c[stu->c]++;
        rank_m[stu->m]++;
        stu_map[id] = stu;
    }

    // update rank
    int sum_c = 0, sum_m = 0, sum_e = 0, sum_a = 0;
    for(int i = 100; i >= 0; i--){
        sum_c = sum_c + rank_c[i];
        rank_c[i] = sum_c - rank_c[i];

        sum_m = sum_m + rank_m[i];
        rank_m[i] = sum_m - rank_m[i];

        sum_e = sum_e + rank_e[i];
        rank_e[i] = sum_e - rank_e[i];
    }
    for(int i = 300; i >= 0; i--){
        sum_a = sum_a + rank_a[i];
        rank_a[i] = sum_a - rank_a[i];
    }

    // Query
    for(int i = 0; i < M; i++){
        string id;
        cin >> id;
        if(stu_map.count(id) == 0){
            cout << "N/A" << endl;
        } else {
            Student * stu = stu_map[id];
            int ra = rank_a[stu->a], rc = rank_c[stu->c], rm = rank_m[stu->m], re = rank_e[stu->e];
            int min_r = re;
            char sub = 'E';
            if(rm <= min_r){
                min_r = rm;
                sub = 'M';
            }
            if(rc <= min_r){
                min_r = rc;
                sub = 'C';
            }
            if(ra <= min_r){
                min_r = ra;
                sub = 'A';
            }
            cout << min_r + 1 << " " << sub << endl;
        }
    }
}