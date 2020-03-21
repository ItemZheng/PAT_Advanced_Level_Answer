#include <iostream>

using namespace std;

// 无坑

int main(){
    string f_name, f_id, m_name, m_id;
    int f_score = -1, m_score = 101;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string name, id;
        int score;
        char sex;
        cin >> name >> sex >> id >> score;
        if(sex == 'M'){
            if(score < m_score){
                m_score = score;
                m_name = name;
                m_id = id;
            }
        } else {
            if(score > f_score){
                f_score = score;
                f_name = name;
                f_id = id;
            }
        }
    }
    if(f_score != -1){
        cout << f_name << " " << f_id << endl;
    } else {
        cout << "Absent" << endl;
    }
    if(m_score != 101){
        cout << m_name << " " << m_id << endl;
    } else{
        cout << "Absent" << endl;
    }
    if(f_score != -1 && m_score != 101){
        cout << f_score - m_score << endl;
    } else {
        cout << "NA" << endl;
    }
}