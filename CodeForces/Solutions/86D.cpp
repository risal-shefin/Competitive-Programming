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

#define block 900
const ll sz = 2e5 + 10;
ll ara[sz], ans[sz], answer = 0, cnt[1000009];

struct query {
    ll l, r, i;
} qry[sz];

bool compare(const query &a, const query &b)
{
    ll tmp = a.l / block;
    if(tmp != b.l / block)
        return a.l < b.l;

    if(tmp & 1)
        return a.r < b.r;

    return a.r > b.r;
}

inline void del(ll indx)
{
    answer -= (cnt[ ara[indx] ] * cnt[ ara[indx] ]) * ara[indx];
    cnt[ ara[indx] ]--;
    answer += (cnt[ ara[indx] ] * cnt[ ara[indx] ]) * ara[indx];
}

inline void add(ll indx)
{
    answer -= (cnt[ ara[indx] ] * cnt[ ara[indx] ]) * ara[indx];
    cnt[ ara[indx] ]++;
    answer += (cnt[ ara[indx] ] * cnt[ ara[indx] ]) * ara[indx];
}
int main()
{
    ll n, q;
    scanf("%lld %lld", &n, &q);
    answer = 0;

    for(ll i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 0; i < q; i++) {
        scanf("%lld %lld", &qry[i].l, &qry[i].r);
        qry[i].l--; qry[i].r--; qry[i].i = i;
    }
    sort(qry, qry + q, compare);

    ll curl = 0, curr = 0;
    for(ll i = 0; i < q; i++) {

        while(curl < qry[i].l) {
            del(curl);
            curl++;
        }

        while(curl > qry[i].l) {
            add(curl - 1);
            curl--;
        }

        while(curr <= qry[i].r) {
            add(curr);
            curr++;
        }

        while(curr > qry[i].r + 1) {
            del(curr - 1);
            curr--;
        }

        ans[ qry[i].i ] = answer;
    }

    for(ll i = 0; i < q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}