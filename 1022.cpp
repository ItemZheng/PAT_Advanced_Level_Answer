#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// 直接用map存，写两个公用函数

using namespace std;

void map_add_vector(string key, string value, map<string, vector<string>> &book_map){
    if(book_map.count(key) > 0){
        book_map[key].push_back(value);
    } else {
        vector<string> *values = new vector<string>();
        values->push_back(value);
        book_map[key] = *values;
    }
}

void output(string key, map<string, vector<string>> &book_map){
    if(book_map.count(key) == 0){
        cout << "Not Found" << endl;
        return;
    }
    vector<string> ids = book_map[key];
    sort(ids.begin(), ids.end());
    for(int i = 0; i < ids.size(); i++){
        cout << ids[i] << endl;
    }
}

int main(){
    map<string, vector<string>> title_id_map, author_id_map, keyword_id_map, publisher_id_map, year_id_map;
    int N;
    cin >> N;
    string nothing;
    getline(cin, nothing);
    for(int i = 0; i < N; i++){
        // read in
        string id, title, author, keyword, publisher, year;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyword);
        getline(cin, publisher);
        getline(cin, year);
        // add
        map_add_vector(title, id, title_id_map);
        map_add_vector(author, id, author_id_map);
        map_add_vector(publisher, id, publisher_id_map);
        map_add_vector(year, id, year_id_map);
        // add key words
        int idx = 0;
        while((idx = keyword.find(' ')) != string::npos){
            string sub_keyword = keyword.substr(0, idx);
            map_add_vector(sub_keyword, id, keyword_id_map);
            keyword = keyword.substr(idx + 1);
        }
        map_add_vector(keyword, id, keyword_id_map);
    }

    int M;
    cin >> M;
    getline(cin, nothing);
    for(int i = 0; i < M; i++){
        string query;
        getline(cin, query);
        cout << query << endl;

        string key = query.substr(3);
        char type = query[0];
        switch (type){
            case '1':
                output(key, title_id_map);
                break;
            case '2':
                output(key, author_id_map);
                break;
            case '3':
                output(key, keyword_id_map);
                break;
            case '4':
                output(key, publisher_id_map);
                break;
            case '5':
                output(key, year_id_map);
                break;
        }
    }
}