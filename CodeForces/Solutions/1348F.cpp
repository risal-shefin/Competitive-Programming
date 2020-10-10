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

const ll sz = 2e5 + 10;

struct info {
    ll en, id;
};
bool operator <(const info &a, const info &b) {
    if(a.en == b.en)
        return a.id < b.id;
    return a.en < b.en;
}

vector <info> lst[sz];
set <info> endList;

ll ans1[sz], ans2[sz];

int main()
{
    ll n;
    cin >> n;

    for1(i, n) {
        ll b, e;
        sl(b), sl(e);

        lst[b].pb({e, i});
    }

    for1(i, n) {
        for(info &u : lst[i]) endList.insert(u);

        auto it = endList.begin();
        ans1[it->id] = ans2[it->id] = i;

        endList.erase(it);
    }

    bool multi = false;
    endList.clear();
    for1(i, n) {
        for(info &u : lst[i]) endList.insert(u);

        if(endList.size() > 1) {
            auto it = endList.begin();
            ++it;

            ll nxt = it->id;
            info inThisPos = *endList.begin();

            if(ans2[nxt] <= inThisPos.en) {
                ans2[inThisPos.id] = ans2[nxt];
                ans2[nxt] = i;

                multi = true;
                break;
            }
        }

        endList.erase(endList.begin());
    }

    if(!multi) {
        pf("YES\n");
        for1(i, n) {
            if(i != 1) pf(" ");
            pf("%lld", ans1[i]);
        }
        pn;
    }
    else {
        pf("NO\n");
        for1(i, n) {
            if(i != 1) pf(" ");
            pf("%lld", ans1[i]);
        }
        pn;
        for1(i, n) {
            if(i != 1) pf(" ");
            pf("%lld", ans2[i]);
        }
        pn;
    }

    return 0;
}