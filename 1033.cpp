#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

// 注意点：注意第一个加油站的位置必须是0，否则寸步难行（测试点二）
//      思路：在当前加油站找下一个比自己油价低的加油站，如果找到了，那就把油加到去那个加油站的位置；
//      如果找不到，那就在当前位置加满（注意边界）

using namespace std;

class Station{
public:
    double price;
    int distance;
public:
    Station(double p, int d){
        price = p;
        distance = d;
    }
};

bool compare(Station s1, Station s2){
    return s1.distance < s2.distance;
}

int main(){
    int c_max, d, d_avg, n;
    cin >> c_max >> d >> d_avg >> n;

    vector<Station> stations;
    for(int i = 0; i < n; i++){
        double p;
        int dis;
        cin >> p >> dis;
        Station * s = new Station(p, dis);
        stations.push_back(*s);
    }

    int max_dis = c_max * d_avg;
    sort(stations.begin(), stations.end(), compare);
    // judge
    if(stations[0].distance != 0){
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    for(int i = 0; i < n; i++){
        int next_dis;
        if(i == n - 1){
            next_dis = d;
        } else {
            next_dis = stations[i+1].distance;
        }
        if(next_dis - stations[i].distance > max_dis){
            cout << "The maximum travel distance = ";
            cout << setiosflags(ios::fixed) << setprecision(2) << (stations[i].distance + max_dis) * 1.0 << endl;
            return 0;
        }
    }

    // Go to hangzhou
    int cur_station = 0;
    double rest_c = 0, price = 0;
    while (cur_station < n){
        // find target
        int next_station = -1;
        for(int i = cur_station + 1; i < n; i++){
            if(stations[i].price < stations[cur_station].price &&
            stations[i].distance <= stations[cur_station].distance + max_dis){
                next_station = i;
                break;
            }
            if(stations[i].distance > stations[cur_station].distance + max_dis){
                break;
            }
        }

        // calculate target distance
        int next_distance = 0;
        if(next_station == -1){
            next_distance = max_dis;
            if(stations[cur_station].distance + next_distance > d){
                next_distance = d - stations[cur_station].distance;
            }
        } else {
            next_distance = stations[next_station].distance - stations[cur_station].distance;
        }

        // fill or not fill
        if(rest_c * d_avg < next_distance){
            price += stations[cur_station].price * (next_distance / (d_avg * 1.0) - rest_c);
            rest_c = next_distance / (d_avg * 1.0);
        }
        // if end
        if(next_distance + stations[cur_station].distance == d){
            break;
        }
        rest_c -= (stations[cur_station + 1].distance - stations[cur_station].distance) / (d_avg * 1.0);
        cur_station++;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << price << endl;
}