#include <string>
#include <iostream>

using namespace std;

string spells[10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void output(int num){
    if(num < 10){
        cout << spells[num];
    } else {
        output(num / 10);
        cout << " " << spells[num % 10];
    }
}

int main(){
    string number;
    cin >> number;
    int sum = 0;

    for(int i = 0; i < number.size(); i++){
        sum = sum + number[i] - '0';
    }

    if(sum == 0){
        cout << "zero";
    } else {
        output(sum);
    }
}