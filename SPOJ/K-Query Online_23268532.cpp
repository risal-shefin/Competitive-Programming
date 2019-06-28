#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define block 720
vector <ll> v[block];
ll ara[100009];
ll query(ll l, ll r, ll c)
 {
    ll lb = l / block, rb = r / block;
     ll cnt = 0;
    if(lb == rb) {
        for(ll i = l; i <= r; i++)
            if(ara[i] > c)
                cnt++;
         return cnt;
    }
     for(ll i = l; i < (lb + 1) * block; i++)
        if(ara[i] > c)
            cnt++;
    for(ll i = rb * block; i <= r; i++)
        if(ara[i] > c)
            cnt++;
     for(ll i = lb + 1; i < rb; i++) {
        ll pos = upper_bound(v[i].begin(), v[i].end(), c) - v[i].begin();
        cnt += (v[i].size() - pos);
    }
     return cnt;
}
int main()
 {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);
        v[i / block].push_back(in);
        ara[i] = in;
    }
    for(ll i = 0; i < block; i++)
        sort(v[i].begin(), v[i].end());
     ll q, lastans = 0;
    cin >> q;
    while(q--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a ^= lastans, b ^= lastans, c^= lastans;
        if(a < 1) a = 1; if(b > n) b = n;
        printf("%lld\n", lastans = a > b? 0: query(a - 1, b - 1, c));
    }
     return 0;
}
