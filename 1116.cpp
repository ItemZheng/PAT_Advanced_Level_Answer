#include <iostream>
#include <unordered_map>
#include <cmath>

// 无坑。存的时候就确定好奖项

using namespace std;

class Student{
public:
    bool checked = false;
    int rank = 1, price = 1;
};

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    unordered_map<string, Student *> id_info_map;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string id;
        cin >> id;
        Student *s = new Student();
        s->rank = i + 1;
        if(s->rank == 1){
            s->price = 0;
        } else if(isPrime(s->rank)){
            s->price = 1;
        } else {
            s->price = 2;
        }
        id_info_map[id] = s;
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        string id;
        cin >> id;
        cout << id << ": ";
        if(id_info_map.count(id) == 0){
            cout << "Are you kidding?" << endl;
        } else {
            Student *s = id_info_map[id];
            if(s->checked){
                cout << "Checked" << endl;
            } else {
                if(s->price == 0){
                    cout << "Mystery Award" << endl;
                } else if(s->price == 1){
                    cout << "Minion" << endl;
                } else {
                    cout << "Chocolate" << endl;
                }
                s->checked = true;
            }
        }
    }
}