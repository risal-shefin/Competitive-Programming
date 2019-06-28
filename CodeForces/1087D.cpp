#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[100009];
int main()
{
    ll n, s;
    cin >> n >> s;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        cnt[u]++, cnt[v]++;
    }
    ll leaf = 0;
    for(ll i = 1; i <= n; i++) {
        if(cnt[i] == 1)
            leaf++;
    }
    cout << setprecision(9) << fixed << (s / (leaf * 1.0)) * 2.0 << endl;
    return 0;
}
