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

const ll sz = 1e5 + 10;
ll ara[sz];

unordered_multiset <ll> pref, suf;

int main()
{
    pref.reserve(1<<15);
    pref.max_load_factor(0.25);

    suf.reserve(1<<15);
    suf.max_load_factor(0.25);

    ll sum = 0, n;
    cin >> n;

    for1(i, n) sl(ara[i]), sum += ara[i], suf.insert(ara[i]);

    if(sum & 1) {
        cout << "NO" << EL;
        return 0;
    }

    ll half = sum / 2, ok = 0, pre = 0;

    for1(i, n) {
        pre += ara[i];
        suf.erase(suf.find(ara[i]));
        pref.insert(ara[i]);

        ll need = half - pre;
        if(suf.find(need) != suf.end()) {
            ok = 1;
            break;
        }

        ll bad = pre - half;
        if(pref.find(bad) != pref.end()) {
            ok = 1;
            break;
        }
    }

    if(!ok) cout << "NO" << EL;
    else cout << "YES" << EL;

    return 0;
}