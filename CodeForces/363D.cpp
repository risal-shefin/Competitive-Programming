#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <ll, ll>
ll n, m, a;
ll poc[100009], bike[100009];
bool check(ll bn)
{
    ll ase = a;
    for(ll i = 1, j = bn; i <= bn; i++, j--) {
        ll dibo = min(bike[j], poc[i]);
        ll need = bike[j] - dibo;
        if(ase >= need)
            ase -= need;
        else
            return 0;
    }
    return 1;
}
int main()
{
    cin >> n >> m >> a;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &poc[i]);
    for(ll i = 1; i <= m; i++)
        scanf("%lld", &bike[i]);
    sort(poc + 1, poc + n + 1, greater <ll> ());
    sort(bike + 1, bike + m + 1);
    ll lo = 0, hi = min(m, n), r = 0, s = 0, ret;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            r = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    ll sum = 0;
    for(ll i = 1; i <= r; i++)
        sum += bike[i];
    s = sum - a;
    cout << r << " " << max(s, 0LL) << endl;
    return 0;
}
