// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 4e5 + 10;
ll day[sz], n, x, tot, cs[sz], cval[sz];

inline ll gsum(ll n) {
    return (n*(n+1)) / 2;
}

ll solve(ll m, ll d)
{
    ll res = 0, tx = x;
    ll mn = min(tx, day[m]-d+1);
    res = gsum(d+mn-1) - gsum(d-1);

    tx -= mn;
    if(tx == 0)
        return res;

    ll now = m+1, lo = m+1, hi = tot, nxt = -1;
    while(lo <= hi) {
        ll mid = (lo+hi) / 2;
        ll v = cs[mid] - cs[m];

        if(v <= tx) {
            nxt = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    //cout << cs[6] << endl;

    if(nxt != -1) {
        ll ase = cs[nxt] - cs[m];
        res += cval[nxt] - cval[m];
        tx -= ase;
    }
    res += gsum(tx);

    return res;
}

int main()
{
    cin >> n >> x;
    tot = 2*n;
    for1(i, n) sl(day[i]);

    for(ll i = n+1; i <= tot; i++) day[i] = day[i-n];

    for1(i, tot) {
        cs[i] = cs[i-1] + day[i];
        cval[i] = cval[i-1] + gsum(day[i]);
    }

    ll ans = 1;
    //cout << solve(3,3) << endl;
    for1(i, n) {
        ll lo = 1, hi = day[i];
        ans = max(ans, solve(i, 1));

        while(lo < hi) {
            ll mid = (lo+hi) >> 1;

            ll got1 = solve(i, mid), got2 = solve(i, mid+1);

            if(got1 > got2) {
                ans = max(ans, got1);
                hi = mid;
            }
            else {
                ans = max(ans, got2);
                //if(ans == 18) cout << i << " " << mid+1 << endl;
                lo = mid+1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}