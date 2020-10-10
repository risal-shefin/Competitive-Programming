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
ll ara[sz], c[sz], cnt[sz], n, k;
vector <int> ans[sz];
multiset <int> lst;

struct node {
    int c, pos;
};
const bool operator <(const node &a, const node &b) {
    if(a.c == b.c)
        return a.pos > b.pos;
    return a.c < b.c;
}
multiset <node> info;

int main()
{
    cin >> n >> k;
    for1(i, n) {
        sl(ara[i]);
        cnt[ ara[i] ]++;
        lst.insert(ara[i]);
    }
    for1(i, k) {
        sl(c[i]);
    }

    for1(i, n) {
        ll now = ara[i];
        info.insert({c[now], now});
    }

    ll now = k, ida = 0, siz = 0;
    while(!lst.empty()) {

        ll used = 0;
        now = *(--lst.end());

        while(!lst.empty()) {

            ll can = c[now] - used;

            if(can == 0) {

                auto it = info.upper_bound({c[now], 0});

                if(it == info.end())
                    break;

                now = it->pos;
            }
            else if(cnt[now] == 0) {
                auto it = lst.lower_bound(now);
                if(it == lst.begin())
                    break;

                now = *(--it);
            }

            ans[ida].pb(now);
            used++;

            lst.erase(lst.find(now));
            info.erase(info.find({c[now], now}) );
            cnt[now]--;
        }
        ida++;
    }

    cout << ida << EL;
    for0(i, ida) {
        pf("%lld", (ll)ans[i].size());

        for(int &v : ans[i]) pf(" %d", v);
        pn;
    }

    return 0;
}