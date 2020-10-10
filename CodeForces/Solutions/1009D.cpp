#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct node {
    ll u, v;
    node(ll _u, ll _v) {
        u = _u;
        v = _v;
    }
};

vector <node> v;

int main()

{

    ll n, m;
    cin >> n >> m;

    if(m < n - 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    for(ll i = 2; i <= n; i++)
        v.pb( node(1, i) );

    ll cnt = n - 1, num = 2;
    while(cnt < m && num <= n) {

        for(ll i = num + 1; i <= n; i++) {
            if(__gcd(num, i) == 1) {
                v.pb( node(num, i) );
                cnt++;

                if(cnt == m)
                    break;
            }
        }

        num++;
    }

    if(v.size() < m)
        cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        for(ll i = 0; i <  v.size(); i++) {
            printf("%lld %lld\n", v[i].u, v[i].v);
        }
    }

    return 0;
}