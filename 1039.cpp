#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 无坑：对时间复杂度有要求
//      把map改成unordered_map会有较大的提升
//      本题priority_queue不如对vector排序

int main(){
    unordered_map<string, vector<int>> stu_course_map;

    int N, K;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int c, M;
        cin >> c >> M;
        for(int j = 0; j < M; j++){
            string name;
            cin >> name;
            if(stu_course_map.count(name) == 0){
                vector<int> *v = new vector<int>();
                v->push_back(c);
                stu_course_map[name] = *v;
            } else {
                stu_course_map[name].push_back(c);
            }
        }
    }

    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        cout << name;
        if(stu_course_map.count(name) == 0){
            cout << " 0" << endl;
        } else {
            vector<int> course = stu_course_map[name];
            cout << " " << course.size();
            sort(course.begin(), course.end());
            for(int j = 0; j < course.size(); j++){
                cout << " " << course[j];
            }
            cout << endl;
        }
    }
}
