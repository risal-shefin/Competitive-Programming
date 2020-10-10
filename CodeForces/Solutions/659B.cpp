#include <bits/stdc++.h>

using namespace std;

struct data {
    string name;
    int reg;
    int num;
};
bool compare(data a, data b)

{
    if(a.reg == b.reg) {
        return a.num > b.num;
    }
    else {
        return a.reg < b.reg;
    }
}
int main()

{
    int n, m;
    cin >> n >> m;
    vector <data> v;
    data temp;
    while(n--) {
        cin >> temp.name >> temp.reg >> temp.num;
        v.push_back(temp);
    }
    stable_sort(v.begin(), v.end(), compare);

    int regc, count = 1, i;
    regc = v[0].reg;
    for(i = 1; i < v.size(); i++) {
        if(v[i].reg != regc) {
            regc = v[i].reg;
            count = 0;
        }
        count++;
        if(count == 2) {
            if(i < v.size() - 1 && v[i].num == v[i + 1].num && v[i].reg == v[i + 1].reg) {
                cout << "?\n";
            }
            else {
                cout << v[i - 1].name << " " << v[i].name << endl;
            }
        }
    }

    return 0;
}