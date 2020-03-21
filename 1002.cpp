#include <iostream>
#include <vector>

using namespace std;

// 注意点：
//      1、 精确到0.1
//      2、 系数为 0 不输出
//      3、 注意负数直接用%.1f输出
//      4、 更好的办法是数组

class Item{
public:
    int exp;
    float a;
public:
    Item(int exp, float a){
        this->exp = exp;
        this->a = a;
    }
};

int main(){
    // define a, b
    vector<Item*> a, b, res;

    // read in
    int len, exp;
    float fab;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        cin >> exp >> fab;
        Item * item = new Item(exp, fab);
        a.push_back(item);
    }
    cin >> len;
    for (int i = 0; i < len; ++i) {
        cin >> exp >> fab;
        Item * item = new Item(exp, fab);
        b.push_back(item);
    }

    // add
    int ai = 0, bi = 0;
    while (ai < a.size() && bi < b.size()){
        Item *item_a = a[ai], *item_b = b[bi];
        int res_exp;
        float  res_fab;
        if(item_a->exp < item_b->exp){
            res_exp = item_b->exp;
            res_fab = item_b->a;
            bi++;
        } else if(item_a->exp > item_b->exp){
            res_exp = item_a->exp;
            res_fab = item_a->a;
            ai++;
        } else {
            res_exp = item_a->exp;
            res_fab = item_a->a + item_b->a;
            ai++;
            bi++;
        }
        Item *res_item = new Item(res_exp, res_fab);
        if(res_fab != 0)
            res.push_back(res_item);
    }

    // if a
    if(bi < b.size()){
        ai = bi;
        a = b;
    }
    while (ai < a.size()){
        if(a[ai]->a != 0)
            res.push_back(a[ai]);
        ai++;
    }

    // print
    cout << res.size();
    for(int i = 0; i < res.size(); i++){
        printf(" %d %.1f", res[i]->exp, res[i]->a);
//        int x = int(res[i]->a * 10);
//        cout << " " << res[i]->exp << " " << x / 10 << "." << x % 10;
    }
    return 0;
}