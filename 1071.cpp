#include <iostream>
#include <string>
#include <unordered_map>

// 无坑，但是不能全文使用string，需要用char *，而且全文只用一个char数组存储

using namespace std;

bool valid(char a){
    if(a >= '0' && a <= '9')
        return true;
    if(a >= 'a' && a <= 'z')
        return true;
    return a >= 'A' && a <= 'Z';
}

int main(){
    char *speech = new char[1048577];
    cin.getline(speech, 1048577);

    int begin = 0;
    while(!valid(speech[begin])){
        begin++;
    }
    speech = speech + begin;

    unordered_map<string, int> word_map;
    while(true){
        int idx = 0;
        while(valid(speech[idx]) && speech[idx] != '\0'){
            if(speech[idx] >= 'A' && speech[idx] <= 'Z'){
                speech[idx] = (char)(speech[idx] - 'A' + 'a');
            }
            idx++;
        }
        string word = string(speech, idx);
        if(word_map.count(word) > 0){
            word_map[word]++;
        } else {
            word_map[word] = 1;
        }
        while(!valid(speech[idx]) && speech[idx] != '\0'){
            idx++;
        }
        if(speech[idx] == '\0'){
            break;
        } else {
            speech = speech + idx;
        }
    }

    int max = 0;
    string max_string = "";
    for(unordered_map<string, int>::iterator it = word_map.begin(); it != word_map.end(); it++){
        if(it->second > max){
            max = it->second;
            max_string = it->first;
        } else if(it->second == max){
            if(max_string > it->first){
                max_string = it->first;
            }
        }
    }
    cout << max_string << " " << max << endl;
}