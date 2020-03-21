#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 注意排序的元素可能有相等的。

void output(vector<int> seq){
    if(seq.empty()){
        return;
    }
    for(int i = 0; i < seq.size(); i++){
        if( i > 0){
            cout << " ";
        }
        cout << seq[i];
    }
}

bool judge_insertion(vector<int> &origin_seq,  vector<int> &part_seq){
    int idx = 0;
    while( idx < part_seq.size() - 1 && part_seq[idx] <= part_seq[idx + 1] ){
        idx++;
    }
    for(int i = idx + 1; i < part_seq.size(); i++){
        if(origin_seq[i] != part_seq[i]){
            return false;
        }
    }
    cout << "Insertion Sort" << endl;
    if(idx < part_seq.size() - 1)
        sort(part_seq.begin(), part_seq.begin() + idx + 2);
    output(part_seq);
    return true;
}

int main(){
    vector<int> origin_seq, part_seq;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        origin_seq.push_back(num);
    }
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        part_seq.push_back(num);
    }

    if(!judge_insertion(origin_seq, part_seq)){
        cout << "Heap Sort" << endl;
        int max_top = part_seq[0], heap_size = N;
        for(int i = 1; i < N; i++){
            if(part_seq[i] > max_top){
                heap_size = i;
                break;
            }
        }

        // swap
        if(heap_size > 1){
            part_seq[0] = part_seq[--heap_size];
            part_seq[heap_size] = max_top;

            int node = 0;
            while(true){
                int child = 2 * node + 1;
                if(child >= heap_size){
                    break;
                }
                if(child < heap_size - 1 && part_seq[child] < part_seq[child + 1]){
                    child ++; // right child
                }
                if(part_seq[child] <= part_seq[node]){
                    break;
                }
                int temp = part_seq[node];
                part_seq[node] = part_seq[child];
                part_seq[child] = temp;
                node = child;
            }
        }
        output(part_seq);
    }
}