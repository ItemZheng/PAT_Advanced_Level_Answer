#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 无坑，注意题目描述即可

string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
    int day = -1, hour = -1;
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    // get day
    int day_idx = -1;
    for(int i = 0; i < s1.size() && i < s2.size(); i++){
        if(s1[i] == s2[i]){
            char c = s1[i];
            if(c >= 'A' && c <= 'G'){
                day_idx = i;
                day = c - 'A';
                break;
            }
        }
    }

    // get hour
    for(int i = day_idx + 1; i < s1.size() && i < s2.size(); i++){
        if(s1[i] == s2[i]){
            char c = s1[i];
            if(c >= '0' && c <= '9'){
                hour = c - '0';
                break;
            } else if(c >= 'A' && c <= 'N'){
                hour = c - 'A' + 10;
                break;
            }
        }
    }

    // get minute
    int minute = 0;
    for(int i = 0; i < s3.size() && i < s4.size(); i++){
        if(s3[i] == s4[i]){
            char c = s3[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                minute = i;
            }
        }
    }

    cout << weekday[day] << " " << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute;
}