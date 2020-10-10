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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll mod = 1000000007;
ll ara[100009], pw[40];
set <ll> lst;

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

map <ll, ll> cnt;

int main()

{
    ll n, p;
    sl(n), sl(p);
    forn(i, n)
        sl(ara[i]);

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    pw[0] = 1;
    ll idp = 0;
    for(ll i = 1; ; i++) {
        pw[i] = pw[i-1] * p;
        if(pw[i] > (ll)1e9)
            break;

        idp++;
    }

    sort(ara+1, ara+n+1);
    ll g = 1;
    forn(i, n) {
        if(i != n)
            g = (g * fastPow(p, ara[i], mod)) % mod;
    }

    forn(i, n) {
        ll now = ara[n] - ara[i];
        lst.insert(now);
        cnt[now]++;
    }

    for(auto it = lst.begin(); it != lst.end();) {
        ll elem = *it;
        ll ase = cnt[elem];
        cnt.erase(elem);

        //cout << elem << " " << ase << endl;
        for(ll i = idp; i >= 0; i--) {
            if(pw[i] <= ase) {

                ll tot = ase / pw[i];
                ase %= pw[i];
                cnt[elem + i] += tot;
                if(i != 0)
                    lst.insert(elem + i);
            }
        }
        it = lst.upper_bound(elem);
    }

    ll mn = inf;
    for(auto it = cnt.begin(); it != cnt.end(); it++) {

        if(it->first >= ara[n]) {
            g = (g * fastPow(p, ara[n], mod)) % mod;
            break;
        }
        if(it-> second > 0) {
            g = (g * fastPow(p, it->first, mod)) % mod;
            break;
        }
    }

    cout << g << endl;

    return 0;
}