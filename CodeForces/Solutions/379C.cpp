#include <bits/stdc++.h>
using namespace std;

#define ll long long

class node {
private:
    ll a;
    ll indx;
public:
    node(ll a, ll i) {
        this -> a = a;
        indx = i;
    }
    node() {}
    ll geta();
    ll getIndex();
    node operator =(node ob) {
        a = ob.a;
        indx = ob.indx;
    }
};

ll node :: geta()

{
    return a;
}

ll node :: getIndex()

{
    return indx;
}

bool cmp(node ob1, node ob2)

{
    return ob1.geta() < ob2.geta();
}

int main()

{
    ll n;
    cin >> n;
    node ara[n + 5];
    ll result[n + 5];
    for(ll i = 0; i < n; i++) {
        ll rating;
        cin >> rating;
        ara[i] = node(rating, i);
    }

    map <ll, bool> mark;
    sort(ara, ara + n, cmp);

    ll val = 0;
    for(int i = 0; i < n; i++) {
        ll tmp = ara[i].geta();
        if(mark[tmp] == 0) {
            result[ ara[i].getIndex() ] = tmp;
            mark[tmp] = 1;
            val = tmp + 1;
        }
        else {
            result[ ara[i].getIndex() ] = val;
            mark[val] = 1;
            val++;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i];
        if(i != n - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}