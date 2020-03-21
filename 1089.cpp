#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 无坑，多用stl，速度会快很多。
// 1、判断Insertion，只要判断前面是否有序，后面是否一致 (用insert 和 erase 可以更加方便完成下一个迭代)
// 2、判断Merge，需要模拟，但是可以用sort函数直接排序，不用自己实现merge sort

vector<int> original, partial;
bool output = false;

void output_array(bool ori){
    vector<int> *arr = &partial;
    if(ori){
        arr = &original;
    }
    for(int i = 0; i < arr->size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << (*arr)[i];
    }
    cout << endl;
}

bool judgeInsertion(){
    int idx = 1;
    while(idx < original.size() && partial[idx] >= partial[idx - 1]){
        idx++;
    }
    for(int i = idx; i < original.size(); i++){
        if(original[i] != partial[i]){
            return false;
        }
    }

    int pos = 0;
    while(pos < partial.size() && partial[pos] < partial[idx]){
        pos++;
    }
    int key = partial[idx];
    partial.erase(partial.begin() + idx);
    partial.insert(partial.begin() + pos, key);

    cout << "Insertion Sort" << endl;
    output_array(false);
    return true;
}

bool is_same_array(){
    for(int i = 0; i < original.size(); i++){
        if(original[i] != partial[i]){
            return false;
        }
    }
    return true;
}

void merge_sort(){
    int size = 2;
    while(size <= original.size()){
        for(int i = 0; i * size < original.size(); i++){
            int end = (i + 1) * size - 1;
            if(end >= original.size()){
                end = original.size() - 1;
            }
            sort(original.begin() + i * size, original.begin() + end + 1);
        }
        if(output){
            output_array(true);
            return;
        }
        if(is_same_array()){
            output = true;
        }
        size = size * 2;
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        original.push_back(num);
    }
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        partial.push_back(num);
    }
    if(!judgeInsertion()){
        cout << "Merge Sort" << endl;
        merge_sort();
    }
}