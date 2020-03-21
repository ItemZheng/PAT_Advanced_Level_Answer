#include <iostream>

using namespace std;

// 注意点，看清楚题目，输出的是数组的值，不是下标
// 如果全是负数，最大和是0，输出数组的首尾数字
// 同时也要注意 如果数字中出现零，其他都是负数的情况

int main(){
    int N;
    cin >> N;
    bool all_neg = true;

    int nums[N], max_sum = 0, sum = 0, max_begin = 0, max_len = N, begin = 0, len = 0;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
        sum = sum + nums[i];
        len++;
        if(nums[i] >= 0){
            if(all_neg){
                max_begin = i;
                max_len = 1;
            }
            all_neg = false;
        }

        if(sum > max_sum){
            max_begin = begin;
            max_len = len;
            max_sum = sum;
        }

        if(sum < 0){
            sum = 0;
            begin = i + 1;
            len = 0;
        }
    }

    cout << max_sum << " " << nums[max_begin] << " " << nums[max_begin + max_len - 1];

    return 0;
}