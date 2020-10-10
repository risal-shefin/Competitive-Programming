/*
 * pre[1]%n = 1, pre[2]%n = 2, pre[3]%n = 3....pre[n-1]%n = n-1

   ((i-1)*A_i) % n = i % n
   => A_i % n = i/(i-1) % n
*/

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
#define inf (1LL << 61)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector <int> ans;

ll fastPow(ll x, ll n, ll mod)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret % mod;
}

inline ll invMod(ll x, ll mod) {
    return fastPow(x, mod-2, mod);
}

int main()
{
    ll n, ok = 1; sl(n);

    if(n == 4) {
        cout << "YES\n1\n3\n2\n4" << EL;
        return 0;
    }

    ans.pb(1);

    for(ll i = 2; i < n; i++) {

        if(__gcd(i-1, n) != 1) {
            ok = 0;
            break;
        }

        ans.pb((i * invMod(i-1, n)) % n);
    }
    if(n != 1) ans.pb(n);

    if(!ok) pf("NO\n");
    else {
        pf("YES\n");
        for(int &num : ans) pf("%d\n", num);
    }

    return 0;
}