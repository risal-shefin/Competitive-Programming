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

const ll sz = 1e5 + 10, lim = 40, root = 0;
ll ara[sz], preXor[sz];

int trie[sz*(lim+2)][2], node;

void add(ll num)
{
    int cur = root;
    for(int i = 40; i >= 0; i--) {
        bool bit = (num>>i) & 1;

        if(trie[cur][bit] == -1)
            trie[cur][bit] = ++node;

        cur = trie[cur][bit];
    }
}

ll calc(ll num)
{
    int cur = root;
    ll ret = 0;

    for(int i = 40; i >= 0; i--) {
        bool bit = (num>>i) & 1;

        if(trie[cur][bit^1] != -1) {

            ret = (ret<<1) | 1;
            cur = trie[cur][bit^1];
        }
        else {
            ret <<= 1;
            cur = trie[cur][bit];
        }
    }

    return ret;
}

int main()
{
    ms(trie, -1);

    ll n, ans = 0, suf = 0;
    cin >> n;

    for1(i, n) sl(ara[i]), preXor[i] = preXor[i-1] ^ ara[i];

    rep1(i, n) {
        ans = max(ans, preXor[i]);

        if(i != n) ans = max(ans, calc(preXor[i]));

        suf ^= ara[i];
        add(suf);
        ans = max(ans, suf);
    }

    cout << ans << EL;

    return 0;
}