#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 无坑。注意输出，数字为0或者1都需要注意输出

int main(){
    int N;
    cin >> N;
    double sum = 0.0;
    int count = 0;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        bool valid = true;
        string num_s = s;
        if(num_s[0] == '-'){
            num_s = num_s.substr(1);
        }
        int idx = num_s.find('.');
        if(idx == string::npos){
            for(int j = 0; j < num_s.size(); j++){
                if(num_s[j] < '0' || num_s[j] > '9'){
                    valid = false;
                    break;
                }
            }
        } else{
            string in_s = num_s.substr(0, idx);
            string de_s = num_s.substr(idx + 1);
            if(de_s.size() > 2){
                valid = false;
            } else {
                for(int j = 0; j < in_s.size(); j++){
                    if(in_s[j] < '0' || in_s[j] > '9'){
                        valid = false;
                        break;
                    }
                }
                for(int j = 0; j < de_s.size(); j++){
                    if(de_s[j] < '0' || de_s[j] > '9'){
                        valid = false;
                        break;
                    }
                }
            }
        }
        if(valid){
            double value = stod(s);
            if(value < -1000 || value > 1000){
                valid = false;
            }
        }
        if(valid){
            count += 1;
            sum += stod(s);
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }

    if(count == 0){
        cout << "The average of 0 numbers is Undefined" << endl;
    } else if(count == 1){
        cout << "The average of 1 number is " << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
    } else {
        cout << "The average of " << count << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << sum / count << endl;
    }
}