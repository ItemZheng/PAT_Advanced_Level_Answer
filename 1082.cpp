#include <iostream>

using namespace std;

//  无坑。 注意边界的零就好
//  思路： 1、以四位为一个单元分别处理
//        2、注意处理四位的时候需要传入前面的数字

string numbers[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string positions[4] = {"", "Shi", "Bai", "Qian"};
bool first = true;

// 处理四位数字
void handle(int prefix, int number){
    if(number == 0){
        return;
    }
    bool zero = true;
    if(prefix != 0){
        zero = false;
    }
    for(int exp = 1000, i = 3; exp >= 1; exp = exp / 10, i--){
        if(number / exp % 10){
            if(zero) {
                zero = false;
            }
            if(first){
                first = false;
            } else {
                cout << " ";
            }
            cout << numbers[number / exp % 10];
            if(i != 0)
                cout << " " << positions[i];
        } else {
            if(!zero){
                if(number % exp == 0){
                    break;
                }
                zero = true;
                cout << " ling";
            }
        }
    }
}

int main(){
    int number;
    cin >> number;
    if(number < 0){
        cout << "Fu";
        number = -number;
        first = false;
    }
    if(number == 0){
        cout << "ling";
        return 0;
    }
    int p1 = number / 100000000 % 10000, p2 = number / 10000 % 10000, p3 = number % 10000;
    handle(0, p1);
    if(p1 != 0){
        cout << " Yi";
    }
    handle(p1, p2);
    if(p2 != 0){
        cout << " Wan";
    }
    handle(number / 10000, p3);
}