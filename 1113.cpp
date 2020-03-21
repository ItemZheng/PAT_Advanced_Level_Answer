#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int n1 = N / 2, n2 = N - N / 2;

    vector<int> numbers;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(i < n1){
            sum = sum + numbers[i];
        } else {
            sum = sum - numbers[i];
        }
    }

    cout << abs(n1 - n2) << " " << abs(sum) << endl;
}