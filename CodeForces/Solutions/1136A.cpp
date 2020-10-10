#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <ll, ll>

vector <pii> vv;

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        vv.push_back( make_pair(u, v));
    }

    ll cnt = n;
    ll un;
    cin >> un;
    for(ll i = 0; i < vv.size(); i++) {
        if(vv[i].first <= un && un <= vv[i].second)
            break;

        //cout << vv[i].first << "  " << un << endl;

        cnt--;
    }

    cout << cnt << endl;

    return 0;
}