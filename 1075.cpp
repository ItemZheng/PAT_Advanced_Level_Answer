#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

int *full_marks = nullptr;

class User{
public:
    int *scores;
    int total_score = 0;
    int prefect_count = 0, course_size = 0;
    int userId;
    bool display = false;
public:
    User(int id, int k){
        scores = new int[k];
        memset(scores, -1, sizeof(int) * k);
        course_size = k;
        userId = id;
    }

    void update_score(int course_id, int score){
        if(score > scores[course_id]){
            // 可以编译通过
            display = true;
            scores[course_id] = score;
            if(score == full_marks[course_id]){
                prefect_count++;
            }
        } else if(score == -1){
            // 提交了，但是没有编译通过，但是需要输出0
            if(scores[course_id] == -1){
                scores[course_id] = 0;
            }
        }
    }

    void calculate_score(){
        total_score = 0;
        for(int i = 0; i < course_size; i++){
            if(scores[i] == -1){
                continue;
            }
            total_score += scores[i];
        }
    }

    void output(){
        cout << setfill('0') << setw(5) << userId << " ";
        cout << total_score;
        for(int i = 0; i < course_size; i++){
            if(scores[i] == -1){
                cout << " -";
            } else {
                cout << " " << scores[i];
            }
        }
        cout << endl;
    }
};

bool cmp(User *u1, User *u2){
    if(u1->total_score != u2->total_score){
        return u1->total_score > u2->total_score;
    } else if(u1->prefect_count != u2->prefect_count){
        return u1->prefect_count > u2->prefect_count;
    } else {
        return u1->userId < u2->userId;
    }
}

int main(){
    int N, K, M;
    cin >> N >> K >> M;

    User *users[N];
    for(int i = 0; i < N; i++){
        users[i] = new User(i + 1, K);
    }
    full_marks = new int[K];
    for(int i = 0; i < K; i++){
        cin >> full_marks[i];
    }

    for(int i = 0; i < M; i++){
        int id, pro_id, score;
        cin >> id >> pro_id >> score;
        users[id-1]->update_score(pro_id - 1, score);
    }

    for(int i = 0; i < N; i++){
        users[i]->calculate_score();
    }

    sort(users, users + N, cmp);

    int rank = 1, cur_score = users[0]->total_score;
    for(int i = 0; i < N; i++){
        if(!users[i]->display){
            break;
        }
        if(users[i]->total_score < cur_score){
            rank = i + 1;
            cur_score = users[i]->total_score;
        }
        cout << rank << " ";
        users[i]->output();
    }
}