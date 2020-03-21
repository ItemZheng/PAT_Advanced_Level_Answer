#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  思路1：首先读取学生，将学生按照姓名排序（排一次），然后遍历一遍学生，加到各个课程下（需要将cout, cin => printf,scanf）
//  思路2：根据学生的姓名，开hash数组，无需排序，然后遍历一边学生，加到课程下（需要将cout, cin => printf,scanf）

class Student {
public:
    string name;
    vector<int> course;

public:
    int hash(){
        return (name[0] - 'A') * 26 * 26 * 26 +  (name[1] - 'A') * 26 * 26 + (name[2] - 'A') * 26 + name[3] - '0';
    }
};

bool compare(Student &s1, Student &s2){
    return s1.name < s2.name;
}

int main() {
    // student vector
    int N, K;
    scanf("%d%d", &N, &K);

    vector<Student> students;
    for (int i = 0; i < N; i++) {
        Student *student = new Student();
        char n[5];
        scanf("%s", n);
        student->name = string(n);
        // cin >> student->name;

        int count;
        scanf("%d", &count);
        for (int j = 0; j < count; j++) {
            int c;
            scanf("%d", &c);
            student->course.push_back(c - 1);
        }
        students.push_back(*student);
    }

    // sort by person
    sort(students.begin(), students.end(), compare);

    vector<string> course_map[K];
    for (int i = 0; i < students.size(); i++) {
        string name = students[i].name;
        for (int j = 0; j < students[i].course.size(); j++) {
            int c = students[i].course[j];
            course_map[c].push_back(name);
        }
    }

    for (int i = 0; i < K; i++) {
        printf("%d %ld\n", i + 1, course_map[i].size());
        vector<string> course_v = course_map[i];
        for (int j = 0; j < course_v.size(); j++) {
            // cout << course_v[j] << endl;
            printf("%s\n", course_v[j].c_str());
        }
    }
}
