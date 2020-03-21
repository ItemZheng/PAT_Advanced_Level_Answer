#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 无坑。注意读题即可。
// 遇到这一类统计最短路径条数的，都先直接存储所有最短路径，最后再递归选择最优

// city name handle
unordered_map<string, int> name_map;

int getCityId(string name){
    return name_map[name];
}

// get best path
int path_count = 0, max_happiness = 0, path_size = 0;
vector<int> max_path, temp_path;

// road
class Road{
public:
    int id, cost;
public:
    Road(int i, int c){
        id = i;
        cost = c;
    }
};

// city
class City{
public:
    // information
    string name;
    vector<Road> Routes;
    int happy;

    // visit
    int costs = -1;
    vector<int> path;
    bool visited = false;
public:
    City(string n, int h){
        name = n;
        happy = h;
    }

    void add_road(int anotherId, int cost){
        Road * r = new Road(anotherId, cost);
        Routes.push_back(*r);
    }

    void update(vector<City> &cities){
        for(int i = 0; i < Routes.size(); i++){
            int neigh = Routes[i].id;
            if(!cities[neigh].visited){
                if(cities[neigh].costs == -1 || cities[neigh].costs >= costs + Routes[i].cost){
                    if(cities[neigh].costs != costs + Routes[i].cost){
                        cities[neigh].path.clear();
                    }
                    cities[neigh].path.push_back(getCityId(name));
                    cities[neigh].costs = costs + Routes[i].cost;
                }
            }
        }
    }

    void choose_best_path(vector<City> &cities, int path_happiness, int size){
        int cur_id = getCityId(name);
        temp_path.push_back(cur_id);
        if(path.empty()){
            // begin
            path_count++;
            if(path_happiness > max_happiness || (path_happiness == max_happiness && size < path_size)){
                max_path.clear();
                max_path = temp_path;
                path_size = size;
                max_happiness = path_happiness;
            }
        } else {
            for(int i = 0; i < path.size(); i++){
                int neigh = path[i];
                cities[neigh].choose_best_path(cities, path_happiness + happy, size + 1);
            }
        }
        temp_path.pop_back();
    }
};

int main(){
    vector<City> cities;
    // read cities
    int N, K;
    string begin_city;
    cin >> N >> K >> begin_city;
    City begin(begin_city, 0);
    cities.push_back(begin);
    name_map[begin_city] = 0;
    for(int i = 1; i < N; i++){
        string name;
        int happy;
        cin >> name >> happy;
        City * c = new City(name, happy);
        cities.push_back(*c);
        name_map[name] = i;
    }

    // read routes
    for(int i = 0; i < K; i++){
        string n1, n2;
        int cost;
        cin >> n1 >> n2 >> cost;
        int c1 = getCityId(n1), c2 = getCityId(n2);
        cities[c1].add_road(c2, cost);
        cities[c2].add_road(c1, cost);
    }

    // begin find min path
    int cur_id = 0;
    cities[cur_id].costs = 0;
    while(cur_id != getCityId("ROM")){
        cities[cur_id].visited = true;
        cities[cur_id].update(cities);

        int next_id = -1;
        for(int i = 0; i < N; i++){
            if(!cities[i].visited && cities[i].costs > 0){
                if(next_id == -1 || cities[i].costs < cities[next_id].costs){
                    next_id = i;
                }
            }
        }
        cur_id = next_id;
        if(next_id == -1){
            break;
        }
    }

    int target = getCityId("ROM");
    cities[target].choose_best_path(cities, 0, 0);
    cout << path_count << " " << cities[target].costs << " " << max_happiness << " " << max_happiness / path_size << endl;
    for(int i = 0; i < max_path.size(); i++){
        if(i != 0){
            cout << "->";
        }
        cout << cities[max_path[max_path.size() - i - 1]].name;
    }
}