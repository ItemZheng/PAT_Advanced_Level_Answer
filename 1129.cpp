#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 无坑。只要维护一个K个数字的vector即可

class Item{
public:
    int id = 0, visit_time = 0;
};

bool cmp(Item *i1, Item *i2){
    if(i1->visit_time != i2->visit_time){
        return i1->visit_time > i2->visit_time;
    }
    return i1->id < i2->id;
}

int main(){
    int N, K;
    cin >> N >> K;
    Item all_item[N];
    for(int i = 0; i < N; i++){
        all_item[i].id = i;
    }

    vector<Item *> topK;
    for(int i = 0; i < N; i++){
        int q;
        cin >> q;
        if(i == 0){
            all_item[q-1].visit_time++;
            topK.push_back(&all_item[q-1]);
        } else {
            bool contain = false;
            cout << q << ": ";
            for(int j = 0; j < topK.size(); j++){
                if(j > 0){
                    cout << " ";
                }
                cout << topK[j]->id + 1;
                if(topK[j]->id == q - 1){
                    contain = true;
                }
            }
            cout << endl;

            all_item[q-1].visit_time++;
            if(!contain){
                topK.push_back(&all_item[q-1]);
            }
            sort(topK.begin(), topK.end(), cmp);
            while(topK.size() > K){
                topK.pop_back();
            }
        }
    }
}