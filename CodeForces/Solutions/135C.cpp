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

const ll sz = 1e5 + 10;
char s[sz];

set <string> lst;

int main()
{
    scanf("%s", s+1);

    ll len = strlen(s+1);

    ll tot = len-2;

    ll mnMv = tot / 2, mxMv = tot / 2;
    if(tot & 1) mnMv++;

    ll o = 0, z = 0, q = 0;

    for1(i, len) {
        o += (s[i] == '1');
        z += (s[i] == '0');
        q += (s[i] == '?');
    }

    ll mxO = o + q, mxZ = z + q;

    if(mnMv <= mxO-2) lst.insert("11");
    if(mnMv >= o) lst.insert("00");

    if(mnMv >= o-1 && mnMv <= mxO-1) {

        ll oq = mnMv+1 - o, zq = q - oq, totZ = z + zq;

        if(s[len] == '0') lst.insert("10");
        else if(s[len] == '1' && totZ != 0) lst.insert("01");
        else {

            if(oq < q) lst.insert("10");
            if(oq != 0 && totZ != 0) lst.insert("01");
        }
    }

    for(const string &s: lst) cout << s << EL;

    return 0;
}