#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string LABELS = "WTL";
    float max_profit = -10000;
    string max_case = "WWW";

    float Odd_Table[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> Odd_Table[i][j];
        }
    }

    // Test All Case
    for(int i = 0; i < 3; i++){
        // First Game Case
        for(int j = 0; j < 3; j++){
            // Second Game Case
            for(int k = 0; k < 3; k++){
                // Third Game Case
                float p = (Odd_Table[0][i] * Odd_Table[1][j] * Odd_Table[2][k] * 0.65 - 1) * 2;
                if(p > max_profit){
                    max_profit = p;
                    max_case[0] = LABELS[i];
                    max_case[1] = LABELS[j];
                    max_case[2] = LABELS[k];
                }
            }
        }
    }

    cout << max_case[0] << " " << max_case[1] << " " << max_case[2] << " ";
    cout << setiosflags(ios::fixed) << setprecision(2) << max_profit;

}