#include <iostream>

using namespace std;

// 无坑。

int char_to_int(int ch){
    if(ch >= '0' && ch <= '9'){
        return ch - '0';
    }
    if(ch >= 'a' && ch <= 'z'){
        return ch - 'a' + 10;
    }
    return ch - 'A' + 36;
}

int main(){
    int colors[100] = {0};
    for(int i = 0; i < 100; i++){
        colors[i] = 0;
    }

    string color_str;
    cin >> color_str;
    for(int i = 0; i < color_str.size(); i++){
        int c = char_to_int(color_str[i]);
        colors[c]++;
    }

    string need_color;
    cin >> need_color;
    bool can = true;
    for(int i = 0; i < need_color.size(); i++){
        int c = char_to_int(need_color[i]);
        colors[c]--;
        if(colors[c] < 0){
            can = false;
        }
    }
    if(can){
        cout << "Yes " << color_str.size() - need_color.size() << endl;
    } else {
        int need_count = 0;
        for(int i = 0; i < 100; i++){
            if(colors[i] < 0){
                need_count =need_count + (-colors[i]);
            }
        }
        cout << "No " << need_count << endl;
    }
}